cmake_minimum_required(VERSION 3.16.3)
enable_testing()

#Create a sub project named COnfiguration
project("Configuration")

#Create variables for sources and header files
set("Configuration_sources" ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration.cpp)
set("Configuration_include" ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Create a library from source files
add_library("${PROJECT_NAME}" ${Configuration_sources})

#Include the header files for everyone else to use
target_include_directories("${PROJECT_NAME}" PUBLIC ${Configuration_include})

#declare a function to make a test
function(create_config_test)
    
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

create_config_test(
	NAME "Two_Stage_Test"
	SOURCE "testing/testTwoStage.cpp"
)
create_config_test(
	NAME "Safety_Lock_Test"
	SOURCE "testing/testSafetyLock.cpp"
)
create_config_test(
	NAME "Pyro_Channel_Test"
	SOURCE "testing/testPyroChannels.cpp"
)
create_config_test(
	NAME "Thresholds_Test"
	SOURCE "testing/testThresholds.cpp"
)
create_config_test(
	NAME "Logging_Rates_Test"
	SOURCE "testing/testLoggingRates.cpp"
)
create_config_test(
	NAME "Altitude_Determination_Test"
	SOURCE "testing/testAltitudeDetermination.cpp"
)
create_config_test(
	NAME "Arming_Altitude_Test"
	SOURCE "testing/testArmingAltitude.cpp"
)
create_config_test(
	NAME "Drogue_Chute_Test"
	SOURCE "testing/testDrogueChute.cpp"
)
create_config_test(
	NAME "Main_Pyro_Test"
	SOURCE "testing/testMainPyroChannel.cpp"
)
create_config_test(
	NAME "Drogue_Pyro_Test"
	SOURCE "testing/testDroguePyroChannel.cpp"
)
create_config_test(
	NAME "Default_Value_Test"
	SOURCE "testing/testDefaults.cpp"
)
create_config_test(
	NAME "Safe_Defaults_Test"
	SOURCE "testing/testSafeDefaults.cpp"
)
