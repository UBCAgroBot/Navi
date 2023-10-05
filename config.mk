TARGET_FOLDER := build
INCLUDE_DIRS := $(ROOT_DIR)/include
SRC_DIR := $(ROOT_DIR)/src

BUILD_DIR := $(ROOT_DIR)/build
OBJS_DIR := $(BUILD_DIR)/objs

CXX := g++
CXXFLAGS :=

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
MODULES := $(wildcard $(SRC_DIR)/*/)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

OUTPUT_BINARY := $(ROOT_DIR)/navi

CLEAN_MODULES :=
BUILD_MODULES := 