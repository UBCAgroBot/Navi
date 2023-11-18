#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <thread>

using namespace std;
using namespace cv;

// Alias for websocketpp server
typedef websocketpp::server<websocketpp::config::asio> server;

/*!
 * Handles the connection to the WebSocket server.
 * Captures frames from the webcam, encodes them,
 * and sends them via the WebSocket connection.
 *
 * \param hdl The connection handle.
 * \param s The WebSocket server.
 * \param cap The OpenCV VideoCapture object.
 */
void handle_connection(websocketpp::connection_hdl hdl, server& s, Mat *frame) {
    while (true) {
        try {
            if (!frame->empty()) {
                // Convert OpenCV frame to byte vector
                vector<uchar> buffer;
                imencode(".jpg", *frame, buffer);
                s.send(hdl, buffer.data(), buffer.size(), websocketpp::frame::opcode::binary);
            }
            else {
                cerr << "Couldn't capture frame from webcam." << endl;
                break;
            }
        } catch (websocketpp::exception const & e) {
        cout << "Caught websocket exception: " << e.what() << endl;
        }
    }
}

/*!
 * Initializes and runs the WebSocket server, capturing frames
 * from the webcam and sending them via open WebSocket connections.
 *
 * Clears all access log channels, initializes the OpenCV webcam,
 * defines the WebSocket server connection handler, listens on port 6969,
 * and finally starts the accept loop and the ASIO io_service event loop.
 *
 * \return 0 if the server ran successfully, otherwise -1.
 */
int web(Mat *frame) {
    // Create a WebSocket server
    server s;
    // Clear all access log channels to prevent frames being logged
    // If frames are logged, then it makes the WebSocket server very slow
    s.clear_access_channels(websocketpp::log::alevel::all);

     s.set_open_handler([&s,frame](websocketpp::connection_hdl hdl) {
        thread video_thread(handle_connection, hdl, ref(s), ref(frame));
        video_thread.detach();
    });

    // Listen on port 6969
    s.init_asio();
    s.listen(6969);
    s.start_accept();
    s.run();

    return 0;
}

