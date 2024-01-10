GENERATED_OBJS := webcamPlantDetection.o

include submodule.general.mk

build_$(DIR):
	$(call build,webcamPlantDetection.cpp)
clean_$(DIR):
test_$(DIR):
	@echo testing the module $(DIR)!
