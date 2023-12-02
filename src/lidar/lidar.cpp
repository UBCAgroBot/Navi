/*
 *
 * Lidar Object Local Positions
 *
 */

#include "lidar.hpp"

struct point {
    double x;
    double y;
};

void* grab_data(ILidarDriver * lidar);

// Global Variables
sl_lidar_response_measurement_node_hq_t nodes[8192];
size_t nodeCount = sizeof(nodes)/sizeof(sl_lidar_response_measurement_node_hq_t);
point points[8192];

/*!
 * Initializes and runs the LiDAR.
 *
 * Creates a channel at /dev/ttyUSB0 at port 115200.
 *
 * \return 0 if successful, else return -1.
 */
int lidar_boot()
{
    // Create a communication channel instance
    IChannel* _channel;
    Result<IChannel*> channel = createSerialPortChannel("/dev/ttyUSB0", 115200);

    // Create a LIDAR driver instance
    ILidarDriver * lidar = *createLidarDriver();
    auto res = (lidar)->connect(*channel);

    if(SL_IS_OK(res))
    {
        sl_lidar_response_device_info_t deviceInfo;
        res = (lidar)->getDeviceInfo(deviceInfo);
        if(SL_IS_OK(res)){
            printf("Model: %d, Firmware Version: %d.%d, Hardware Version: %d\n",
            deviceInfo.model,
            deviceInfo.firmware_version >> 8, deviceInfo.firmware_version & 0xffu,
            deviceInfo.hardware_version);
        }else{
            fprintf(stderr, "Failed to get device information from LIDAR %08x\r\n", res);
        }
    } else {
        fprintf(stderr, "Failed to connect to LIDAR %08x\r\n", res);
    }

    // lidar->startMotor();
    LidarScanMode scanMode;
    lidar->startScan(false, true, 0, &scanMode); //in bootstrap

    while(1) 
    {
        void* val = grab_data(lidar);

        for (int pos = 0; pos < (int)nodeCount; ++pos) 
        {
            printf("x = %f, y = %f\n", points[pos].x, points[pos].y);
        }

    }

    return 0;
}

/*
 * Converts the data from theta and distance to x and y
 * 
 * Returns a pointer to the array containing the x and y's
 */

/*!
 * Writes the scanned data into a points array, starting from theta 0 to 360.
 *
 * \param lidar the currently connected lidar.
 * \return pointer to the array containing the data.
 */
void* grab_data(ILidarDriver * lidar) 
{
    sl_result res = lidar->grabScanDataHq(nodes, nodeCount);

    if (IS_FAIL(res)) {
        // failed to get scan data
        printf("ERROR IN SCANNING\n");
    }

    if (SL_IS_OK(res)) {
        lidar->ascendScanData(nodes, nodeCount);
        for (int pos = 0; pos < (int)nodeCount; ++pos) {
            points[pos].x = std::cos(((nodes[pos].angle_z_q14 * 90.f) / 16384.f) * (3.14 / 180)) * nodes[pos].dist_mm_q2/4.0f;
            points[pos].y = std::sin(((nodes[pos].angle_z_q14 * 90.f) / 16384.f) * (3.14 / 180)) * nodes[pos].dist_mm_q2/4.0f;
        }
    }

    return &points;
}

