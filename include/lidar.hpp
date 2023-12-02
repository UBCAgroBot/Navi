#ifndef LIDAR_HPP
#define LIDAR_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <rplidar.h>
#include <unistd.h>
#include <cmath>

#include "sl_lidar.h" 
#include "sl_lidar_driver.h"

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif

using namespace sl;

int lidar_boot(int argc, const char * argv[]);
void* grab_data(ILidarDriver * lidar);

#endif