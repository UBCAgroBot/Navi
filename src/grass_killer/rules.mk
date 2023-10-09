GENERATED_OBJS := grass_killer.o
include submodule.general.mk

build_$(DIR):
	$(call build,grass_killer.cpp)
clean_$(DIR):
test_$(DIR):
	@echo testing the grass killer!!
test_grass_killer: test_$(DIR)
