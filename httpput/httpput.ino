#define PIN 32

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>


 
const char* ssid = "NETGEAR_IOT";
//const char* password =  "yourNetworkPassword";
const int volts = analogReadMilliVolts(PIN);

WiFiServer server(80);

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;


 void setup() {
  Serial.begin(115200);

  pinMode(PIN,ANALOG);
   
  
  delay(4000);   //Delay needed before calling the WiFi.begin
 
  WiFi.begin(ssid); 
    Serial.println("Connecting to WiFi..");
 
 
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(500);
      Serial.print(".");
 
   }

  
  Serial.println("");
  Serial.printf("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
}



//
// void setup() {
//  Serial.begin(115200);
//  pinMode(PIN, ANALOG);
//  WiFi.begin(ssid);
//
//  Serial.println("connecting:");
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//}
void loop() {
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
    //settings
   HTTPClient http;   
   WiFiClient client = server.available();

   http.begin("https://a7b2-153-156-28-29.jp.ngrok.io/api/v1/temp");  //HTTP server connect address
   http.addHeader("Content-Type", "application/json");                //Specify content-type header > needs Json→application/json
  

      
   StaticJsonDocument<JSON_OBJECT_SIZE(1)> json_array;
    char json_string[255];

      const float temp = volts * (165.0 / 4096) * (4.096 / 5);

    //json_array["id"]
    json_array["temp"]=temp;
   // json_array["timestamp"]

    
  
    Serial.printf("%f\n", temp);
  
   
    if ((millis() - lastTime) > timerDelay){
      //send post request every 10 sec

      serializeJson(json_array, json_string, sizeof(json_string));
      int status_code = http.POST((uint8_t *)json_string, strlen(json_string)); 

     // int httpResponseCode = http.POST(json_string);   //Send the actual POST request
      
    }else{
      return;
      Serial.printf("request data not updated");
    }
   


   http.end();  //Free resources
  delay(10000);  //Send a request every 10 seconds
 
   }else{
 
    Serial.print("Error on sending POST: ");
 
   }
 
}
