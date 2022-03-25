
CompressOptions :: u16 {
    DISABLED = 0;
    SHARED_COMPRESSOR = 1;
    SHARED_DECOMPRESSOR = 1 << 8;
    DEDICATED_DECOMPRESSOR_32KB = 15 << 8;
    DEDICATED_DECOMPRESSOR_16KB = 14 << 8;
    DEDICATED_DECOMPRESSOR_8KB = 13 << 8;
    DEDICATED_DECOMPRESSOR_4KB = 12 << 8;
    DEDICATED_DECOMPRESSOR_2KB = 11 << 8;
    DEDICATED_DECOMPRESSOR_1KB = 10 << 8;
    DEDICATED_DECOMPRESSOR_512B = 9 << 8;
    DEDICATED_DECOMPRESSOR = 15 << 8;
    DEDICATED_COMPRESSOR_3KB = 9 << 4 | 1;
    DEDICATED_COMPRESSOR_4KB = 9 << 4 | 2;
    DEDICATED_COMPRESSOR_8KB = 10 << 4 | 3;
    DEDICATED_COMPRESSOR_16KB = 11 << 4 | 4;
    DEDICATED_COMPRESSOR_32KB = 12 << 4 | 5;
    DEDICATED_COMPRESSOR_64KB = 13 << 4 | 6;
    DEDICATED_COMPRESSOR_128KB = 14 << 4 | 7;
    DEDICATED_COMPRESSOR_256KB = 15 << 4 | 8;
    DEDICATED_COMPRESSOR = 15 << 4 | 8;
}

SocketConfig :: struct {
    compression: CompressOptions = .DISABLED;
    maxPayloadLength: u32 = 16 * 1024 * 1024;
    idleTimeout: u16 = 120;
    maxBackpressure: u32 = 16 * 1024 * 1024;
    closeOnBackpressureLimit: bool = false;
    resetIdleTimeoutOnSend: bool = true;
    sendPingsAutomatically: bool = true;
};

call :: () -> void #foreign uwebsockets;

#scope_file

uwebsockets :: #foreign_library "bin/win/uwebsockets";