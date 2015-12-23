# Description
I wanted to have a remote controlled RGB light because my baby daughter likes to look at the lights in our house and the color (yellow for morning/day, blue for evening/night) has given her a routine.
I could have got a Philips Hue but I wouldn't have learned anything in the process.
I decided to build a very basic WiFi controlled RGB LED lamp using a string of 8 WS2812 and an ESP8266.

# Implementation
## Hardware
The hardware uses a ESP8266-01, a 3.3V linear regulator (L4931CZ33), some decoupling capacitors and a string of 8 WS2812 LEDs.
Everything is housed in a white paper lantern using an old tape reel box. Power is coming from a 5V/2.4A wall adapter.

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

I developped the Javascript code separately from the ESP code. You can find it in the file *colorwheel.html*.
The html file is converted into a C "header" file via the following command:

```bash
cat colorwheel.html  | sed -e "s/\"/'/g" | sed -e '/^\s*$/d' | sed -e 's/.*/\"&\"/g' > colorwheel.h
```
The resulting file is then copied as *html_header.h* and the following is added at the begining to make it a constant definition:

```c
const char* html_header =
```
A semicolon has to be added at the end.

This is the user interface as displayed in Safari on an iPhone:

<img alt="red lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/UI.PNG" width="300">

# Assembly
The ESP8266 is connected to a small piece of prototyping board via a 2 rows of 4 pins connector. The board houses the regulator and the two decoupling capacitors. The 8 WS2812 come preassembled on a PCB. Wires are soldered directly on the PCB to connect it to the prototyping board.
The base (an old tape reel box) has few holes drilled into it to accecpt the screws to attach the lantern, the prototyping board and the LED string. Once the electronics is assembled it looks like that:

<img alt="red lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/TopView.jpg" width="300">

There is a big slot to allow the lantern holder to sit in.
The lantern is attached using two screws+nuts and these special toothed washers (can't remeber where I found them):

<img alt="red lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/LanternFasteners.jpg" width="300">

Lantern attached but not expanded:

<img alt="red lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/AttachedLantern.jpg" width="300">

At the bottom, I've added a ON/OFF switch and a barrel connector for the power supply:

<img alt="red lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/BottomView.jpg" width="300">

Final product:

<img alt="red lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/ExpandedLantern.jpg" width="300">


# Hello World
This is not a very bright lamp on purpose. Here are three pictures showing how it glows.

<img alt="red lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/red.jpg" height="250">
<img alt="green lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/green.jpg" height="250">
<img alt="blue lantern" src="https://github.com/jmbussat/WS2812_ESP8266/blob/master/Img/blue.jpg" height="250">

# License
![CClogo](https://i.creativecommons.org/l/by/4.0/88x31.png)

This work is licensed under a [Creative Commons Attribution 4.0 International License] (http://creativecommons.org/licenses/by/4.0/)
