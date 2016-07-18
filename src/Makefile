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

# 
# .link
all : .mkdirs .dependences .compile
# 
clean :
	rm -rf $(ALL_PATHS)
# 
# .PHONY : clean
# 	
# 
# # --------------------------------------------------
# 
.mkdirs :
	@mkdir -p $(ALL_PATHS)
 
# # --------------------------------------------------
 
.dependences : .mkdirs .make_depends
.make_depends : $(DEPENDS)
$(DEP_PATH)/%.d : $(SOURCE_PATH)/%.cpp
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

.link: .mkdirs
	
