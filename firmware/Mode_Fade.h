
/**
 * params[0] - col1
 * params[1] - col2
 * params[2] - fade cycle time
 * 
 * long[0] - start time
 * 
 * //byte[0] - cycle done
 * //byte[0] - direction
 * 
 * 
 * bool[0] - direction
 */
void fade(StripController * st){

  if(!st->longVars[0]){ //not initialized

    st->longVars[0] = millis(); //start time
    
    st->cols[0][0] = colCon(&st->params[0], 'R');
    st->cols[0][1] = colCon(&st->params[0], 'G');
    st->cols[0][2] = colCon(&st->params[0], 'B');

    st->cols[1][0] = colCon(&st->params[1], 'R');
    st->cols[1][1] = colCon(&st->params[1], 'G');
    st->cols[1][2] = colCon(&st->params[1], 'B');

    st->cols[2][0] = (short) st->cols[1][0] - (short) st->cols[0][0];
    st->cols[2][1] = (short) st->cols[1][1] - (short) st->cols[0][1];
    st->cols[2][2] = (short) st->cols[1][2] - (short) st->cols[0][2];
    
    t("initilz");
    /*
    Serial.println(st->cols[0][0]);
    Serial.println(st->cols[0][1]);
    Serial.println(st->cols[0][2]);
    Serial.println(st->cols[1][0]);
    Serial.println(st->cols[1][1]);
    Serial.println(st->cols[1][2]);
    Serial.println(st->cols[2][0]);
    Serial.println(st->cols[2][1]);
    Serial.println(st->cols[2][2]);*/
    
  }


  if(millis() - st->longVars[0] >= st->params[2]){ //done

    st->longVars[0] = st->longVars[0] + st->params[2];

    st->boolVars[0] = !(st->boolVars[0]);

    if(!st->boolVars[0]){

      st->cols[2][0] = (short) st->cols[1][0] - (short) st->cols[0][0];
      st->cols[2][1] = (short) st->cols[1][1] - (short) st->cols[0][1];
      st->cols[2][2] = (short) st->cols[1][2] - (short) st->cols[0][2];
    }
    else{

      st->cols[2][0] = (short) st->cols[0][0] - (short) st->cols[1][0];
      st->cols[2][1] = (short) st->cols[0][1] - (short) st->cols[1][1];
      st->cols[2][2] = (short) st->cols[0][2] - (short) st->cols[1][2];
    }
    //Serial.println(st->cols[2][0]);
    //Serial.println(st->cols[2][1]);
    //Serial.println(st->cols[2][2]);
    //t("reverse dir"); Serial.println(st->boolVars[0]);
  }

  short R, G, B;
  float progress = (map(millis() - st->longVars[0], 0, st->params[2], 0, 1000) / (float) 1000);


  //Serial.println(progress);
  
  if(st->boolVars[0]){ //reverse direction

    R = (short) st->cols[1][0] + st->cols[2][0] * progress;
    G = (short) st->cols[1][1] + st->cols[2][1] * progress;
    B = (short) st->cols[1][2] + st->cols[2][2] * progress;
  }
  else{

    
    R = (short) st->cols[0][0] + st->cols[2][0] * progress;
    G = (short) st->cols[0][1] + st->cols[2][1] * progress;
    B = (short) st->cols[0][2] + st->cols[2][2] * progress;
    
  }

  for(int i = 0; i < st->ledNum; i++)      
      st->strip->setPixelColor(i, R, G, B);
}

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

void Fade(){


  
}
