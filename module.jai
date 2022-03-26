uws_app_t :: struct {
    
}

us_socket_context_options_t :: struct {
    key_file_name: *u8;
    cert_file_name: *u8;
    passphrase: *u8;
    dh_params_file_name: *u8;
    ssl_prefer_low_memory_usage: s32;
};

uws_create_app :: (ssl: s32, options: us_socket_context_options_t) -> *uws_app_t #foreign uwebsockets;
uws_app_run :: (ssl: s32, app: *uws_app_t) -> void #foreign uwebsockets;

#scope_file

#if OS == .WINDOWS {
  uwebsockets :: #foreign_library "bin/win/uwebsockets";
} else #if OS == .LINUX {
  uwebsockets :: #foreign_library "bin/linux/libuwebsockets";
}