file(GLOB SRCS *.cc)

set(testlibbitutils_SOURCES
  bitutilstest.cc
  main.cc
)

ADD_EXECUTABLE(testlibbitutils 
    ${testlibbitutils_SOURCES})

TARGET_LINK_LIBRARIES(testlibbitutils
    libbitutils
    libgtest
)

add_test( NAME testlibbitutils
    COMMAND testlibbitutils)
