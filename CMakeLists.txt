cmake_minimum_required(VERSION 3.0.0)
project(thinWalls VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

add_executable(
    ${PROJECT_NAME}

        main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
