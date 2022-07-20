void onConnect() {
  Serial.println("Connected.");
}

void initPS3()
{
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin(PS3_MAC);
}

void managePS3()
{

  if (!Ps3.isConnected())
    return;

}

int rawToAcc(int val)
{
  float result = 0;

  result = val * val * val * 0.000125;

  return int(result);

}

void notify()
{
  if ( Ps3.event.button_down.select)
  {
    static byte status = 0;
    status++;
    if (status >= 3) status = 0;
    switch (status) {
      case 0:
        maxSpeed = LOW_MAXSPEED;
        buz(500, 1);
        break;
      case 1:
        maxSpeed = MEDIUM_MAXSPEED;
        buz(500, 2);
        break;
      case 2:
        maxSpeed = LUDICROUS_MAXSPEED;
        buz(500, 3);
        break;

    }
    Serial.print("maxSpeed = ");
    Serial.println(maxSpeed);
  }


  if ( Ps3.event.button_down.start )
  {
    active = !active;
    if(active)buz(200, 2);
    else buz(200, 1);
    Serial.print("Active = ");
    Serial.println(active);

    /*if (active) {
      display.setCursor(ALIGN_CENTER("Active"), 40);
      display.print("Active");
      display.sendBuffer();
      } else {
      display.setCursor(ALIGN_CENTER("Inactive"), 40);
      display.print("Inactive");
      display.sendBuffer();
      }*/
  }

  if (active)
  {

    /* if (Ps3.data.analog.stick.ry < ((-1) * (DEAD_ZONE)) ) dirSpeed = 0;
      if (Ps3.data.analog.stick.ry > DEAD_ZONE ) dirSpeed = 1;*/

    if (abs(Ps3.data.analog.stick.ry) > DEAD_ZONE) accVal = rawToAcc(Ps3.data.analog.stick.ry); 
    else accVal = 0;

    dir = Ps3.data.analog.stick.lx > 0 ? 1 : 0;
    speed = map(abs(Ps3.data.analog.stick.lx) > 127 ? 127 : abs(Ps3.data.analog.stick.lx), 0, 127, STEP_MAX_DELAY, STEP_MIN_DELAY);

    /* Serial.print("right stick:");
       Serial.print(" dirSpeed="); Serial.print(dirSpeed);
       Serial.print(" x="); Serial.print(Ps3.data.analog.stick.rx, DEC);
       Serial.print(" y="); Serial.print(Ps3.data.analog.stick.ry, DEC);
       Serial.print(" accVal =");
       Serial.print(accVal);
       Serial.print("  left stick x="); Serial.print(Ps3.data.analog.stick.lx, DEC);
       Serial.print("  Speed = ");
       Serial.println(speed);*/
  }

  if ( Ps3.event.button_down.cross ) {
    Serial.println("Pressing the cross button");
  }

  if ( Ps3.event.button_down.square ) {
    Serial.println("Pressing the square button");
  }

  if ( Ps3.event.button_down.triangle ) {
    Serial.println("Pressing the triangle button");
  }

  if ( Ps3.event.button_down.circle ) {
    Serial.println("Pressing the circle button");
  }
}
