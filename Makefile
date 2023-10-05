# .SILENT:default

.DEFAULT_GOAL := default

ROOT_DIR := $(shell pwd)
MODULE_OBJS :=

# top level definitions
include config.mk

# example: include a folder
DIR := $(SRC_DIR)/sample_submodule
include $(DIR)/rules.mk

mkobjdir:
	mkdir -p $(OBJS_DIR)

mkbuilddir:
	mkdir -p $(BUILD_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIRS) -o $(OBJS_DIR)/$*.o -c $(SRC_DIR)/$*.cpp

$(OUTPUT_BINARY): $(SRCS) $(BUILD_MODULES)
	@echo "[[[[   BUILDING BINARY   ]]]]"
	$(CXX) $(OBJS) $(MODULE_OBJS) -o $(OUTPUT_BINARY)

default: mkobjdir mkbuilddir $(OBJS) $(MODULES) $(OUTPUT_BINARY)

clean: $(CLEAN_MODULES)
	rm -rf $(BUILD_DIR) $(OUTPUT_BINARY)

.PHONY: mkobjdir mkbuilddir $(OBJECTS) $(MODULES) $(BUILD_MODULES) $(CLEAN_MODULES) binary $(SRC_DIR)/%.cpp