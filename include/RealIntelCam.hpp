#ifndef INTELCAM_H
#define INTELCAM_H

#include <librealsense2/rs.hpp>
#include <iostream>
#include <vector>
#include <cmath>

const float TIME_INTERVAL = 0.01; // Time interval in seconds
const double RAD_TO_DEG = 180.0 / M_PI; 


using namespace std

class realIntelCam
{
    public:

    RealIntelCam();

    void update_camera_position(); 

    vector<float> get_location();

    vector<float> get_angle();

    private:
    //Essential to initiate connection
    rs2::pipeline pipeline;
    rs2::config configure;
    rs2::pipeline_profile profile;
    // the acceleration in 3D previous: 0->x, 1->y, 2->z current 3->x, 4->y, 5->z 
    float acceleration[]{};
    // average velocity aka speed
    float velocity[]{};
    // calculated location
    float camera_location[];
    //calculated angle
    float camera_angle[];
}

#endif