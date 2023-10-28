GENERATED_OBJS := measure.o

include submodule.general.mk

build_$(DIR):
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIRS) $(ROOT_DIR)/IntelRealSenseSDK/lib/x64/realsense2.lib -c $(DIR)/measure.cpp -o $(OBJS_DIR)/measure.o
clean_$(DIR):
test_$(DIR):
	@echo testing the module $(DIR)!
test_sample_submodule: test_$(DIR)