#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
 
const char* ssid = "NETGEAR_IOT";
//const char* password =  "yourPassword";
 
void setup() {
 
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin("http://jsonplaceholder.typicode.com/comments?id=10"); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
      String payload = http.getString();

      StaticJsonBuffer<500> JSONBuffer; //Memory pool
     
      JsonArray &root = JSONBuffer.parseArray(payload);
      for(int i=0; i<root.size(); i++) {
        JsonObject& parsed = root[i];
        const char * id = parsed["id"];
        const char * te[mp = parsed["temp"]; 
     

        Serial.println(httpCode);
  
        Serial.print("id: "); Serial.println(id);
        Serial.print("temp : "); Serial.println(temp);
     
        Serial.println("------------------------------");
        Serial.println();
      }
    }
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(10000);
 
}
