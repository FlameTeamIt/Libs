ifeq ($(CONFIG_FILE),)
     override CONFIG_FILE :=../Makefile.config
endif
include $(CONFIG_FILE)

ifeq ($(SOURCE_PATH),)
    SOURCE_PATH := .
endif

SOURCES := $(subst ./,,$(subst src/,,$(shell find $(SOURCE_PATH) -name *.cpp | grep -v Tests | grep -v tests)))

DEPENDS := $(addprefix $(DEP_PATH)/,$(SOURCES:.cpp=.d))
OBJECTS := $(addprefix $(OBJ_PATH)/,$(SOURCES:.cpp=.o))
TARGET_LIB := lib$(NAME).a

DEPENDS_SHARED := $(addprefix $(DEP_PATH)/,$(SOURCES:.cpp=_shared.d))
OBJECTS_SHARED = $(addprefix $(OBJ_PATH)/,$(SOURCES:.cpp=_shared.o))
TARGET_SHARED_LIB := lib$(NAME).so

# 
# .link
all : .mkdirs static shared

clean :
	rm -rf $(ALL_PATHS)

static : .link

shared : .link_shared

.PHONY : all clean static shared
	

# --------------------------------------------------

.mkdirs :
	@mkdir -p $(ALL_PATHS)
 
# # --------------------------------------------------
 
.dependences : .mkdirs .make_depends
.make_depends : $(DEPENDS)
$(DEP_PATH)/%.d : $(SOURCE_PATH)/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CXX_FLAGS) -I$(SOURCE_PATH) -MM -c $< > $@
$(DEP_PATH)/%_shared.d : $(SOURCE_PATH)/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CXX_FLAGS) -I$(SOURCE_PATH) -MM -c $< > $@
include $(wildcard $(DEP_PATH)/*.d)

# --------------------------------------------------

.compile : .mkdirs .make_depends .make_obj
.make_obj : $(OBJECTS)
$(OBJ_PATH)/%.o : $(SOURCE_PATH)/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CXX_FLAGS) -I$(SOURCE_PATH) -c $< -o $@

# --------------------------------------------------

.link: .compile
	$(AR) rcs $(LIB_PATH)/$(TARGET_LIB) $(OBJECTS)

# --------------------------------------------------

.dependences_shared : .mkdirs .make_depends_shared
.make_depends_shared : $(DEPENDS_SHARED)
$(DEP_PATH)/%_shared.d : $(SOURCE_PATH)/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CXX_FLAGS) -I$(SOURCE_PATH) -MM -c $< > $@
include $(wildcard $(DEP_PATH)/*_shared.d)

# --------------------------------------------------

.compile_shared : .mkdirs .make_depends .make_obj_shared
.make_obj_shared : $(OBJECTS_SHARED)
$(OBJ_PATH)/%_shared.o : $(SOURCE_PATH)/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CXX_FLAGS) -I$(SOURCE_PATH) -fpic -c $< -o $@

# --------------------------------------------------

.link_shared: .compile_shared
	$(CC) -shared -o $(LIB_PATH)/$(TARGET_SHARED_LIB) $(OBJECTS_SHARED)

# --------------------------------------------------

