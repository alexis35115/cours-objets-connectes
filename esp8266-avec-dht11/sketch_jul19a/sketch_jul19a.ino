#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "COGECO-57830"; //Wifi SSID
const char* password = "<*******>"; //WIFI password
const char* mqtt_server = "alexis35115demohub.azure-devices.net"; //MQTT Broker address
const int mqtt_port = 8883; //MQTT broker port
const char* deviceName = "dthdemo-esp8266";
const char* deviceSAS = "SharedAccessSignature ......";

WiFiClientSecure espClient;
PubSubClient client(espClient);

void setup() {

  Serial.begin(115200); // Afficher les données à ce port

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {

  if (!client.connected()) {
    connect();
  }

  client.loop();

  delay(2000);
}

void setup_wifi() {
  delay(10);
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void connect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String hubUserString=mqtt_server;
    hubUserString+="/";
    hubUserString+=deviceName;

    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(deviceName, hubUserString.c_str(), deviceSAS)) {
      Serial.println("Connected!");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
