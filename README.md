ArduinoMindwave
================

Arduino library to interface with the [Mindwave Mobile](http://www.neurosky.com/products/mindwavemobile.aspx) brainwave reader. Based on the [sample Arduino code](http://developer.neurosky.com/docs/doku.php?id=mindwave_mobile_and_arduino) from Neurosky, with some modifications to make it non-blocking, more object oriented and easier to use.

Built by [Adrià Navarro](http://adrianavarro.net) at [Red Paper Heart](http://redpaperheart.com) for [“Remember”](http://redpaperheart.com/work/remember), a typographic installation inspired by wooden push toys.

Installation
------------
1- Download the zip file and decompress it in the “libraries” folder of your Arduino sketches folder. Restart the Arduino environment.

2- Setup the hardware. You’ll need an [Arduino](http://arduino.cc/en/Main/arduinoBoardUno) and a [Bluetooth modem](https://www.sparkfun.com/products/10269). There are instructions on how to wire these and pair them with the Mindwave headset [here](http://developer.neurosky.com/docs/doku.php?id=mindwave_mobile_and_arduino) and [here](http://www.whizzosoftware.com/forums/blog/1/entry-48-bluesmirf-silver-bluetooth-modem-and-mac-os-x/).

3- Open the example at File/Examples/Mindwave/BasicMindwave and upload it to the Arduino. The wire to the Rx pin (0) will have to be unplugged or you will get an error. Plug it back after uploading, and see the console for the Serial port at 57600 bauds.

Usage
-----
Create a new sketch and include the Mindwave library through the menu *Sketch/Import Library/Mindwave*

Declare a Mindwave object and start using the following functions>

- `void setup()`     
Initializes the class and opens a serial port at 57600 bauds. Needs to be called in the setup() function of the sketch.

- `void update()`     
Listens for new brainwave data and parses it. Needs to be called in the update() function of the sketch.

- `void setDebug(boolean debug)`    
Tells the Mindwave class whether to print the received data or not.

- `void setTimeout(long t)`     
Sets the millis that it will take before deciding that there is not data coming in, and setting the quality to 0. Default is 5000 (5 seconds).

- `boolean hasNewData()`    
Returns a boolean indicating if a new data packet has been parsed.

- `boolean isDebugging()`     
Returns a boolean indicating if the Mindwave is set to debug.

- `byte getAttention()` and `byte getMeditation()`     
Returns a number from 0 to 100 with the level of attention or meditation.

- `byte getQuality()` and `byte getPoorQuality()`     
Returns a number from 0 to 200 with the quality of the signal. Quality goes from 0 (bad quality) to 200 (good) and PoorQuality is the inverse.

