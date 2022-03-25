#include "calls.h"

#include <cstdio>

void call() {
    printf("printed\n");
}

Server* create_threaded_server(int port, SocketConfig config) {
    uWS::App* server = new uWS::App();

    struct UserData {

    };

    uWS::App::WebSocketBehavior<UserData> behavior;
    behavior.compression = (uWS::CompressOptions) config.compression;
    behavior.maxPayloadLength = config.maxPayloadLength;
    behavior.idleTimeout = config.idleTimeout;
    behavior.maxBackpressure = config.maxBackpressure;
    behavior.closeOnBackpressureLimit = config.closeOnBackpressureLimit;
    behavior.resetIdleTimeoutOnSend = config.resetIdleTimeoutOnSend;
    behavior.sendPingsAutomatically = config.sendPingsAutomatically;
    behavior.open = [](auto* ws) {
        
    };
    behavior.message = [&server](auto* ws, std::string_view message, uWS::OpCode opCode) {

    };
    behavior.drain = [](auto* ws) {

    };
    behavior.ping = [](auto* ws) {

    };
    behavior.pong = [](auto* ws) {

    };
    behavior.close = [](auto* ws, int code, std::string_view message) {

    };

    server->ws<UserData>(std::string("/*"), std::move(behavior)).listen(port, [](us_listen_socket_t* listen_socket) {
        if (listen_socket) {
            std::cout << "Thread " << std::this_thread::get_id() << " listening" << std::endl;
        } else {
            std::cout << "Thread " << std::this_thread::get_id() << " failed to listen" << std::endl;
        }
    }).run();

    // server->ws<void>("/*", {
    //     .compression = uWS::DISABLED,
    //     .maxPayloadLength = 16 * 1024 * 1024,
    //     .idleTimeout = 60,
    //     .maxBackpressure = 16 * 1024 * 1024,
    //     .closeOnBackpressureLimit = false,
    //     .resetIdleTimeoutOnSend = true,
    //     .sendPingsAutomatically = false,
    //     /* Handlers */
    //     .upgrade = nullptr,
    //     .open = [](auto *ws) {
    //         /* Open event here, you may access ws->getUserData() which points to a PerSocketData struct */

    //         PerSocketData *perSocketData = (PerSocketData *) ws->getUserData();

    //         for (int i = 0; i < 32; i++) {
    //             std::string topic = std::to_string((uintptr_t)ws) + "-" + std::to_string(i);
    //             perSocketData->topics.push_back(topic);
    //             ws->subscribe(topic);
    //         }
    //     },
    //     .message = [&app](auto *ws, std::string_view message, uWS::OpCode opCode) {
    //         PerSocketData *perSocketData = (PerSocketData *) ws->getUserData();

    //         app->publish(perSocketData->topics[(size_t)(++perSocketData->nr % 32)], message, opCode);
    //         ws->publish(perSocketData->topics[(size_t)(++perSocketData->nr % 32)], message, opCode);
    //     },
    //     .drain = [](auto */*ws*/) {
    //         /* Check ws->getBufferedAmount() here */
    //         //std::cout << "drain" << std::endl;
    //     },
    //     .ping = [](auto */*ws*/, std::string_view ) {
    //         /* Not implemented yet */
    //     },
    //     .pong = [](auto */*ws*/, std::string_view ) {
    //         /* Not implemented yet */
    //     },
    //     .close = [](auto */*ws*/, int /*code*/, std::string_view /*message*/) {
    //         /* You may access ws->getUserData() here */
    //     }
    // });
}