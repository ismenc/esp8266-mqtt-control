/*
 * Made for ESP8266 ESP-12 family. Connects to MQTT broker and listen to
 * 'home/lights' topic. We should post messages starting at '1' or '0' to this
 * topic to make the esp switch the lights state.
 * More info at: https://github.com/ismenc/esp8266-mqtt-control
 *
 * @author: Ismael
 * Made with Atom & PlatformIO
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

/* ------------------------------- Variables ------------------------------- */

// /!\ Too many constants can make the program fail with no clue about it

// MQTT topics
const char* LOG = "/home/log"; // Here we will publish status updates
const char* LIGHTS = "/home/lights"; // Here we will read commands
const char[6] QUESTION = "lights?"

// Fill with your data
const char* ssid = "............";
const char* password = ".................";
const char* mqtt_server = "................";
const int mqtt_port = 9999;
const char* mqtt_user = "..............";
const char* mqtt_pass = "................";
const int outputPin = 14; // D5 = GPIO14

WiFiClient espClient;
PubSubClient client(espClient);

int pinStatus = 0;

// Function prototypes
void setupWifi();
void reconnect();
void handler(char* topic, byte* payload, unsigned int length);
bool compareStringArrays(byte* respuesta, char* cadena);

/* ------------------------------- Program ------------------------------- */

void setup() {
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);

  setupWifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(handler);
  reconnect();
}

void loop() {

  // client.loop checks that connection is openned and keeps it open (pingReq)
  if(!client.loop()){
    reconnect();
  }else{

    // Here we can do logics or posting some info on MQTT
    delay(50);
  }
}

/* ------------------------------- Functions ------------------------------- */

/* Establishes wifi connection */
void setupWifi() {
  delay(10);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(300);
  randomSeed(micros());
}


/* Connects with MQTT broker does basic configuration */
void reconnect() {
  while (!client.connected()) {

    // identifying name, user, password
     if (client.connect("NodeMCU", mqtt_user, mqtt_pass)) {

      // Post an event on 'log' topic
      client.publish(LOG, "NodeMCU connected");

      // Listen to a topic
      client.subscribe(LIGHTS);

    } else {
      delay(10000);
    }
  }
}


/* Handles the messaged posted on subscribed topics -> check setup() */
void handler(char* topic, byte* payload, unsigned int length){

  // Update the output pin status and posting on node topic
  if(strcmp(topic, LIGHTS) == 0){  // Validation in case we subscribe multiple topics
    if ((char)payload[0] == '0' && digitalRead(outputPin)){
      digitalWrite(outputPin, LOW);
      client.publish(LOG, "");
    }else if((char)payload[0] == '1' && !digitalRead(outputPin)){
      digitalWrite(outputPin, HIGH);
      client.publish(LOG, "Turning ligths on");
    }

    // If someone ask for lights status
    if(compareStringArrays(payload, QUESTION, 6)){
      if(digitalRead(outputPin) == true)
        client.publish(LIGHTS, "Status: 1";
      else
        client.publish(LIGHTS, "Status: 0";
    }
  }
}

// Todo can fail because of length function
bool compareStringArrays(byte* respuesta, char[] cadena){
  bool comparation = true;
  int i = 0;
  while( i < strlen(cadena) && comparation == true){
    if((char)respuesta[i] != cadena[i])
      comparation = false;
  }
  return comparation;
}
