GENERATED_OBJS := submodule.o arg.o

include submodule.general.mk

build_$(DIR): build_generic_arg.cpp build_generic_submodule.cpp
clean_$(DIR):
test_$(DIR):
	@echo testing the module $(DIR)!
test_sample_submodule: test_$(DIR)
