void IRAM_ATTR TimerHandler0()
{
  buzState = !buzState;
  ledcWrite(2, buzState == 0 ? 0 : 2048);
  buzCount--;
  if (buzCount <= 0) {
    ITimer0.detachInterrupt();
    //digitalWrite(BUZ_PIN, 0);
    ledcWrite(2, 0);
  }
}

void initBuzer()
{
  //pinMode(BUZ_PIN, OUTPUT);
  ledcAttachPin(BUZ_PIN, 2);
  ledcSetup(2, 4000, 12);
  ledcWrite(2, 0);
  //ITimer0.detachInterrupt();
  ledcWrite(2, 0);
}

void buz(int period, int times)
{
  ITimer0.attachInterruptInterval(period * 1000, TimerHandler0);
  buzCount = times * 2;
  ledcWrite(2, 2048);
  buzState = 1;
}
