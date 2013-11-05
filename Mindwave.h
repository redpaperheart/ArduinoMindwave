/*
 Mindwave.cpp
 Created by Adrià Navarro at Red Paper Heart
 To contact, email hello@redpaperheart.com
 
 Based on the sample code by Neursoky
 http://developer.neurosky.com/docs/doku.php?id=mindwave_mobile_and_arduino
 
 For installation and usage instructions check
 https://github.com/redpaperheart/Arduino-Mindwave
 */

#ifndef Mindwave_h
#define Mindwave_h
#define BAUDRATE 57600  // for bluetooth and serial debug

#include "Arduino.h"

class Mindwave
{
public:
  void setup();
  void update();
  void setDebug(bool d)     {debug = d;}
  void setTimeout(long t)   {timeOut = t;}              // in millis
  boolean hasNewData()      {return newPacket;}
  boolean isDebugging()     {return debug;}
  byte getAttention()       {return attention;}         // 0 (bad) to 100 (good)
  byte getMeditation()      {return meditation;}        // 0 (bad) to 100 (good)
  byte getPoorQuality()     {return poorQuality;}       // 0 (good) to 200 (bad)
  byte getQuality()         {return 200 - poorQuality;} // 0 (bad) to 200 (good)
    
private:
  byte readOneByte();
  byte readFirstByte();

  boolean debug;
  boolean newPacket;
  byte payloadData[64];
  byte poorQuality;
  byte attention;
  byte meditation;
  long lastReceivedPacket;
  long timeOut;
};

#endif



