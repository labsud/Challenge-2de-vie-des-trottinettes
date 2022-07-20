void initStepper()
{
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}

void manageStepper() {

  if (speed < STEP_MAX_DELAY)
  {
    digitalWrite(DIR_PIN, dir);
    digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
    delayMicroseconds(speed);
  }
  
}
