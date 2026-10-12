//class Fade{
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
//
//
//
//class Perlin{
//    
//  int counter = 0;  
//  Adafruit_NeoPixel *strip;
//
//  byte minSat, ledNum, fireStep;
//  unsigned int hueStart, hueGap;
//
//  public: Perlin(Adafruit_NeoPixel *st, int ledN, long *prms){
//
//    strip = st;
//    ledNum = ledN;
//
//    hueStart = prms[0];
//    hueGap = prms[1];
//
//    fireStep = prms[2];
//    minSat = prms[3];
//  }
//
//
// 
//  
//  public: void tick(){
//  
//      for(int i = 0; i < ledNum; i++)
//        strip->setPixelColor(i, getFireColor((inoise8(i * fireStep, counter))));
//  
//      counter += 5;      
//  }
//  
//  
//  
//  long getFireColor(int val) {
//  
//    return strip->ColorHSV(
//               hueStart + map(val, 0, 255, 0, hueGap),                      // H  
//               constrain(map(val, 0, 255, minSat, 255), 0, 255),            // S
//               constrain(map(val, 0, 255, 10, SYSTEM_MAX_BRIGHT), 0, 255)   // V   
//             );
//  }
//};
//
//
//
//class GradualChange{
//
//  unsigned long stTime;
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
//
//    if(millis() - stTime >= GC_TIME){
//    
//    finished = true;
//    strip->setBrightness(SYSTEM_MAX_BRIGHT);
//    return;
//    }
//      
//    if(!halfWay && millis() - stTime >= GC_HALF_TIME)
//      halfWay = true;
//    
//    
//    byte brig;
//    
//    if(millis() - stTime <= GC_HALF_TIME)
//      brig = (map(millis() - stTime, 0, GC_HALF_TIME, SYSTEM_MAX_BRIGHT, 0));
//    else
//      brig = (map(millis() - stTime - GC_HALF_TIME, 0, GC_HALF_TIME, 0, SYSTEM_MAX_BRIGHT));
//    
//    strip->setBrightness(brig);  
//    
//  }
//
//  
//
//
//  
//};
//
///*
//
//
//
//
//byte rainbowDelay = 10;
//
//class Rainbow{
//
//  long lastUPD;
//  long firstPixelHue = 0;
//  
//  public:Rainbow(){
//
//    lastUPD = 0;
//    
//  }
//  
//  void tick() {
//
//
//    if(millis() - lastUPD < rainbowDelay)
//      return;
//      
//
//    lastUPD = millis();
//
//    if(firstPixelHue >= 327680)
//      firstPixelHue = 0;
//
//    for(int i = 0; i < NUM_LEDS; i++) { 
//
//      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
//
//      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
//    }
//    
//    firstPixelHue += 256;
//  }
//};
//
//
//
//Rainbow *rainbowLink;
//
//
//void rainbow(){
//
//  if(rainbowLink == NULL)
//    rainbowLink = new Rainbow();
//
//  rainbowLink->tick();
//}
//*/
