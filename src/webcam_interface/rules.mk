GENERATED_OBJS := webcam_interface.o

include submodule.general.mk

build_$(DIR):
	$(call build,webcam_interface.cpp)
clean_$(DIR):
test_$(DIR):
	@echo testing the module $(DIR)!
test_webcam_interface: test_$(DIR)
