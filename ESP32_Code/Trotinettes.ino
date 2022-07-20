/*** TODO
    Dashboard OLED
    PID stepper
    capteur angulaire


*/

/*** Wifi ***/
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <WiFiAP.h>

// Set these to your desired credentials.
const char *ssid = "trittinette";
const char *password = "labsud1234";

/*** PS3 Remote ***/

#include <Ps3Controller.h>

#define PS3_MAC "ac:67:b2:f9:7a:36"
#define DEAD_ZONE 10

byte active = 0;
boolean remoteConnected = false;

/*** PID ***/

/*#include <PIDController.h>
  PIDController pidBrushless;
  PIDController pidStepper;*/

/*** Brushless ***/

#include "analogWrite.h"

#define PWM_OUT 14
#define DIR_SPEED 15

#define LUDICROUS_MAXSPEED 255
#define MEDIUM_MAXSPEED 150
#define LOW_MAXSPEED 70
#define DEFAULT_MAXSPEED LOW_MAXSPEED

byte dirSpeed = 0;
int accVal = 0;
int maxSpeed = DEFAULT_MAXSPEED;
int computedAcc = 0;

/*** Stepper ***/

#define STEP_PIN 12
#define DIR_PIN 13

#define STEP_MAX_DELAY 4000
#define STEP_MIN_DELAY 70

long speed = STEP_MAX_DELAY;

byte dir = 0;

/* OLED */

#include <U8g2lib.h>
#include <Wire.h>

#define LCDWidth                        display.getDisplayWidth()
#define LCDHeight                       display.getDisplayHeight()
#define ALIGN_CENTER(t)                 ((LCDWidth - (display.getUTF8Width(t))) / 2)
#define ALIGN_RIGHT(t)                  (LCDWidth -  display.getUTF8Width(t))
#define ALIGN_LEFT                      0
#define V_CENTER(h)                     ((LCDHeight + (h)) / 2)
#define V_BOTTOM(h)                     (LCDHeight - (0))

U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 4, /* data=*/ 5);

/*** Buzzer ***/

#include "TimerInterrupt_Generic.h"
ESP32Timer ITimer0(1);
#define BUZ_PIN 26
volatile int buzCount = 0;
volatile byte buzState = 0;

void setup() {

  initBrushless();
  initStepper();
  Serial.begin(250000);
  
  initOLED();
  initPS3();
  initWifi();

  OLEDSimpleText("Manette deconnectee");
  initBuzer();
  //delay(1000);
 // buz(300, 2);
}

void loop()
{
  
  manageOTA();

  if (Ps3.isConnected())
  {
    if (remoteConnected == false)  buz(1000, 1);

    remoteConnected = true;
    manageBrushless();
    manageStepper();

  } else {
    
    if (remoteConnected == false)  buz(1000, 2);
    remoteConnected = false;
    buz(100, 1);
    delay(500);
    
  }

  //manageOLED();

}
