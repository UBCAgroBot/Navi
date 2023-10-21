TARGET_FOLDER := build
INCLUDE_DIRS := $(ROOT_DIR)/include
SRC_DIR := $(ROOT_DIR)/src

BUILD_DIR := $(ROOT_DIR)/build
OBJS_DIR := $(BUILD_DIR)/objs

CXX := g++
CXXFLAGS := -std=c++20 -Wall 
LINK_TIME_FLAGS := 

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
MODULES := $(wildcard $(SRC_DIR)/*/)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

OUTPUT_BINARY := $(ROOT_DIR)/navi

CLEAN_MODULES :=
BUILD_MODULES := 
TEST_MODULES :=

DOCS_DIR := $(ROOT_DIR)/docs
DOCS_OUTPUT_DIR := $(DOCS_DIR)/doxygen_output

define build
	$(eval DRK := $(shell echo "$@" | cut -c 7-))
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS:%=-I %) -c $(DRK)/$(1) -o $(OBJS_DIR)/$(basename $(1)).o
endef