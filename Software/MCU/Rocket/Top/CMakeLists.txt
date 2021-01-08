project("Rocket_Lib")

set("Lib_Sources")
set("Lib_Include_Dir")
set("Lib_Dependencies")#literally all of them

add_library("${PROJECT_NAME}" ${Lib_Sources})
target_include_directories("${PROJECT_NAME}" PUBLIC ${Lib_Include_Dir})
target_link_libraries("${PROJECT_NAME}" PRIVATE ${RocketData_dependencies})

function(create_layer_test)
    
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
endfunction()


