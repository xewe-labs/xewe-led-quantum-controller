/**
 * long[0] - firstPixelHue
 * 
 * int[0] - step
 */

void rainbow(StripController * st) {

  //int wait = 10;

  

  if(st->longVars[0] >= 327680)
    st->longVars[0] = 0;

  
  
  for(int i = 0; i < st->ledNum; i++) { 
    
    int pixelHue = st->longVars[0] + (i * 65536L / st->ledNum);
    st->strip->setPixelColor(i, st->strip->gamma32(st->strip->ColorHSV(pixelHue)));
  }
  

  st->longVars[0] += st->params[0];
  
}
