
//! Initialize the Intel Realsense Camera  Object
realIntelCam::realIntelCam(){
        rs2::pipeline pipeline;
        rs2::config configure;
        rs2::pipeline_profile profile;
        
        // Enable accelerator and gyroscope stream
        configure.enable_stream(RS2_STREAM_ACCEL);
        configure.enable_stream(RS2_STREAM_GYRO);
        
        // the acceleration in 3D previous: 0->x, 1->y, 2->z current 3->x, 4->y, 5->z 
        acceleration[6]{};
        // average velocity aka speed
        velocity[3]{};
        
        camera_location[3]{};
        camera_angle[3]{};
}

//! Infinite loop, must fork the process to update the camera position and angle.
void realIntelCam:: update_camera_position() {
    while(1){
            //get data from the camera
            rs2::frameset frames = pipeline.wait_for_frames();
           
           //extract accelerometer data
            rs2::motion_frame accelerometer_frame = frames.first_or_default(RS2_STREAM_ACCEL);

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

                acceleration[0] = accelerometer_data.x;
                acceleration[1] = accelerometer_data.y;
                acceleration[2] = accelerometer_data.z;

                }
        }
}

vector<float> realIntelCam :: get_location() {
    vector<float> location;

    for (int i = 0; i < 3; i++){
    location.pushback(camera_location[i]);
    }
    return location;
}

vector<float> realIntelCam :: get_angle() {
    vector<float> angle;

    for (int i = 0; i < 3; i++){
    angle.pushback(camera_angle[i]);
    }
    return angle;
}

