# Description
I wanted to have a remote controlled RGB light because my baby daughter likes to look at the lights in our house and the color (yellow for morning/day, blue for evening/night) has given her a routine.
I could have got a Philips Hue but I wouldn't have learned anything in the process.
I decided to build a very basic WiFi controlled RGB LED lamp using a string of 8 WS2812 and an ESP8266.

# Implementation
## Hardware
The hardware uses a ESP8266-01, a 3.3V linear regulator (L4931CZ33), some decoupling capacitors and a string of 8 WS2812 LEDs.
Everything is housed in a white paper lantern using an old tape spool box. Power is coming from a 5V/2.4A wall adapter.

GPIO0 of the ESP8266 is used to drive the WS2812. 

The ESP is powered under 3.3V using the linear regulator. The WS2812 is powered directly off the 5V.

## Software
The code is written for the arduino interface for the ESP8266 because it provided the fastest idea to working system turnaround.
It is using the following libraries:
  - ESP8266 Web Server
  - Adafruit NeoPixel

The client side uses a HTML5/Javasript based color picker. The HTML code is converted into a C header file that becomes a string of characters constant.

The Javascript code returns the R, G, B components via a form-based interface. I initially started with three sliders to directly control the RGB components but I didn't like the look of it. 

The RGB components are read by the server side code and directly converted into integers that are fed to the WS2812.

# Hello World
This is not a very bright lamp on purpose. Here are three pictures showing how it glows.

(https://github.com/jmbussat/WS2812_ESP8266/Img/red.png)

(https://github.com/jmbussat/WS2812_ESP8266/Img/green.png)

(https://github.com/jmbussat/WS2812_ESP8266/Img/blue.png)

# License
![CClogo](https://i.creativecommons.org/l/by/4.0/88x31.png)

This work is licensed under a [Creative Commons Attribution 4.0 International License] (http://creativecommons.org/licenses/by/4.0/)
