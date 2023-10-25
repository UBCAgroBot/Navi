# Navi Building Guide

### Dependencies
- `make` (GNU make) - required to manage the method of building the project
- `doxygen` (Doxygen) - generates documentation from comments in source files
- `g++` - GNU project C and C++ compiler
- `ld` - GNU linker. used alongside `g++` to compile the binary from the project sources.

additional dependencies include:
- `librealsense2` \[v.2.54.2\] - to drive the distance sensing camera

### Build Commands
In a linux shell, the following rules have been provided via the build system:
- `make`/`make default`: build the `navi` binary. 
- `make doc`: use doxygen to generate documentation from the source files.
- `make test_ALL`: test every submodule included in the project.
- `make clean`: remove build files and return the repository to its original state.

### Create a New Submodule
1. Put module sources in `src/my_submodule_name/`. (Name the folder appropriately.)
2. Put module header files (`*.hpp`, `*.h`) in the `include/` directory.
3. Copy an example `rules.mk` into your submodule.
4. Replace the object file names in `rules.mk` with your object files, and the source file names with your source files.
  - (Please refer to [the guide to rules.mk](#A-Guide-to-Rules.mk))
5. In `Makefile`, include the following lines with the other submodules:
```make
DIR := $(SRC_DIR)/sample_submodule
include $(DIR)/rules.mk
```
6. profit.

### Documentation Notes
One-line summaries of functions should be prefixed by `//!`.

Multi-line detailed descriptions of functions should be surrounded by `/*!` and `*/`. 

Refer to the example submodules for an example.

### A Guide to Rules.mk
Each submodule has one `rules.mk` file, which must define the following rules for the following purposes:
`build_$(DIR):`: used to build the submodule.
`clean_$(DIR):`: used to clean any artifacts that the submodule makes.
`test_$(DIR):`: used to test the submodule.

Particularly observant readers may notice the special syntax `$(DIR)` embedded within the rules. Yet more astute readers may connect this to step 5 in the section [Create a New Submodule](#Create-a-New-Submodule):
```make
DIR := $(SRC_DIR)/sample_submodule
```
This syntax means that, for example, if your submodule lives at `/home/zelda/projects/Navi/src/fairy-fountain`, then the three commands to build, clean, and test the submodule become:
- `make build_/home/zelda/projects/Navi/src/fairy-fountain`
- `make clean_/home/zelda/projects/Navi/src/fairy-fountain`
- `make test_/home/zelda/projects/Navi/src/fairy-fountain`

respectively. obviously, this is quite painful to write. Thus, it may be useful to **alias** rules by defining new rules like this:
```make
build_fairy_fountain: build_$(DIR)
clean_fairy_fountain: clean_$(DIR)
test_fairy_fountain: test_$(DIR)
```

This way, to build the fairy fountain submodule, you could run
```sh
make build_fairy_fountain
```
which would call the internal command `make build_$(DIR)` and build your submodule.
