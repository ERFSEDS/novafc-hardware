cmake_minimum_required(VERSION 3.16.3)
enable_testing()

#Create a sub project named Message Handler 
project("MessageHandler")

#Create variables for sources and header files
set("MessageHandler_sources" ${CMAKE_CURRENT_SOURCE_DIR}/src/MessageHandler.cpp)
set("Messagehandler_include" ${CMAKE_CURRENT_SOURCE_DIR}/include)
set("MessageHandler_dependencies" "Brain" "SensorValues" "Logger" "Configuration" "RocketData" "State_Machine" "Rocket_Layer_Common")
#Create a library from source files
add_library("${PROJECT_NAME}" ${MessageHandler_sources})

#Include the header files for everyone else to use
target_include_directories("${PROJECT_NAME}" PUBLIC ${Messagehandler_include})
target_link_libraries("${PROJECT_NAME}" PRIVATE ${MessageHandler_dependencies})
#declare a function to make a test
set("message_handle_test_depends" ${MessageHandler_dependencies} "common_test")
set("message_handle_common_src" "test/TransmitSnooper.cpp")
function(create_MessageHandler_test)
    
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
    add_executable(${test_NAME} ${test_SOURCE} ${message_handle_common_src})
    target_link_libraries(${test_NAME} PRIVATE "${PROJECT_NAME}")
    target_link_libraries(${test_NAME} PRIVATE ${message_handle_test_depends})
    add_test("${test_NAME}_test"  "${test_NAME}")

    #if there is a REGEX that was passed in(usually no but sometimes yes) check it against this variable
    if(DEFINED ${test_PASS_REGEX})
        set_property(TEST ${test_NAME}
            PROPERTY PASS_REGULAR_EXPRESSION ${test_PASS_REGEX}
        )
    endif()
endfunction()

create_MessageHandler_test(
	NAME "TempTest"
	SOURCE "test/workingTest.cpp"
)





