#include "ADXL.h"
void setup(){
  // put your setup code here, to run once:
   printf("La valeur de l'octet pour 3200Hz est : 0x%02X\n", ADXL_DATARATE.RATE_3200_HZ);
   printf("La valeur de l'adresse du registre pour DATA_RATE est : 0x%02X\n", ADXL_REG.REG_DATA_FORMAT);


}

void loop() {
  // put your main code here, to run repeatedly:
  
  }
