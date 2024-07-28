GENERATED_OBJS := RealIntelCam.o

include submodule.general.mk

build_$(DIR):
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIRS) -c $(DIR)/RealIntelCam.cpp -o $(OBJS_DIR)/RealIntelCam.o
clean_$(DIR):
	rm imu_interface_test_binary
test_$(DIR):
	@echo testing the module $(DIR)!
build_imu_interface_test_binary:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIRS) $(DIR)/measure.cpp -o imu_interface_test_binary -lrealsense2