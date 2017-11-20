# Embedded System Final Project Information

This README is simply to introduce to you the resources available for the final
project. If you have any questions, please contact the TA.

## Getting Started

### CPP Application
The Spider program code is located in the SpiderLinuxApplication directory.
As you will be implementing a custom linux application, you will need to create a
binary from your CPP code and transfer it to the Spider. Instead of using the 'Main.cpp'
file for your code, I have created a 'Project.cpp' file that contains the essentials
for starting your application the correct way. I've included all the header
files from Main.cpp and added the ADC header file (See below).

Utilizing the updated makefile, you only need to issue the 'make' command to compile
your application. The below mentioned applications and the original Spider program
are also built when issuing 'make'. Use 'make clean' to remove all compilation files.


### SD Card
The SpiderSDCardFiles directory contains all the updated files for the Spider to utilize
ADC pins on the board. If you are not planning on using an ADC sensor (IR sensor) then
you should not have to update your Spider's SD card.


### Spider Controller Program
The 'Controller' binary file was created to demonstrate some of the actions you can do
with Spider's legs. Primarily, it was created for folding the Spider's leg for easy
storage in their boxes. Simply run the binary supplied in the Binaries directory to
see the commands.

I have supplied the code for this program. You may use any part you wish, though I would
strongly suggest taking advantage of the fold function I implemented in the 'CSpider.cpp'
file.


## ADC for Sensors
In order to use the IR sensors for your projects, I have updated the Spider hardware
so that the sensors can be accessed from the Linux OS on the processor. I have also added
and ADC class to the Spider application folder. This class allows you to read a particular
channel from the ADC pins. There is also an ADCTest program that you can use to understand
the readings the sensor will provide.

The ADC pins are on the right side of the ethernet port and this layout reflects
if you are holding the Spider with the Ethernet port facing away from you. You'll
need to connect the SensorOutput to the ADC channel 0 pin and the 5V and GND wires
to the corresponding ADC pins.

ADC Pin Layout          Sensor Pins (Sensor Facing Up)
  * 5V  0                   SensorOutput  GND   5V
    1   2
    3   4
    5   6
    7   GND
