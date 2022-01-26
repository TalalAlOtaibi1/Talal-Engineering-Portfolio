/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "28130aa6c98340c49162722c41a71eeb";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ayman003";
char pass[] = "20002001";

WidgetLCD lcd(V1);
WidgetLED led (V2);


void setup()
{
  pinMode(13,OUTPUT);
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{int x = analogRead (A0);
lcd.print( 1,0 , "Gas :");
lcd.print(8,0, x);
delay(300);
lcd.clear(); 
if(x>480)
{
  Blynk.notify("Danger!!! CO/CO2 concentration is approaching excessive levels!You're either grilling or getting grilled!");
  led.on();  
  digitalWrite(13,1);
  Blynk.email("thebomber016@gmail.com", "Life Box", "Danger!!! CO/CO2 concentration is approaching excessive levels!");
  led.on();
}
if(x<480)
{digitalWrite(13,0);
  led.off();
}
  Blynk.run();
}

