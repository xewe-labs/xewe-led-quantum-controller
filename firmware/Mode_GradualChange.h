long changeStTime[STRIP_NUM];

bool gradualChange(byte i){

  //Serial.print(i); Serial.println(" c");
          
  long curMillis = millis();
  
  if(!changeStTime[i]){
    changeStTime[i] = curMillis;

    //Serial.print(i); t("started");
  }

  if(curMillis - changeStTime[i] >= GC_TIME){ //gc finished

    //t("finished");
    strips[i]->modeChanging = false;
    strips[i]->halfWayChange = false;
    strips[i]->modeUpdated = true;
    strips[i]->strip->setBrightness(SYSTEM_MAX_BRIGHT);

    changeStTime[i] = 0;

    return true;
  }

  if(!strips[i]->halfWayChange && curMillis - changeStTime[i] >= GC_HALF_TIME){ // half way FUCKING TITS I BROKE SMTH BY ADDING HALF WAY VAR

    strips[i]->halfWayChange = true;

    strips[i]->mode = strips[i]->newMode;
    strips[i]->resetVars();  
  }

  byte brig;

  if(strips[i]->halfWayChange){ // half way

    brig = (map(curMillis - changeStTime[i] - GC_HALF_TIME, 0, GC_HALF_TIME, 20, SYSTEM_MAX_BRIGHT));
    strips[i]->strip->setBrightness(brig);  
    strips[i]->strip->show();  

    //Serial.print(i); Serial.print(' '); Serial.println(brig);

    return true;
  }
  else{
      brig = (map(curMillis - changeStTime[i], 0, GC_HALF_TIME, SYSTEM_MAX_BRIGHT, 20));
      strips[i]->strip->setBrightness(brig);  
      strips[i]->strip->show();  

      //Serial.print(i); Serial.print(' '); Serial.println(brig);
      return false;
  }
}
