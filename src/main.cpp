#include <Arduino.h>

#include "defines.h"
#include "ArduinoNvs.h"
#include "mywebserver.h"
#include "mywifi.h"

// GLOBALS
CMyWifi myWifi;


void setup() {
  // console init
  Serial.begin(115200);

  // non volatile storage init
  NVS.begin();

  // wifi init
  myWifi.Init();

  // http server init
  WebServerInit();

}

void loop() {
  // wifi check
  myWifi.Update();  

  // web handling
  WebServerUpdate();

  yield();  // iddle, reset watchdog 

}