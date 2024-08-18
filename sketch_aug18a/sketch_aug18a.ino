#include <WiFi.h>
#include <PubSubClient.h>
// #include <BluetoothSerial.h>

// Wi-Fi credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT broker details
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_topic = "sasinduwije1";

// Initialize Bluetooth
// BluetoothSerial SerialBT;

// Initialize Wi-Fi and MQTT client
WiFiClient espClient;
PubSubClient client(espClient);

// Function to connect to Wi-Fi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// Function to connect to the MQTT broker
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize Bluetooth
  // SerialBT.begin("ESP32_BT");
  Serial.println("The device started, now you can pair it with Bluetooth!");

  // Connect to Wi-Fi
  setup_wifi();

  // Set MQTT server
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (Serial.available()) {
    // String receivedData = SerialBT.readStringUntil('\n');
    String receivedData = Serial.readln();
    int receivedInt = receivedData.toInt();
    Serial.print("Received integer: ");
    Serial.println(receivedInt);

    // // Publish to MQTT
    // String payload = String(receivedInt);
    // client.publish(mqtt_topic, payload.c_str());
    // Serial.println("Integer published to MQTT");
  }
}
