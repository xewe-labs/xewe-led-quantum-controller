#define BAUD_RATE 4800
#define MAX_CMD_LEN 40
#define TIMEOUT 100
#define DELAY_BEFORE 10
#define ITERATION_DELAY 3
#define TIMEOUT_PROTECTION 100



class SerialController{

  StripController **strips;
  long timeoutProtection = 0;
  
  public: SerialController(StripController **st){

    Serial.begin(BAUD_RATE);
    strips = st;
  }


  void tick(){

    //t("s t");
    
    if (Serial.available() && Serial.read() == '$')
      processCommand();
  }
  
  
  
  void processCommand(){


      //delay(25);
      char *cmd = getCommand();
  
      if(!cmd)
        return;
 
      //command processing
      byte cmdP = 0;
      
      char function = cmd[cmdP++];
      byte channel = cmd[cmdP++] - 48;

      Serial.print("Function : "); Serial.println(function);
      Serial.print("CH : "); Serial.println(channel);
      delay(25);

      if(function == 'm'){
        
        Serial.println(freeMemory());
        delete cmd;

        return;
      }

      if(function == 'r'){

        Serial.println("$r");
        delete cmd;
        reset();
      }


      if(!(function > 64 && function < 91 && (channel >= 0 && (channel < STRIP_NUM || channel == 9 || channel == 8)))){
        
        delete cmd;
        return;
      }

      long *prms = new long[4];

      prms[0] = -1;
      prms[1] = -1;      
      prms[2] = -1;
      prms[3] = -1;
  
      while(getValues(cmd, &cmdP, prms) && cmdP < MAX_CMD_LEN);


      if(function == 'F')
        prms[2] = map(prms[2], 1, 10, 10000, 1000);//10000 / (prms[2] * 1000);

      if(function == 'U'){

        prms[2] = map(prms[1], 1, 10, 10000, 1000);//10000 / (prms[1] * 1000);
        prms[1] = 0;

        function = 'F';
      }

      if(function == 'R')
        prms[0] *= 100;

      if(function == 'P')
        perlinProcessing(prms);
        
      if(channel < 8){
        
        strips[channel]->setParams(prms);
        strips[channel]->setMode(function, true);
      }
      
      else if (channel == 9){

        for(int i = 0; i < STRIP_NUM; i++){

          strips[i]->setParams(prms);
          strips[i]->setMode(function, true);
        }
      }
      else if (channel == 8){

        for(int i = 1; i < STRIP_NUM; i++){

          strips[i]->setParams(prms);
          strips[i]->setMode(function, true);
        }
      }

      delete cmd;
      delete prms;

      t("cmd process finished");
  }

  char* getCommand(){

    t("new cmd");
    
    char *cmd = new char[MAX_CMD_LEN];
  
    for(int i = 0; i< MAX_CMD_LEN; i++)
      cmd[i] = 0;
    
    long stTime = millis();
    bool timeOut = false;
  
    int i = 0;   
    for(;i < MAX_CMD_LEN && !timeOut; i++){
      
      while(!Serial.available() && !timeOut){      
        timeOut = (millis() - stTime >= TIMEOUT);
      }          

      cmd[i] = Serial.read();
      
      if(cmd[i] == ';')
        break;
        
      timeOut = (millis() - stTime >= TIMEOUT);
    }

    if(timeOut || i == MAX_CMD_LEN){
            
      delete cmd;
      return NULL;
    }
  
    cmd[++i] = '\0';

    //Serial.print("got cmd :"); Serial.println(cmd);
    
    return cmd;
  }



  bool getValues(char *cmd, byte *cmdP, long *params){

    //t("getting value "); Serial.println(*cmdP);
    if(cmd[*cmdP] == ':'){
        
        (*cmdP)++;
        
        char *argument = new char[8];
  
        for(int i = 0; i < 8; i++)
          argument[i] = 0;
          
        for(int i = 0; i < 8 && cmd[*cmdP] != ';' && cmd[*cmdP] != ':'; i++)
          argument[i] = cmd[(*cmdP)++];
          

        long hexVal = hexToDec(argument);

            
        if(params[0] == -1)
          params[0] = hexVal;

        else if(params[1] == -1)
          params[1] = hexVal;

        else if(params[2] == -1)
          params[2] = hexVal;

        else if(params[3] == -1)
          params[3] = hexVal;

  
        delete argument;

        return true;
    }
  
    return false;;
  } 

  void perlinProcessing(long *params){

    long hueGap = params[1] - params[0];

    Serial.println(hueGap);

    if(hueGap > 0){

      if(hueGap > 32768){

        long col1 = params[0];
        params[0] = params[1];
        params[1] = col1;

        hueGap = 65535 - params[0] + params[1];
      }
    }
    else{ //hue gap < 0

      hueGap *= -1;
      
      if(hueGap > 32678){

        hueGap = 65535 - params[0] + params[1];
      }
      else{//nice

        long col1 = params[0];
        params[0] = params[1];
        params[1] = col1;
      }

    }

    params[1] = hueGap;

    Serial.print("start "); Serial.println(params[0]);
    Serial.print("dif "); Serial.println(params[1]);


  }
};
