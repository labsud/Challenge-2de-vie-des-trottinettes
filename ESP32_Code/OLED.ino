void initOLED() {

  u8g2_SetI2CAddress(&display, 0x3c);
  display.begin();

  xTaskCreate(
    manageOLED,    // Function that should be called
    "manageOLED",   // Name of the task (for debugging)
    1000,            // Stack size (bytes)
    NULL,            // Parameter to pass
    1,               // Task priority
    NULL             // Task handle
  );
}

void manageOLED(void* parameter)
{
  for (;;) {

    /*
        static unsigned long hash = 0;
        static unsigned long previousHash = 0;
        hash = remoteConnected | computedAcc = 0 << 1;
        if (hash != previousHash)
        previousHash = hash;*/

    static unsigned long startTime = millis();

    if (millis() >= (startTime + 300))
    {
      startTime = millis();

      if (remoteConnected == false) OLEDSimpleText("Manette deconnectee");
      else  OLEDSimpleText("Manette connectee");

    }
    vTaskDelay(20 / portTICK_PERIOD_MS);
  }
}

void OLEDSimpleText(char* text)
{

  display.clearBuffer();

  display.setFont(u8g2_font_5x7_mr); // choose a suitable font
  display.setCursor(ALIGN_CENTER(text), V_CENTER(15));
  display.print(text);

  display.drawFrame(1, 1, 128 - 1, 64 - 1);

  display.sendBuffer();          // transfer internal memory to the display

}
