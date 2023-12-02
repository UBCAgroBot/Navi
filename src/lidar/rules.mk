GENERATED_OBJS := lidar.o
include submodule.general.mk

LD_LIBS += -lstdc++ -lpthread -lm

build_$(DIR):
	$(call build,lidar.cpp)
clean_$(DIR):
test_$(DIR):
	@echo testing the lidar!!
test_lidar: test_$(DIR)


