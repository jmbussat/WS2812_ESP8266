// Basic RGB lamp using WS2812 controlled by a ESP8266-01
// (C) Jean-Marie Bussat - Creative Commons Attribution 4.0 International Public License
#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>
#include "html_header.h"
#include <Adafruit_NeoPixel.h>

// Classic web server on port 80
ESP8266WebServer server(80);

#define NUM_PIX 8

const char* password = "YourNetworkPassword";
const char* ssid     = "YourNetworkSSID";
unsigned char red,green,blue;
String form;

// Number of pixels, pin used to control
// NEO_KHZ800 because we are using WS2812 leds
// NEO_GRB because WS2812 wants pixel data in GRB order
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIX, 0, NEO_GRB + NEO_KHZ800);

// Root handler: basic web page with link to settings page
void handle_root() {
  server.send(200, "text/plain", "WS2812 WiFi <a href='./out'>Control</a>");
  delay(100);
}

// Output handler: display colorwheel and allow picking a color
void handle_outputs() {
  // Strings to strore the client output
  String RMsg;
  String GMsg;
  String BMsg;

  // Parse client output
  RMsg=server.arg("R");
  GMsg=server.arg("G"); 
  BMsg=server.arg("B");

  // Convert to number to pass to Neopixel library
  red=RMsg.toInt();
  green=GMsg.toInt(); 
  blue=BMsg.toInt();  

  // Update the form and send it back to the client
  form = "<html>";
  form = form + html_header;
  form = form + "</html>";
  // Send the form
  server.send(200, "text/html", form);
}

// Initialize WiFi, web server and handles
void setup() {
  // Connect to network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  // Default setting for RGB string: dim white
  red=127;
  green=127;
  blue=127;
  // Attach handles to web server
  // Base page
  server.on("/", handle_root);
  // Setting page
  server.on("/out", handle_outputs);
  // Start web server
  server.begin();
  // Initialize Neopixel 
  pixels.begin();
  
}

void loop() {
  int i;
  
  // Process clients requests
  server.handleClient(); 

  // Update the LED string. All LED have same color
  for(i=0;i<NUM_PIX;i++){
    // RGB
    pixels.setPixelColor(i, pixels.Color(red,green,blue));
    pixels.show();
  }
  delay(500);    // Wait a little before trying again
}
