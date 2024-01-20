#include <librealsense2/rs.hpp>
#include <iostream>
#include <exception>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <thread>


const float GRAVITY = 9.81; // Standard gravity (m/s^2)
const float TIME_INTERVAL = 0.01; // Time interval in seconds
const double RAD_TO_DEG = 180.0 / M_PI; 

int main() {
    std:: cout << "Ready to Execute" << std::endl;
    try {
        rs2::pipeline pipeline;
        rs2::config configure;
        rs2::pipeline_profile profile;
        
        // Enable accelerator and gyroscope stream
        configure.enable_stream(RS2_STREAM_ACCEL);
        configure.enable_stream(RS2_STREAM_GYRO);
        
        // the acceleration in 3D previous: 0->x, 1->y, 2->z current 3->x, 4->y, 5->z 
        float acceleration[6]{};
        // average velocity aka speed
        float velocity[3]{};
        float camera_location[3]{};
        float gyro_angle[3]{};
        float camera_angle[3]{};

        // Start the pipeline and configure it
        profile = pipeline.start(configure);
        std::cout << "ready to start" << std::endl;

        while(1){
            //get data from the camera
            rs2::frameset frames = pipeline.wait_for_frames();
           
           //extract accelerometer data
            rs2::motion_frame accelerometer_frame = frames.first_or_default(RS2_STREAM_ACCEL);

            rs2::motion_frame gyro_frame = frames.first_or_default(RS2_STREAM_GYRO);

            if (accelerometer_frame){

                rs2_vector accelerometer_data = accelerometer_frame.get_motion_data();
                
                acceleration[3] = accelerometer_data.x;
                acceleration[4] = accelerometer_data.y;
                acceleration[5] = accelerometer_data.z;

                for (int i = 0; i < 3; i++){
                    velocity[i] = (acceleration[i] + acceleration[i+3]) / 2 * TIME_INTERVAL;
                }

                for (int i = 0; i < 3; i++){
                    camera_location[i] += velocity[i] * TIME_INTERVAL;
                }

                std::cout << "Camera Location: X = " << camera_location[0] << " Y = " << camera_location[1] << " Z = " << camera_location[2] << std::endl;

                }

                if(gyro_frame){
                    rs2_vector gyro_data = gyro_frame.get_motion_data();
                    gyro_angle[0] = gyro_data.x;
                    gyro_angle[1] = gyro_data.y;
                    gyro_angle[2] = gyro_data.z;

                    for(int i = 0; i < 3; i++){
                        camera_angle[i] +=  gyro_angle[i] * TIME_INTERVAL * RAD_TO_DEG;
                    }
                    std::cout << "Camera Angle: X = " << camera_angle[0] << " Y = " << camera_angle[1] << " Z = " << camera_angle[2] << std::endl;
                }
        }
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    return 0;
}