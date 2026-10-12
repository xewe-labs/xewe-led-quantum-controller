#include "DataController.h"

#include "StripController.h"

#include "SerialController.h"



class QuantumController {

    //CLASS OBJECTS//
    SerialController *serialController;
    StripController *strips[STRIP_NUM];


  public : QuantumController() {

      this->setup();
    }




  private: void setup() {

      int prevMem = freeMemory();

      changeStTime[0] = 0;
      changeStTime[1] = 0;
      changeStTime[2] = 0;
      changeStTime[3] = 0;

      serialController = new SerialController(strips);
      Serial.println("serial"); Serial.println(prevMem - freeMemory());
      prevMem = freeMemory();

      strips[0] = new StripController(0, 12, 77);

      Serial.println("strip 1"); Serial.println(prevMem - freeMemory());
      prevMem = freeMemory();

      strips[1] = new StripController(1, 10, 16);

      Serial.println("strip 2"); Serial.println(prevMem - freeMemory());
      prevMem = freeMemory();

      strips[2] = new StripController(2, 9, 16);

      Serial.println("strip 3"); Serial.println(prevMem - freeMemory());
      prevMem = freeMemory();

      strips[3] = new StripController(3, 11, 16);

      Serial.println("strip 4"); Serial.println(prevMem - freeMemory());
      prevMem = freeMemory();
    }


  public: void tick() {

      serialController->tick();
      
      for (int i = 0; i < STRIP_NUM; i++){

        if(strips[i]->modeChanging) //mode changing event
          if(!gradualChange(i))
            continue;

        if(strips[i]->modeUpdated){ //mode updated event

          strips[i]->strip->setBrightness(SYSTEM_MAX_BRIGHT);
          strips[i]->modeUpdated = false;
        }
        

        //Serial.print(i); Serial.print(' ');  Serial.println(strips[i]->mode);
        ///Serial.print(i); Serial.println(" m");
        
        switch(strips[i]->mode){

          case 'S':
            single(strips[i]);
          break;


          case 'U':

          break;


          case 'F':
            fade(strips[i]);
          break;


          case 'P':
            perlin(strips[i]);
          break;


          case 'R':
            rainbow(strips[i]);
          break;
        }

        strips[i]->tick();
      }
    }

    #include "ModeFunctions.h"


};
