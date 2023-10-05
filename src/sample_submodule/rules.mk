GENERATED_OBJS := submodule.o arg.o

MODULE_OBJS+= $(addprefix $(OBJS_DIR)/, $(GENERATED_OBJS))
BUILD_MODULES+= build_$(DIR)
CLEAN_MODULES+= clean_$(DIR)

build_$(DIR):
	$(CXX) -I $(INCLUDE_DIRS) -c $(DIR)/submodule.cpp -o $(OBJS_DIR)/submodule.o
	$(CXX) -I $(INCLUDE_DIRS) -c $(DIR)/arg.cpp -o $(OBJS_DIR)/arg.o

clean_$(DIR):

