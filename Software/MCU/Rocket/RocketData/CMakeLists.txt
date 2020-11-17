cmake_minimum_required(VERSION 3.16)
enable_testing()

project( RocketData )

set("RocketData_sources" ${CMAKE_CURRENT_SOURCE_DIR}/src/RocketData.cpp)
set("RocketData_include" ${CMAKE_CURRENT_SOURCE_DIR}/Include)

add_library("${PROJECT_NAME}" ${RocketData_sources})

target_include_directories("${PROJECT_NAME}" PUBLIC ${RocketData_include})
target_link_libraries(RocketData, SensorData)
########################################################################

function(create_RocketData_test)
    
    #parse all inputs namely NAME, SOURCE, and PASS_REGEX
    #Other two are not used, just needed for function call
    set(options)
    set(args NAME SOURCE PASS_REGEX)
    set(list_args)
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
    add_executable(${test_NAME} ${test_SOURCE})
    target_link_libraries(${test_NAME} PRIVATE "${PROJECT_NAME}")
    add_test("${test_NAME}_test"  "${test_NAME}")

    #if there is a REGEX that was passed in(usually no but sometimes yes) check it against this variable
    if(DEFINED ${test_PASS_REGEX})
        set_property(TEST ${test_NAME}
            PROPERTY PASS_REGULAR_EXPRESSION ${test_PASS_REGEX}
        )
    endif()
endfunction()

create_RocketData_test(
	NAME "Rocket_Data_Test"
	SOURCE "testing/RocketDataTester.cpp"
)