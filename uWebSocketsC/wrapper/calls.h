#include <cstdint>

struct Server {

};

struct SocketConfig {
    uint16_t compression;
    uint32_t maxPayloadLength;
    uint16_t idleTimeout;
    uint32_t maxBackpressure;
    bool closeOnBackpressureLimit;
    bool resetIdleTimeoutOnSend;
    bool sendPingsAutomatically;
};

EXPORT void call();

EXPORT void* create_server(int port, SocketConfig config);