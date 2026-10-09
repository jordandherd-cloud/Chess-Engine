cmake_minimum_required(VERSION 3.28)
project(ChessEngine LANGUAGES CXX)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    SYSTEM)
set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)
FetchContent_MakeAvailable(SFML)

add_executable(ChessEngine src/main.cpp)
target_link_libraries(ChessEngine PRIVATE SFML::Graphics)
