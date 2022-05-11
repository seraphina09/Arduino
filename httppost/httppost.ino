#define LED 25

#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
 
const char* ssid = "NETGEAR_IOT";
//const char* password =  "yourNetworkPassword";

WiFiServer server(80);

pinMode(LED, OUTPUT);


void setup() {
 
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin
 
  WiFi.begin(ssid); 
 
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(500);
    Serial.print("Connecting to WiFi..");
    Serial.println(ssid);
  }
 
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());

    server.begin();
 
}
 
void loop() {

 WiFiClient client = server.available();
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;   
 
   http.begin("address");  //Specify destination for HTTP request
   digitalWrite(LED, HIGH);

   
   http.addHeader("Content-Type", "text/plain");            
 
   int httpResponseCode = http.POST("POSTING from ESP32");  
 
     if(httpResponseCode>0){
   
        String response = http.getString();                     
     
        Serial.println(httpResponseCode); 
        Serial.println(response);         
     
     }else{
   
       Serial.print("Error on sending POST: ");
       Serial.println(httpResponseCode);
   
     }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
  client.stop();
  Serial.println("Client Disconnected");
  digitalWrite)(LED, LOW);
  delay(10000);  //Send a request every 10 seconds
 
}
