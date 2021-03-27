# Nova Software High Level Code

## Note from the Original Developer

This is the High Level software for the Nova Flight Computer, this code is structured in modules
with many tests that way you, future developer, can edit without fear that there is a mistake. As
a quick note, as you develop new features, and find all the bugs I left you, I encourage you to
write tests to ensure that you dont have to think about making that mistake again because the
computer will catch it. In addition you will notice that all the tests are run on your computer
and not on the final MCU, this is because when I started coding, it was several months before
I was going to be able to see a functinoal board, and several more until I could have reliable
ownership of it. This delay was deemed unacceptable so I planned to write the logic now and deal
with the cross compiler later.

There are many things in hindsight I would change in hindsight, there would likely be more
standardization of a module(as in make a script to create a module for me), I would probably
restructure the code, and that message protocol.... disgusting.


## Documentation outline

This code is divided up into a number of modules each of which accomplishes a specific goal,
at time of writing, the modules dependencies are listed near the top of the CMakeLists.txt file
in a variable named Dependencies. I have strived to make the names of things as accurate as
possible in order to make it clear to future programmers what is doing what and how it works.
Each of these modules is defined in its own module. These modules are defined in detail in each
of thier folders in how they work and other assorted information that might be. I will be giving
a quick one or two sentance overview of each module here.

 1. Rocket Layer
    * The overall module that combines all of the functionality into one interface for ease of use
 2. Rocket Data
    * This module is responsible for taking the sensor Data and procesing it to determine where in
space the rocket is and how it is orienteed at thismoment
 3. Brain
    * This module is responsible for taking where the rocket is in space and making any decisions
that the rocket needs to make
 4. Message Parser
    * This module is resonsible for handling all of the message that go to/from the high level
module and taking the appropriate action
 5. configuration
    * This module is for any flight specific settings that the flight computer has to operate
under
 6. Logger
    * This module is for logging messages for later diagnoses
 7. SensorValues
    * This module is for holding all of the sensor data that comes from the low level code
 8. StateMachine
    * This module is for holding the current state of the rocket in its flight
 9. Common
    * This is a module that holds common structures that are common to the entire high level code
 10. CommonTest
    * This is a module that holds some test structures that are used in multiple places