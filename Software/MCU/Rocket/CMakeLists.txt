CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
enable_testing()
project("Rocket Layer")


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(Logger)
add_subdirectory(SensorValues)
add_subdirectory(configuration)
add_subdirectory(StateMachine)
add_subdirectory(RocketData)
add_subdirectory(Brain)
