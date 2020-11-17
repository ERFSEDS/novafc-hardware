CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
enable_testing()
project("Rocket Layer")

set(Rocket_testing_dir ${CMAKE_CURRENT_SOURCE_DIR}/testing)
add_subdirectory(Logger)
add_subdirectory(configuration)
add_subdirectory(StateMachine)
add_subdirectory(SensorValues)

