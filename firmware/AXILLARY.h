byte colCon(long *hexValue, char color){
      
    if(color == 'R')        
      return ((*hexValue >> 16) & 0xFF);    
    if(color == 'G')
        return ((*hexValue >> 8) & 0xFF);
    if(color == 'B')
      return ((*hexValue) & 0xFF);
}

long hexToDec(char *hexString) {
  
  long decValue = 0;
  int nextInt;
  
  for (int i = 0; i < 8; i++) {
    
    nextInt = int(hexString[i]);
    if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
    if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
    if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
    if (nextInt == 'x' || nextInt == 'X') nextInt = 0;

    nextInt = constrain(nextInt, 0, 15);

    decValue = (decValue * 16) + nextInt;
  }

  return decValue;
}

long EEPROMReadlong(long address) {
  
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);
  
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

void EEPROMWritelong(int address, long value) {
  
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);
  
  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}


void (*reset) (void) = 0;
