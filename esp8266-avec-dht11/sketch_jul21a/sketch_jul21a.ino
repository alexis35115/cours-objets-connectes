#include "DHTesp.h" // Click here to get the library: http://librarymanager/All#DHTesp

DHTesp dht;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello, world!");
  display.display(); 

  Serial.begin(115200); // Afficher les données à ce port
  Serial.println();
  Serial.println("Statut\tHumidité (%)\tTémperature (C)\t(F)");

  dht.setup(2, DHTesp::DHT11); // Correspond au connecteur D4, voir <https://community.blynk.cc/uploads/default/original/2X/a/ad21775ddd04bb9049994cb2a4ecfd5828cbf6d6.PNG>
  // le DHT11 précise le capteur que l'on prend (j'aurais pu avoir pris un DHT22)
}

void loop() {

  delay(dht.getMinimumSamplingPeriod());

  float humidite = dht.getHumidity();
  float temperature = dht.getTemperature();

  display.clearDisplay();
  display.setCursor(0, 10);

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidite, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);

  display.print("Status : ");
  display.println(dht.getStatusString());

  display.print("Temperature : ");
  display.print(temperature, 1);
  display.println(" C");

  display.print(F("Humidite : "));
  display.print(humidite, 1);
  display.println(" %");
  
  display.display();

  delay(2000);
}
