#include "DHTesp.h" // Click here to get the library: http://librarymanager/All#DHTesp

DHTesp dht;

void setup()
{
  Serial.begin(115200); // Afficher les données à ce port
  Serial.println();
  Serial.println("Statut\tHumidité (%)\tTémperature (C)\t(F)");

  dht.setup(2, DHTesp::DHT11); // Correspond au connecteur D4, voir <https://community.blynk.cc/uploads/default/original/2X/a/ad21775ddd04bb9049994cb2a4ecfd5828cbf6d6.PNG>
  // le DHT11 précise le capteur que l'on prend (j'aurais pu avoir pris un DHT22)
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());

  float humidite = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidite, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);

  delay(2000);
}
