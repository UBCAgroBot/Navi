GENERATED_OBJS := webcamint.o websocketint.o

include submodule.general.mk

build_$(DIR):
	$(call build,webcamint.cpp)
	$(call build,websocketint.cpp)
clean_$(DIR):
test_$(DIR):
	@echo testing the module $(DIR)!
test_webcam_interface: test_$(DIR)
