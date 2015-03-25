Name := FlameIDE

override CC := g++-4.8

ifdef BUILD
override TypeBuild := $(BUILD)
else
override TypeBuild := Release
endif

BuildPath := $(TypeBuild)

DepPath := $(BuildPath)/dep
ObjPath := $(BuildPath)/obj
BinPath := $(BuildPath)/bin

Dirs := $(DepPath) $(ObjPath) $(BinPath) $(TypeBuild)

override Libs := 

override Warn_flags :=
# override Warn_flags := \
# 			-Wall \
# 			-Wextra \
# 			-Wconversion \
# 			-Werror \
# 			-Winit-self \
# 			-Wunreachable-code \
# 			-Wformat=2 \
# 			-Wswitch-default \
# 			-Wtrigraphs \
# 			-Wstrict-overflow=4 \
# 			-Wfloat-equal \
# 			-Wundef \
# 			-Wshadow \
# 			-Wcast-qual \
# 			-Wcast-align \
# 			-Wwrite-strings \
# 			-Wlogical-op
			
Defines := 

override Flags_Debug := -g -O0 $(Warn_flags)
override Flags_Release := -O2

ifeq ($(TypeBuild),Release)
override Flags := -std=c++11 -pipe $(Defines) $(Flags_Release)
endif

ifeq ($(TypeBuild),Debug)
override Flags := -std=c++11 -pipe $(Defines) $(Flags_Debug)
endif


#Flag_Obj := -fPIC

#Flag_Lib := -shared

Path := ./src

# список всех ресурсных файлов
Sources := \
	$(subst ./,,$(shell find $(Path) -name *.cpp | grep -v Tests/ | grep -v Others/ ))

# файлы для модульного тестирования
Sources_Test := \
	$(subst ./,,$(shell find $(Path) -name *.cpp | grep Tests/ ))

Objects := \
	$(addprefix $(ObjPath)/,$(subst /,_,$(Sources:.cpp=.o)))
	
# получаем имена объектных файлов
Dependences := \
	$(addprefix $(DepPath)/,$(subst /,_,$(Sources:.cpp=.d)))


Path_ALL := \
	$(shell find $(Path) -type d)

#--------------------
all: .mkdirs .depends .compile #.link
#--------------------
.mkdirs:
	@mkdir -p $(Dirs)
#--------------------
#
# Для описания зависимостей от заголовков
#
.depends: .mkdirs $(Dependences)

# честно говоря, такой вариант не очень нравится. Надо думать.
$(DepPath)/%.d :  
	$(CC) $(Flags) $(Libs) -MM -c $(subst _,/,$(notdir $(subst .d,.cpp,$@))) > $@
include $(wildcard $(DepPath)/*.d)
#--------------------	
#
# Для компиляции объектных файлов
#
.compile : .depends $(Objects)

# $(Objects): obj/%.o : %.cpp # старый вариант; оставил для понимания происходящего
$(ObjPath)/%.o : 
	$(CC) $(Flags) $(Flag_Obj) $(Libs) -c $(subst _,/,$(notdir $(subst .o,.cpp,$@))) -o $@

#--------------------	
#
# Для сборки статичной и динамической библиотек
#
.link: .link_libs .link_test

.link_libs: \
	./lib/$(Target_lib)
# 	./lib/$(Target_lib_static)

# видно с коммандной строки
./lib/$(Target_lib): $(Objects)
	$(CC) $(Flag_Lib) $(Flags) $(Libs) $(Objects) -o lib/$(Target_lib)

# видно с коммандной строки
# ./lib/$(Target_lib_static): $(Objects)
# 	@ar rv lib/$(Target_lib_static) $(Objects)

.link_test: .compile ./bin/$(Target_bin)

# видно с коммандной строки
./bin/$(Target_bin): .compile .link_libs
	cd bin; $(CC) $(Flags) $(Defines) ../lib/$(Target_lib) ../$(Sources_Tests) -o $(Target_bin)
	
#--------------------	
exec:
	@cd ./bin; ./$(Target_bin)
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
.debianize:
#--------------------
.PHONY: clean
	
clean:
	@rm -rf $(Dirs)
#--------------------
