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
#include <string>
#include <time.h>
#include <ESP8266HTTPClient.h>

/* ------------------------------- Variables ------------------------------- */

// /!\ Too many constants can make the program fail with no clue about it

// MQTT topics
const char* LOG = "/home/log"; // Here we will publish status updates
const char* LIGHTS = "/home/lights"; // Here we will read commands

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
void getTime(/*char* time*/);

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
  if(strcmp(topic, LIGHTS) == 0)  // Validation in case we subscribe multiple topics
    if ((char)payload[0] == '0' && digitalRead(outputPin)){
      digitalWrite(outputPin, LOW);
      client.publish(LOG, "Turning ligths off");
      getTime();
    }else if((char)payload[0] == '1' && !digitalRead(outputPin)){
      digitalWrite(outputPin, HIGH);
      client.publish(LOG, "Turning ligths on");
    }
}


/* Gets the current time by http */
void getTime(char* ret){
  HTTPClient timeClient;
  timeClient.begin("http://www.convert-unix-time.com/api?timestamp=now&timezone=Madrid&returnType=rss");
  int httpCode = timeClient.GET();

        if(httpCode > 0) {
            if(httpCode == HTTP_CODE_OK) {
                String payload = timeClient.getString();

                char times[95];
                strncpy(times, payload.c_str(), sizeof(times));
                memcpy(times, &times[80], 10 );
                times[10] = 0;
                time_t epch = atoi(times);

                //client.publish(LOG, asctime(gmtime(&epch)));
            }
        } else
          client.publish(LOG, "Error while getting time from API.");
}
