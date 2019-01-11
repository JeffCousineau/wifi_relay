#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
ESP8266WebServer server(80);
 
const char* ssid = "YourNetworkName";
const char* password =  "YourNetworkPassword";
const char* api_key = "";

 
void setup() {
 
    Serial.begin(115200);
    WiFi.begin(ssid, password);  //Connect to the WiFi network
 
    while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
 
        delay(500);
        Serial.println("Waiting to connect...");

    }
 
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());  //Print the local IP
 
    server.on("/body", handleBody); //Associate the handler function to the path
    server.on("/api", handleApiArg);   //Associate the handler function to the path
    
    server.begin(); //Start the server
    Serial.println("Server listening");
 
}
 
void loop() {
    server.handleClient(); //Handling of incoming requests
}
 
void handleApiArg() { 

String message = "";

if (server.arg("api-key")== ""){     //Parameter not found
  message = "No API key";
}
else{     //Parameter found
  if (server.arg("api-key") == api_key)
  {
    message = "Door opening...";   
  }
  else
  {
    message = "Wrong API key";
  }
}
server.send(200, “text/plain”, message);          //Returns the HTTP response

}
