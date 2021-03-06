/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    MegaPiOnBoardStepperTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2016/05/06
 * @brief   Description: this file is sample code for Stepper Driver device.
 *
 * Function List:
 *
 *    1. void MeStepper::moveTo(long absolute); 
 *    2. void MeStepper::move(long relative);
 *    3. boolean MeStepper::run();
 *    4. void MeStepper::setMaxSpeed(float speed);
 *    5. void MeStepper::setAcceleration(float acceleration);
 *    6. void MeStepper::setMicroStep(int8_t value);
 *    7. void MeStepper::enableOutputs(void);
 *
 * \par History:
 * <pre>
 * <Author>     <Time>        <Version>      <Descr>
 * Mark Yan     2016/05/06    1.0.0          build the new.
 * </pre>
 */

#include "MeMegaPi.h"
#include <SoftwareSerial.h>

MeStepperOnBoard stepper(SLOT_1); 

void setup()
{  
  Serial.begin(9600);
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(20000);
  stepper.setMicroStep(16);
  stepper.enableOutputs();
}

void loop()
{
  if(Serial.available())
  {
    char a = Serial.read();
    switch(a)
    {
      case '0':
      stepper.moveTo(0);
      break;
      case '1':
      stepper.moveTo(200);
      break;
      case '2':
      stepper.move(50);
      break;
      case '3':
      stepper.move(100);
      break;
      case '4':
      stepper.move(200);
      break;
      case '5':
      stepper.move(400);
      break;
      case '6':
      stepper.move(600);
      break;
      case '7':
      stepper.move(4000);
      break;
      case '8':
      stepper.move(8000);
      break;
      case '9':
      stepper.move(3200);
      break;
    }
  }
  stepper.run();
}
