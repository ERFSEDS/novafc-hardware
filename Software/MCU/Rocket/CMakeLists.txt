
CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
enable_testing()
project("Rocket Layer")
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17")


add_subdirectory(common)
add_subdirectory(configuration)
add_subdirectory(commonTest)
add_subdirectory(Logger)
add_subdirectory(SensorValues)
add_subdirectory(StateMachine)
add_subdirectory(Brain)
add_subdirectory(RocketData)

add_subdirectory(MessageParser)
add_subdirectory(RocketLayer)
