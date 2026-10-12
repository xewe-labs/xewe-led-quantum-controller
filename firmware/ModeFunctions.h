#include "Mode_GradualChange.h"
#include "Mode_SingleColor.h"
#include "Mode_Fade.h"
#include "Mode_FadeSmart.h"
#include "Mode_Rainbow.h"





/**
 * params[0] - col1
 * params[1] - col2
 * params[2] - fade cycle time
 * 
 * long[0] - start time
 * 
 * byte[0] - cycle done
 * byte[1] - direction
 */
//void Fade(StripController * st){
//
//  long startT;
//  short colors[2][3];
//  public: bool finished = false;
//  int delay = 0;
//  byte ledNum = 0;
//  Adafruit_NeoPixel *strip;
//  
//  public:  
//    Fade(Adafruit_NeoPixel *st, byte ledN, long col1, long col2, short del){
//      
//      startT = millis();
//      getColors(&col1, &col2);
//
//      strip = st;
//      ledNum = ledN;
//      delay = del;
//      
//    }
//
//  void tick(){
//
//    if(millis() - startT >= delay){
//      
//      finished = true;
//      return;
//    }
//    
//    float progress = (map(millis() - startT, 0, delay, 0, 1000) / (float) 1000);
//    
//    byte R = colors[0][0] + colors[1][0] * progress;
//    byte G = colors[0][1] + colors[1][1] * progress;
//    byte B = colors[0][2] + colors[1][2] * progress;
//
//    for(int i = 0; i < ledNum; i++)      
//      strip->setPixelColor(i, R, G, B);
//
//  }
//
//  void getColors(long *col1, long *col2){
//      
//    colors[0][0] = colCon(col1, 'R');
//    colors[0][1] = colCon(col1, 'G');
//    colors[0][2] = colCon(col1, 'B');
//  
//    colors[1][0] = (short) colCon(col2, 'R') - (short) colors[0][0];
//    colors[1][1] = (short) colCon(col2, 'G') - (short) colors[0][1];
//    colors[1][2] = (short) colCon(col2, 'B') - (short) colors[0][2]; 
//  } 
//};
/*
 * FADE
 * 
 * Vars Used
 * 
 * boolVars[0] - fade in/out flag
 */
//Fade* fadeLink;
//
//void fade(){
//
//  if(fadeLink == NULL){
//
//          Serial.println(freeMemory());
//              fadeLink = new Fade(strip, ledNum, params[0], params[1], params[2]);
//
//
//  }
//
//
//  if(fadeLink->finished){
//    
//    delete fadeLink;
//    fadeLink = NULL;
//    
//    if(boolVars[0])
//      fadeLink = new Fade(strip, ledNum, params[0], params[1], params[2]);
//
//    else
//      fadeLink = new Fade(strip, ledNum, params[1], params[0], params[2]);
//    
//    boolVars[0] = !(boolVars[0]);
//  }
//    
//  fadeLink->tick();
//}
////------------------------------//



/*
 * PERLIN
 * 
 * Vars Used
 * colors[0] - hueStart
 * colors[1] - hueGap
 * params[0] - fireStep
 * params[1] - minSat
 */
 
//#define HUE_START 25000     // начальный цвет огня (0 красный, 80 зелёный, 140 молния, 190 розовый) colors[0]
//#define HUE_GAP 35000      // заброс по hue colors[1]
//#define FIRE_STEP 30    // шаг огня - param[0}
//#define MIN_BRIGHT 10   // мин. яркость огня - HARDCODED
//#define MAX_BRIGHT 255  // макс. яркость огня - SYSTEM_MAX_BRIGHTNESS
//#define MIN_SAT 180     // мин. насыщенность - param[1]
//#define MAX_SAT 255     // макс. насыщенность - HARDCODED
 
//Perlin* perlinLink = NULL;
//
//void perlin(){
//
//  if(perlinLink == NULL)
//    perlinLink = new Perlin(strip, ledNum, params);
//    
//  perlinLink->tick();
//}
//------------------------------//



/*
 * GRADUAL CHANGE
 * 
 */
//   unsigned long stTime;
//  
//  public:
//  bool halfWay = false, finished = false;
//  char oldMode, newMode;
//  Adafruit_NeoPixel *strip;
//
//  public: GradualChange(Adafruit_NeoPixel *st, char om, char nm){
//
//    strip = st;
//    oldMode = om;
//    newMode = nm;
//    
//    stTime = millis();
//  }
//
//  public: void tick(){

//    if(millis() - stTime >= GC_TIME){
//    
//    finished = true;
//    strip->setBrightness(SYSTEM_MAX_BRIGHT);
//    return;
//    }
      
//    if(!halfWay && millis() - stTime >= GC_HALF_TIME)
//      halfWay = true;
    
    
//    byte brig;
//    
//    if(millis() - stTime <= GC_HALF_TIME)
//      brig = (map(millis() - stTime, 0, GC_HALF_TIME, SYSTEM_MAX_BRIGHT, 0));
//    else
//      brig = (map(millis() - stTime - GC_HALF_TIME, 0, GC_HALF_TIME, 0, SYSTEM_MAX_BRIGHT));
//    
//    strip->setBrightness(brig);  
//    
// bool gradualChange(StripController * st, byte * br){
//
//    if(br <= 5){
//      
//      st->mode = st->newMode;
//
//      st->newMode = 'x';
//
//
//      st->resetVars();
//    }
//
//    if(changeLink->finished){
//
//      st->modeChanging = false;
//      st->modeUpdated = true;
//      
//    }
//}
