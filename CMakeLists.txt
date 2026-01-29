cmake_minimum_required(VERSION 3.22)

project(permatracks_msg)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME}
        src/Position.cpp
        src/Direction.cpp
        src/DirectionVector.cpp
        src/MagneticFluxDensityDataRawLIS3MDL.cpp
        src/MagneticFluxDensityDataRawMMC5983MA.cpp
        src/MagneticFluxDensityDataRawAK09940A.cpp
        src/MagneticFluxDensityData.cpp
        src/MagneticFluxDensityIntegerData.cpp
        src/Message.cpp
        src/Pack.cpp
        src/Box.cpp
        src/Array.cpp
        src/Magnet.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

add_executable(test_${PROJECT_NAME}
        test/test_msg.cpp)
target_link_libraries(test_${PROJECT_NAME} PUBLIC ${PROJECT_NAME})

enable_testing()

add_test(NAME test_${PROJECT_NAME} COMMAND $<TARGET_FILE:test_${PROJECT_NAME}> WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})