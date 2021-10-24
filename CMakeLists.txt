cmake_minimum_required(VERSION 3.17)
project(CDPSDKTest)

set(CMAKE_CXX_STANDARD 14)

set(LIBRARY_GITHUB_URL "https://github.com/Lard4/kdixson-CDPSDK.git")

add_executable(${PROJECT_NAME} main.cpp)

# to run against a local library build, you should do something like:
# krdixson@Kevins-MacBook-Pro-2:[build]$: cmake -D LOCAL_LIB_PATH=~/Desktop/CDPSDK .. && make
if (DEFINED LOCAL_LIB_PATH)
    message("Using a local version of the library at ${LOCAL_LIB_PATH}")
    # add the library
    target_link_libraries(${PROJECT_NAME} PUBLIC ${LOCAL_LIB_PATH}/lib/libCDPSDK.a)
    # grab the header files
    target_include_directories(${PROJECT_NAME} PUBLIC ${LOCAL_LIB_PATH}/include)
else ()
    message("Using the version of the library from GitHub: ${LIBRARY_GITHUB_URL}")

    # FetchContent is used to get libaries from git. used to pull third party libraries like GoogleTest and our Crypto lib.
    include(FetchContent)

    # add it to the project
    FetchContent_Declare(CDPSDK
            GIT_REPOSITORY ${LIBRARY_GITHUB_URL}
            GIT_TAG origin/main
    )
    FetchContent_MakeAvailable(CDPSDK)

    # include the header files from the source directory of the CDPSDK library to the CDPSDK library itself
    target_include_directories(CDPSDK INTERFACE ${CDPSDK_SOURCE_DIR})

    # link the CDPSDK library to our project
    target_link_libraries(${PROJECT_NAME} CDPSDK)
endif()