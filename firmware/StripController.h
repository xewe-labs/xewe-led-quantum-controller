#define BOOL_NUM 2
#define BYTE_NUM 2
#define INT_NUM 3
#define LONG_NUM  2

///MAX LED NUM 255///
class StripController{

public:
  Adafruit_NeoPixel *strip;

  byte ledNum, id;
  char mode = 'S', newMode = 'x';
  bool paramsUpdated = true, modeUpdated = false, modeChanging = false, halfWayChange = false;
  
  long *params = new long[4];
  short cols[3][3];

  byte *boolVars = new byte[BOOL_NUM];
  byte *byteVars = new byte[BYTE_NUM];
  unsigned int *intVars = new unsigned int[INT_NUM];
  unsigned long *longVars = new unsigned long[LONG_NUM];
  
  public: StripController(byte id, byte pin, byte ledNum){

    this->id = id;
    this->ledNum = ledNum;
    
    strip = new Adafruit_NeoPixel(ledNum, pin, NEO_GRB + NEO_KHZ800);
    strip->begin();

    resetVars();
    for(int i = 0; i < 4; i++)
      params[i] = 0;
      
    readMemParams(id, params);
    setMode(readMemMode(id), false);
  }


  void tick(){

    strip->show();
  }


  void setParams(long *prms){

    if(prms[0] != -1){
      
      params[0] = prms[0];
      paramsUpdated = true;
      Serial.print("0  "); Serial.println(params[0]);
    }
      
    if(prms[1] != -1){
      
      params[1] = prms[1];
      paramsUpdated = true;
      Serial.print("1  "); Serial.println(params[1]);
    }      
    
    if(prms[2] != -1){
      
      params[2] = prms[2];
      paramsUpdated = true;
      Serial.print("2  "); Serial.println(params[2]);
    }    
      
    if(prms[3] != -1){
      
      params[3] = prms[3];
      paramsUpdated = true;
      Serial.print("3  "); Serial.println(params[3]);
    }

    updateMemParams(id, params);
  }

  void resetVars(){

    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        cols[i][j] = 0;

    for(int i = 0; i < BOOL_NUM; i++)
      boolVars[i] = 0;

    for(int i = 0; i < BYTE_NUM; i++)
      byteVars[i] = 0;
      
    for(int i = 0; i < INT_NUM; i++)
      intVars[i] = 0;

    for(int i = 0; i < LONG_NUM; i++)
      longVars[i] = 0;
  }


  void setMode(char m, bool updateMemory){

    //Serial.print("mode changed to "); Serial.println(m);
    
    modeChanging = true;

    newMode = m;
    
    if(updateMemory)
      updateMemMode(id, m);
  }
};
