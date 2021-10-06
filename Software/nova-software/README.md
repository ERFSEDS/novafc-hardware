# Nova Software

This is a [Cargo Workspace](https://doc.rust-lang.org/book/ch14-03-cargo-workspaces.html) that contains all of the sub-components of the Nova Flight Software. 

The current sub=components are:
* main
  * The main glue of the flight software. This contains the main function of the software, and runs everything else in a loop.
* state-machine
  * Handles the execution of states from the states configuration file. This allows different stages of the flight to execute commands.
* data-acquisition
  * Handles all data collection and stores it in memory for consumption by the state machine and telemetry.
* telemetry
  * Currently handles saving data to the SD card and/or flash memory. Will eventually be responsible for transmitting live data from the rocket to a ground station.