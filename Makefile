# .SILENT:default

.DEFAULT_GOAL := default

ROOT_DIR := $(shell pwd)
MODULE_OBJS :=

# top level definitions
include config.mk

# example: include a folder
DIR := $(SRC_DIR)/sample_submodule
include $(DIR)/rules.mk

DIR := $(SRC_DIR)/grass_killer
include $(DIR)/rules.mk

DIR := $(SRC_DIR)/webcam_interface
include $(DIR)/rules.mk

mkobjdir:
	mkdir -p $(OBJS_DIR)

mkbuilddir:
	mkdir -p $(BUILD_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS:%=-I %) -o $(OBJS_DIR)/$*.o -c $(SRC_DIR)/$*.cpp

$(OUTPUT_BINARY): $(SRCS) $(BUILD_MODULES)
	@echo "[[[[   LINKING NAVI   ]]]]"
	$(CXX) $(LINK_TIME_FLAGS) $(OBJS) $(MODULE_OBJS) $(LIBS) -o $(OUTPUT_BINARY)

debug:
	@echo $(BUILD_MODULES)

default: debug mkobjdir mkbuilddir $(OBJS) $(MODULES) $(OUTPUT_BINARY)

clean: $(CLEAN_MODULES)
	rm -rf $(BUILD_DIR) $(OUTPUT_BINARY)
	rm -rf $(DOCS_OUTPUT_DIR)

test_ALL: $(TEST_MODULES)

doc:
	mkdir -p $(DOCS_OUTPUT_DIR)
	cd $(DOCS_DIR) && doxygen $(DOCS_DIR)/doxygen-config

.PHONY: mkobjdir mkbuilddir $(MODULES) $(BUILD_MODULES) $(CLEAN_MODULES) $(TEST_MODULES) binary test_ALL