#include <Arduino.h>

#include <MemoryFree.h>
#include "Adafruit_NeoPixel.h"
#include "FastLED.h"
#include "EEPROM.h"

void t(String t){Serial.println(t);}
void n(int n){Serial.println(n);}


#define STRIP_NUM 4

#define SYSTEM_MAX_BRIGHT 255

#define GC_TIME 600
#define GC_HALF_TIME 300
#define GC_MIN_BRIGHT 0



#include "AXILLARY.h"
#include "Modes.h"
#include "QuantumController.h"



QuantumController *quantumController;


void setup() {

  t("|===========| wassup vanilla face |===========|");

  quantumController = new QuantumController();

}
