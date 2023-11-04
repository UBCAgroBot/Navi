#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <opencv2/opencv.hpp>
#include <thread>

using namespace std;
using namespace cv;

typedef websocketpp::server<websocketpp::config::asio> server;

void handle_connection(websocketpp::connection_hdl hdl, server& s, VideoCapture& cap) {
    while (true) {
        // Read frame from webcam
        Mat frame;
        cap >> frame;

        // Check if frame is empty
        if (!frame.empty()) {
            // Convert OpenCV frame to byte vector
            vector<uchar> buffer;
            imencode(".jpg", frame, buffer);

            // Send the frame as a binary message via WebSocket
            s.send(hdl, buffer.data(), buffer.size(), websocketpp::frame::opcode::binary);
        }
        else {
            cerr << "Couldn't capture frame from webcam." << endl;
            break;
        }
    }
}

int webcam() {
    // Create a WebSocket server
    server s;

    // Clear all access log channels to prevent frames being logged
    // If frames are logged, then it makes the WebSocket server very slow
    s.clear_access_channels(websocketpp::log::alevel::all);

    // Initialize OpenCV webcam
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Couldn't open the webcam." << endl;
        return -1;
    }

    // Define WebSocket server connection handler
    s.set_open_handler([&s, &cap](websocketpp::connection_hdl hdl) {
        thread video_thread(handle_connection, hdl, ref(s), ref(cap));
        video_thread.detach();
    });

    // Listen on port 6969
    s.init_asio();
    s.listen(6969);
    s.start_accept();
    s.run();

    return 0;
}
