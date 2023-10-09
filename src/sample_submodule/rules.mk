GENERATED_OBJS := submodule.o arg.o

include submodule.general.mk

build_$(DIR):
	$(call build,submodule.cpp)
	$(call build,arg.cpp)
clean_$(DIR):
test_$(DIR):
	@echo testing the module $(DIR)!
test_sample_submodule: test_$(DIR)
