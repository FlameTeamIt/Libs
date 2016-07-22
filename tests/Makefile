ifeq ($(CONFIG_FILE),)
     override CONFIG_FILE :=../Makefile.config
endif
include $(CONFIG_FILE)

ifeq ($(SOURCE_PATH),)
    SOURCE_PATH := $(LOCAL_PATH)
endif
ifeq ($(INCLUDE_PATH),)
    INCLUDE_PATH := $(LOCAL_PATH)/../src
endif

SOURCES := $(shell find $(SOURCE_PATH) -name *.cpp | grep -v Tests)

DEPENDS := $(subst $(SOURCE_PATH),$(DEP_PATH),$(SOURCES:.cpp=_test.d))
OBJECTS := $(subst $(SOURCE_PATH),$(OBJ_PATH),$(SOURCES:.cpp=_test.o))

TARGETS_BIN := $(subst $(OBJ_PATH)/,$(TEST_PATH)/,$(OBJECTS:.o=))

all : .mkdirs .compile .link

clean :
	rm -rf $(ALL_PATHS)

.PHONY : all clean

# --------------------------------------------------

.mkdirs : $(ALL_PATHS)
$(ALL_PATHS) :
	mkdir -p $@

# --------------------------------------------------

.compile : $(OBJECTS)
$(OBJECTS) : $(ALL_PATHS)
$(OBJ_PATH)/%_test.o : $(SOURCE_PATH)/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CXX_FLAGS) -I$(INCLUDE_PATH) -c $< -o $@

# --------------------------------------------------

.link : $(TARGETS_BIN)
$(TARGETS_BIN) : $(OBJECTS)
$(TEST_PATH)/% : $(OBJ_PATH)/%.o
	@mkdir -p $(shell dirname $@)
	$(CC) $(CXX_FLAGS) -I$(INCLUDE_PATH) $< -o $@