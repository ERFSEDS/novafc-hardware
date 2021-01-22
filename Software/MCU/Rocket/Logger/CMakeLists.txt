cmake_minimum_required(VERSION 3.16.3)
enable_testing()

#Create a sub project named COnfiguration
project("Logger")

#Create variables for sources and header files
set("Logger_sources" ${CMAKE_CURRENT_SOURCE_DIR}/src/Logger.cpp)
set("Logger_include" ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Create a library from source files
add_library("${PROJECT_NAME}" ${Logger_sources})

#Include the header files for everyone else to use
target_include_directories("${PROJECT_NAME}" PUBLIC ${Logger_include})


set("logger_test_depends" "Logger" "common_test")
#declare a function to make a test
function(create_logger_test)
    
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
    target_link_libraries(${test_NAME} PRIVATE ${logger_test_depends})
    add_test("${test_NAME}_test"  "${test_NAME}")

    #if there is a REGEX that was passed in(usually no but sometimes yes) check it against this variable
    if(DEFINED ${test_PASS_REGEX})
    	set_tests_properties(${test_NAME} PROPERTIES
  			PASS_REGULAR_EXPRESSION "${test_PASS_REGEX}"
		)
    endif()
endfunction()


create_logger_test(
	NAME "Test_Fatal"
	SOURCE "test/testFatal.cpp"
	PASS_REGEX "[ERROR]: Test Fatal"
)

create_logger_test(
	NAME "Test_Error"
	SOURCE "test/testError.cpp"
	PASS_REGEX "[ERROR]: Test Error"
)

create_logger_test(
	NAME "Test_Event"
	SOURCE "test/testEvent.cpp"
	PASS_REGEX "[ERROR]: Test Event"
)

create_logger_test(
	NAME "Test_Warning"
	SOURCE "test/testWarning.cpp"
	PASS_REGEX "[ERROR]: Test Warning"
)

create_logger_test(
	NAME "Test_Info"
	SOURCE "test/testInfo.cpp"
	PASS_REGEX "[ERROR]: Test Info"
)

create_logger_test(
	NAME "Test_Debug"
	SOURCE "test/testDebug.cpp"
	PASS_REGEX "[ERROR]: Test Debug"
)

