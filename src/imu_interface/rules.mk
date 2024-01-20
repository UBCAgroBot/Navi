GENERATED_OBJS := RealIntelCam.o

include submodule.general.mk

build_$(DIR):
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIRS) -c $(DIR)/RealIntelCam.cpp -o $(OBJS_DIR)/RealIntelCam.o
clean_$(DIR):
test_$(DIR):
	@echo testing the module $(DIR)!
test_sample_submodule: test_$(DIR)