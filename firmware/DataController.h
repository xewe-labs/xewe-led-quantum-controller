void updateMemParams(byte id, long *params){

  if(params[0] != -1){

    //Serial.print((params[0])); t(" p 0 wrote");
  
    EEPROMWritelong(1 + id * 17, params[0]);
  }
  
  if(params[1] != -1){

    //Serial.print((params[1])); t(" p 1 wrote");

    EEPROMWritelong(5 + id * 17, params[1]);
  }
  
  if(params[2] != -1){
    
    //Serial.print((params[2])); t(" p 2 wrote");
    EEPROMWritelong(9 + id * 17, params[2]);
  }
  
  if(params[3] != -1){
    
    //Serial.print((params[3])); t(" p 3 wrote");

    EEPROMWritelong(13 + id * 17, params[3]);
  }
}



void updateMemMode(byte id, char mode){

  EEPROM.write(id * 17, mode);
}



void readMemParams(byte id, long *params){

  params[0] = EEPROMReadlong(1 + id * 17);
  params[1] = EEPROMReadlong(5 + id * 17);
  params[2] = EEPROMReadlong(9 + id * 17);
  params[3] = EEPROMReadlong(13 + id * 17);

  Serial.print(id); Serial.print(' '); Serial.print(params[0]); Serial.print(' '); Serial.print(params[1]); Serial.print(' '); Serial.print(params[2]); Serial.print(' '); Serial.println(params[3]);
}



char readMemMode(byte id){

  //Serial.print(id); Serial.print(' ');  Serial.println((char) EEPROM.read(id * 17)); 
  
  return EEPROM.read(id * 17);
}
