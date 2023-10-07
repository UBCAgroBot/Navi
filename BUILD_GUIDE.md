# Navi Building Guide

### Dependencies
- `make` (GNU make) - required to manage the method of building the project
- `doxygen` (Doxygen) - generates documentation from comments in source files
- `g++` - GNU project C and C++ compiler
- `ld` - GNU linker. used alongside `g++` to compile the binary from the project sources.

### Build Commands
In a linux shell, the following rules have been provided via the build system:
- `make`/`make default`: build the `navi` binary. 
- `make doc`: use doxygen to generate documentation from the source files.
- `make test_ALL`: test every submodule included in the project.
- `make clean`: remove build files and return the repository to its original state.

### Build Guide
1. Put module sources in `src/my_submodule_name/`. (Name the folder appropriately.)
2. Put module header files (`*.hpp`, `*.h`) in the `include/` directory.
3. Copy an example `rules.mk` into your submodule.
4. Replace the object file names in `rules.mk` with your object files, and the source file names with your source files.
5. In `Makefile`, include the following lines with the other submodules:
```make
DIR := $(SRC_DIR)/sample_submodule
include $(DIR)/rules.mk
```
6. profit.