//fucking tits 

/**
 * int[0] - counter
 * 
 * 
 * params[0] - color 1 hue
 * params[1] - hue gap
 * params[2] - fire step
 * params[3] - minSat
 */


void perlin(StripController * st){

  for(int i = 0; i < st->ledNum; i++)
    st->strip->setPixelColor(i, getFireColor(st, (inoise8(i * st->params[2], st->intVars[0]))));

  st->intVars[0] += 5;  
}


long getFireColor(StripController * st, int val) {

  return st->strip->ColorHSV(
             st->params[0] + map(val, 0, 255, 0, st->params[1]),                  //H  
             constrain(map(val, 0, 255, st->params[3], 255), 0, 255),             //S
             constrain(map(val, 0, 255, 10, SYSTEM_MAX_BRIGHT), 0, 255)           //V   
           );
}
