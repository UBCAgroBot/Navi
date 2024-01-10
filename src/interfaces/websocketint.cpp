#include <iostream>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <thread>
#include <opencv2/opencv.hpp>
#include "../../include/interfaces.hpp"

namespace interfaces {

    typedef websocketpp::server<websocketpp::config::asio> server;

    void handle_connection(websocketpp::connection_hdl hdl, server& s, cv::Mat* frame) {
        try {
            while (true) {
                // Check if frame is empty
                if (!(*frame).empty()) {
                    // Convert OpenCV frame to byte vector
                    std::vector<uchar> buffer;
                    cv::imencode(".jpg", *frame, buffer);

                    // Send the frame as a binary message via WebSocket
                    s.send(hdl, buffer.data(), buffer.size(), websocketpp::frame::opcode::binary);
                }
                else {
                    std::cerr << "Couldn't capture frame from webcam." << std::endl;
                    break;
                }
            }
        } catch (websocketpp::exception const & e) {
            std::cout << "Caught websocket exception: " << e.what() << std::endl;
        }
    }

    int start_websocket(cv::Mat* frame) {
        // Create a WebSocket server
        server s;

        // Clear all access log channels to prevent frames being logged
        // If frames are logged, then it makes the WebSocket server very slow
        s.clear_access_channels(websocketpp::log::alevel::all);

        // Define WebSocket server connection handler
        s.set_open_handler([&s, frame](websocketpp::connection_hdl hdl) {
            std::thread video_thread(handle_connection, hdl, std::ref(s), frame);
            video_thread.detach();
        });

        // Listen on port 6969
        s.init_asio();
        s.listen(6969);
        s.start_accept();
        s.run();

        std::cout << "WEBSOCKETINT: Successfully started the websocket." << std::endl;
        return 0;
    }
}
