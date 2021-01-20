cmake_minimum_required(VERSION 3.16)
enable_testing()

project( RocketData )

set("RocketData_sources" ${CMAKE_CURRENT_SOURCE_DIR}/src/RocketData.cpp)
set("RocketData_include" ${CMAKE_CURRENT_SOURCE_DIR}/Include)
set("RocketData_dependencies" "SensorValues" "Logger" "Configuration" "Rocket_Layer_Common")

add_library("${PROJECT_NAME}" ${RocketData_sources})

target_include_directories("${PROJECT_NAME}" PUBLIC ${RocketData_include})
target_link_libraries("${PROJECT_NAME}" PRIVATE ${RocketData_dependencies})

########################################################################
set("Common_Test_Source" ${CMAKE_CURRENT_SOURCE_DIR}/testing/FlightLoader.cpp)
function(create_RocketData_test)
    
    #parse all inputs namely NAME, SOURCE, and PASS_REGEX
    #Other two are not used, just needed for function call
    set(options)
    set(args NAME SOURCE PASS_REGEX )
    set(list_args RESOURCES)
    cmake_parse_arguments(
        PARSE_ARGV 0
        test
        "${options}"
        "${args}"
        "${list_args}"
    )   
    
    #print a warning for all arguements that were not parsed
    foreach(arg IN LISTS test_UNPARSED_ARGUMENTS)
        message(WARNING  "Unparsed Arguement: ${arg}")
    endforeach()
    
	
    #Create the executable and link to the library
    add_executable(${test_NAME} ${test_SOURCE} ${Common_Test_Source})
    target_link_libraries(${test_NAME} PRIVATE "${PROJECT_NAME}")
	target_link_libraries(${test_NAME} PRIVATE ${RocketData_dependencies} )
    add_test("${test_NAME}_test"  "${test_NAME}")

    #if there is a REGEX that was passed in(usually no but sometimes yes) check it against this variable
    if(DEFINED ${test_PASS_REGEX})
        set_property(TEST ${test_NAME}
            PROPERTY PASS_REGULAR_EXPRESSION ${test_PASS_REGEX}
        )
    endif()
    foreach(file IN LISTS test_RESOURCES)
    	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/testing/${file}"
        	DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/resources")
    endforeach()
endfunction()

create_RocketData_test(
	NAME "Rocket_Data_Test"
	SOURCE "testing/RocketDataTester.cpp"
	RESOURCES "resources/TestData.csv"
)
create_RocketData_test(
	NAME "Rocket_Angle_Test"
	SOURCE "testing/AngleTester.cpp"
)

create_RocketData_test(
	NAME "No_Noise_Test"
	SOURCE "testing/NoNoiseFlight.cpp"
)
