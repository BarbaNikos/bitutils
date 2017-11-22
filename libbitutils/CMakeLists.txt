set(libbitutils_SOURCES 
    include/bitutils.h 
    src/bitutils.cc
)

#set(CMAKE_CXX_FLAGS 
#    "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(libbitutils SHARED 
    ${libbitutils_SOURCES})

target_include_directories(libbitutils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
