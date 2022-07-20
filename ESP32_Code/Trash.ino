/*
  void OLEDWifiStart() {
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_roentgen_nbp_tf); // choose a suitable font
  u8g2.drawStr(12, 25, "Wifi & MQTT ");
  u8g2.drawStr(1, 45, "connecting...");
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);
  }

  void  OLEDWifiOK() {

  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_roentgen_nbp_tf); // choose a suitable font
  u8g2.drawStr(12, 25, "Wifi & MQTT ");
  u8g2.drawStr(12, 45, "connected !");
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);
  }*/

/*void  updateOLED() {

  char buf[15];

  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_roentgen_nbp_tf); // choose a suitable font

  u8g2.drawStr(12, 15, "pH : ");
  itoa(int(voltPH * 3300 / 4095.0), buf, 10);
  u8g2.drawStr(70, 15, buf);

  u8g2.drawStr(12, 25, "ORP : ");
  itoa(int(voltORP * 3300 / 4095.0), buf, 10);
  u8g2.drawStr(70, 25, buf);

    u8g2.drawStr(12, 45, "LvL : ");
  itoa(int(lvl), buf, 10);
  u8g2.drawStr(70, 45, buf);

  u8g2.sendBuffer();          // transfer internal memory to the display

  }*/
