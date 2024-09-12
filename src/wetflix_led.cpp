#include "wetflix_led.h"
#include "user_defines.h"

// all leds are connected as per schematics(common anode---> led on-low(0);led off-high(1))

// LED setup
void led_setup()
{
   // ADC channel setup to 12 kHz PWM, 8-bit resolution
  ledcSetup(1, 12000, 8);
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);
 // Assigning LED pins to ADC channel
  ledcAttachPin(RED_LED_PIN, 1);
  ledcAttachPin(GREEN_LED_PIN, 2);
  ledcAttachPin(BLUE_LED_PIN, 3);

 
  // Green led is on, refers to power connection
  power_led_on();

 
}
void power_led_on()
{
  pinMode(POWER_LED_PIN,OUTPUT);
  digitalWrite(POWER_LED_PIN,HIGH);

  ledcWrite(1, 255);                 // RGB RED 
  ledcWrite(2, 0);                 // RGB GREEN
  ledcWrite(3, 255);                 // RGB BLUE
  delay(1000);

}

// when device going to deep sleep mode, all LEDs has to be OFF
void led_off()
{
 digitalWrite(POWER_LED_PIN,LOW);  // Power led will OFF
 ledcWrite(1, 255);                 // RGB RED 
 ledcWrite(2, 255);                 // RGB GREEN
 ledcWrite(3, 255);                 // RGB BLUE
}

// if there is fual guage less than 20 red led will turn on
void battery_low_led()             
{
  ledcWrite(1, 0);
  ledcWrite(2, 255);
  ledcWrite(3, 255);
  delay(1000);
}

// if there is an error, red led will blink for 4 times
void error_led()             
{
 for(int i=0;i<=3;i++)
 {
  // led is on
  ledcWrite(1, 0);
  ledcWrite(2, 255);
  ledcWrite(3, 255);
  delay(200);

  // led is off
  ledcWrite(1, 255);
  ledcWrite(2,255);
  ledcWrite(3, 255);
  delay(200);
 }
}

// if wifi is connected, then Blue LED has to glow
void wifi_connect_led()
{
  ledcWrite(1, 255);
  ledcWrite(2,255);
  ledcWrite(3, 0);
  delay(1000);
}

// if wifi is dis-connected, then Orange LED has to glow
void wifi_disconnect_led()
{
  ledcWrite(1, 30);
  ledcWrite(2,10);
  ledcWrite(3, 255);
  delay(1000);
}

void data_sent()//light green
{
  ledcWrite(1, 200);
  ledcWrite(2,50);
  ledcWrite(3,100);
  delay(1000);
}

void data_notsent()
{
  ledcWrite(1, 100);
  ledcWrite(2,255);
  ledcWrite(3, 30);
  delay(1000);
}