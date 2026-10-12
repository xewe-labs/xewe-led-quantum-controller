void single(StripController * st){

    if(st->paramsUpdated){
            
      byte R = colCon(&st->params[0], 'R');
      byte G = colCon(&st->params[0], 'G');
      byte B = colCon(&st->params[0], 'B');
    
      for(int i = 0; i < st->ledNum; i++)
        st->strip->setPixelColor(i, R, G, B);
      
      st->paramsUpdated = false;
  } 
}
