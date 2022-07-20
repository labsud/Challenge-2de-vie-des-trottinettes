void initBrushless()
{
  pinMode(DIR_SPEED, OUTPUT);
  analogWrite(PWM_OUT, 0);

/*  pidBrushless.begin();          // initialize the PID instance
  pidBrushless.setpoint(0);    // The "goal" the PID controller tries to "reach"
  pidBrushless.tune(1, 1, 1);    // Tune the PID, arguments: kP, kI, kD
  pidBrushless.limit(-127, 127);  */  // Limit the PID output between 0 and 255, this is important to get rid of integral windup!

/*
 * pinMode(BRAKE_PIN, OUTPUT);
 * digitalWrite(BRAKE_PIN,0);
 * pinMode(DIR_SPEED, OUTPUT);
 * digitalWrite(,0);
 */
}

void manageBrushless()
{

  static unsigned long startTimeBrushless = millis();
   

  if (millis() > (startTimeBrushless + 50))
  {

    startTimeBrushless = millis();
    dirSpeed = computedAcc > 0 ? 1 : 0;
    
    computedAcc = constrain(computedAcc,(-1)*maxSpeed,maxSpeed);
    int error = accVal - computedAcc ;

    computedAcc = computedAcc + constrain(error, -10, 10);
    
    analogWrite(PWM_OUT,abs(computedAcc));
    digitalWrite(DIR_SPEED, dirSpeed);

    Serial.print(accVal); Serial.print(","); Serial.print(error); Serial.print(","); Serial.println(computedAcc);
  }

}
