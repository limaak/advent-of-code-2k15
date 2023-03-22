add_library (md5_lib SHARED md5.cpp md5.h)

target_include_directories(md5_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
