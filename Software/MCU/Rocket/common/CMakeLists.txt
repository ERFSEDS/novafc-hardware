CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
enable_testing()
project("Rocket_Layer_Common")

set("Rocket_Layer_Common_sources" ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)
set("Rocket_Layer_Common_include" ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Create a library from source files
add_library("${PROJECT_NAME}" ${Rocket_Layer_Common_sources})

#Include the header files for everyone else to use
target_include_directories("${PROJECT_NAME}" PUBLIC ${Rocket_Layer_Common_include})

#declare a function to make a test
function(create_rocket_layer_common_test)
    
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

create_rocket_layer_common_test(
	NAME "Cartesian_Math"
	SOURCE "testing/CartesianMath.cpp"
)
create_rocket_layer_common_test(
	NAME "Quanternion_Math"
	SOURCE "testing/QuanternionMath.cpp"
)
