cmake_minimum_required(VERSION 3.16.3)
enable_testing()

#Create a sub project named COnfiguration
project("State_Machine")

#Create variables for sources and header files
set("State_Machine_sources" ${CMAKE_CURRENT_SOURCE_DIR}/src/StateMachine.cpp)
set("State_Machine_include" ${CMAKE_CURRENT_SOURCE_DIR}/include)
set("State_Machine_dependencies" "Logger" "Configuration")

#Create a library from source files
add_library("${PROJECT_NAME}" ${State_Machine_sources})

#Include the header files for everyone else to use
target_include_directories("${PROJECT_NAME}" PUBLIC ${State_Machine_include})
target_link_libraries("${PROJECT_NAME}" PRIVATE ${State_Machine_dependencies})

#declare a function to make a test
set("state_machine_test_depends" "common_test" "State_Machine" "Configuration" "Logger")
function(create_State_Machine_test)
    
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
    add_executable("${test_NAME}" ${test_SOURCE})
    target_link_libraries(${test_NAME} PRIVATE "${PROJECT_NAME}" ${state_machine_test_depends})
    add_test("${test_NAME}_test"  "${test_NAME}")

    #if there is a REGEX that was passed in(usually no but sometimes yes) check it against this variable
    if(DEFINED ${test_PASS_REGEX})
        set_property(TEST ${test_NAME}
            PROPERTY PASS_REGULAR_EXPRESSION ${test_PASS_REGEX}
        )
    endif()
endfunction()

create_State_Machine_test(
	NAME "One_Stage_Flight"
	SOURCE "test/testOneStageFlight.cpp"
)
create_State_Machine_test(
	NAME "Two_Stage_Flight"
	SOURCE "test/testTwoStageFlight.cpp"
)
create_State_Machine_test(
	NAME "Random_Changes"
	SOURCE "test/testRandomChanges.cpp"
)
create_State_Machine_test(
	NAME "Improper_transitions"
	SOURCE "test/testStateMapSetup.cpp"
)
