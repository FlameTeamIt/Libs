# control Makefile
include Makefile.config


all   : .mkdirs .libs .tests
	@echo $@ : $^

tests : .mkdirs .libs .tests
	@echo $@ : $^

libs  : .mkdirs .libs
	@echo $@ : $^

clean :
	@echo $@
	rm -rf $(BUILD_PATH)

.PHONY : clean

# --------------------------------------------------

.mkdirs :
	@echo $@
	mkdir -p $(ALL_PATHS)

# --------------------------------------------------

.libs : .mkdirs
	@echo $@ : $^

.compile_libs : .libs
	@echo $@ : $^
	make -f $(MAKE_LIBS) BUILD_PATH=$(BUILD_PATH)

# --------------------------------------------------

.tests: .mkdirs
	@echo $@ : $^
	
.compile_tests : .mkdirs
	@echo $@ : $^
	make -f $(MAKE_TESTS) BUILD_PATH=$(BUILD_PATH)
