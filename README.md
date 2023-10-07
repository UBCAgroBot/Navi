# Navi
Agrobot Navi is a robot navigation and control system consisting software and hardware.

### Dependencies
- `make` (GNU make) - required to manage the method of building the project
- `doxygen` (Doxygen) - generates documentation from comments in source files
- `g++` - GNU project C and C++ compiler
- `ld` - GNU linker. used alongside `g++` to compile the binary from the project sources.

### Build Commands
In a linux shell, the following rules have been provided via the build system:
`make`/`make default`: build the `navi` binary. 
`make doc`: use doxygen to generate documentation from the source files.
`make test_ALL`: test every submodule included in the project.
`make clean`: remove build files and return the repository to its original state.
