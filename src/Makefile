ifeq ($(CONFIG_FILE),)
     override CONFIG_FILE :=../Makefile.config
endif
include $(CONFIG_FILE)

ifeq ($(SOURCE_PATH),)
    SOURCE_PATH := .
endif
SOURCES := $(subst ./,,$(subst src/,,$(shell find $(SOURCE_PATH) -name *.cpp | grep -v Tests | grep -v tests)))
DEPENDS := $(addprefix $(DEP_PATH)/,$(SOURCES:.cpp=.d))
# 
# .compile .link
all : .mkdirs .dependences
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
	@echo MAKEFLAGS = $(MAKEFLAGS)
	@echo CONFIG_FILE = $(CONFIG_FILE)
	mkdir -p $(ALL_PATHS)
	@echo DEPENDS = $(DEPENDS)
	@echo
# 
# 
# # --------------------------------------------------
# 
.dependences : .mkdirs .make_depends
.make_depends : $(DEPENDS)
$(DEP_PATH)/%.d : $(SOURCE_PATH)/%.cpp
	mkdir -p $(shell dirname $@)
	$(CC) $(CXX_FLAGS) -I$(SOURCE_PATH) -MM -c $< > $@

include $(wildcard $(DEP_PATH)/*.d)
# 
# # --------------------------------------------------
# 
# .compile : .mkdirs .make_depends
# 	
# 
# # --------------------------------------------------
# 
# .link: .mkdirs
# 	
