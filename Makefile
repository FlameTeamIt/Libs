Name := FlameIDE

ifeq ($(CC),cc)
override CC := g++
endif

ifdef BUILD
override TypeBuild := $(BUILD)
else
override TypeBuild := Release
endif

BuildPath := $(TypeBuild)

DepPath := $(BuildPath)/dep
ObjPath := $(BuildPath)/obj
BinPath := $(BuildPath)/bin
LibPath := $(BuildPath)/lib

Dirs := $(DepPath) $(ObjPath) $(BinPath) $(LibPath) $(TypeBuild)

override Libs :=

#override Warn_flags := -Wall -Wextra #-Werror
override Warn_flags := \
			-Wall \
			-Wextra \
			-Wconversion \
			-Winit-self \
			-Wunreachable-code \
			-Wformat=2 \
			-Wswitch-default \
			-Wtrigraphs \
			-Wstrict-overflow=4 \
			-Wfloat-equal \
			-Wundef \
			-Wshadow \
			-Wcast-qual \
			-Wcast-align \
			-Wwrite-strings \
			-Wlogical-op \
			#-Werror \


Defines_Debug := -DDEBUG=1
Defines_Release :=

override Flags_Debug :=-pg -O0 -fno-inline-functions $(Warn_flags) 
override Flags_Release :=-O2 -finline-functions  $(Warn_flags) #-nostdlib -ffreestanding

ifeq ($(TypeBuild),Release)
override Defines := $(Defines_Release)
override Flags :=-std=c++11 -pipe $(Defines_Release) $(Flags_Release)
endif

ifeq ($(TypeBuild),Debug)
override Defines := $(Defines_Debug)
override Flags :=-std=c++11 -pipe $(Defines_Debug) $(Flags_Debug)
endif

Path := src/

# список всех ресурсных файлов
Sources := \
	$(subst ./,,$(shell find $(Path) -name *.cpp | grep -v Tests/ ))

# получаем имена объектных файлов
Dependences := \
	$(addprefix $(DepPath)/,$(subst $(Path),,$(Sources:.cpp=.d)))
Flag_Deps := -MM -c


# файлы для модульного тестирования
Sources_Test := \
	$(subst ./,,$(shell find $(Path) -name *.cpp | grep Tests/ ))


Objects := \
	$(addprefix $(ObjPath)/,$(subst $(Path),,$(Sources:.cpp=.o)))
	
Flag_Obj :=-fPIC
Flag_Lib :=-shared


Target_lib := $(LibPath)/lib$(Name).so
Target_lib_static := $(LibPath)/lib$(Name).a
Target_bin_test := $(BinPath)/test_$(Name)

Path_ALL := \
	$(shell find $(Path) -type d)

#--------------------
all: .mkdirs .depends .compile .link
#--------------------
.mkdirs:
	@mkdir -p $(Dirs) $(shell dirname $(Objects) $(Dependences))
	
#--------------------
.PHONY: clean
	
clean:
	@rm -rf $(Dirs)
	
#--------------------
#
# Для описания зависимостей от заголовков
#
.depends: .mkdirs .make_depends
.make_depends: $(Dependences)

# честно говоря, такой вариант не очень нравится. Надо думать.
$(Dependences): $(DepPath)/%.d : $(Path)/%.cpp
	$(CC) $(Flags) $(Flag_Deps) $(Libs) $< > $@
include $(wildcard $(DepPath)/*.d)
Define_BuildNumber :=-DBUILD_NUMBER=$(shell bash change_buildnumber && cat buildnumber | tr -d '\n')
#--------------------
#
# Для компиляции объектных файлов
#
.compile : .depends $(Objects)

# $(Objects): obj/%.o : %.cpp # старый вариант; оставил для понимания происходящего
$(Objects) : $(ObjPath)/%.o : $(Path)/%.cpp
	$(CC) $(Flags) $(Defines) $(Define_BuildNumber) $(Flag_Obj) $(Libs) -c $< -o $@

#--------------------
#
# Для сборки статичной и динамической библиотек
#
.link: .compile .link_libs .link_test

.link_libs: \
	$(Target_lib) \
# 	$(Target_lib_static)

# видно с коммандной строки
$(Target_lib): $(Objects)
	$(CC) $(Flag_Lib) $(Flags) $(Define_BuildNumber) $(Libs) $(Objects) -o $(Target_lib)

# видно с коммандной строки
$(Target_lib_static): $(Objects)
	@ar rv $(Target_lib_static) $(Objects)

.link_test: .compile $(Target_bin_test)

# видно с коммандной строки
$(Target_bin_test): .compile .link_libs
	$(CC) $(Flags) $(Defines) $(Define_BuildNumber) $(Target_lib) $(Sources_Test) -o $(Target_bin_test)
#--------------------
exec_test:
	./$(Target_bin_test)
#--------------------
#
# Для установки $(Name) как библиотеки
#
# Есть мысля заделать аналогично с компиляцией
# Разница лишь в том, что тут будет копирование
# заголовков в директорию /usr/include/$(Name)
# и динамической библиотеки в директорию /usr/lib/$(Name)
#
# install: .install_headers .install_lib
# 	
# .install_headers:
# 	
# .install_headers_mkdirs:
# 	@cd /usr/include; mkdir -p $(dir $(Headers))
# 
# 
# 	
# .install_lib:
# 	@mkdir /usr/lib/$(Name)
# 	@cp ./libs/$(Target_lib) /usr/lib/$(Name)
# 	
#--------------------
#
# Для удаления всех установленных файлов
#
# uninstall:
# 	
#--------------------
#
# Для дебианизации
#
# Это напоследок поиграться и поиздеваться над
# своими мозгами.
#
#.debianize:
