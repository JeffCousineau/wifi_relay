#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
ESP8266WebServer server(80);
 
const char* ssid = "";
const char* password =  "";
const char* api_key = "";

// Auxiliar variables to store the current output state
String output5State = "off";
// Assign output variables to GPIO pins
const int ledPin = 13;

int door_delay = 4000;
 
void setup() {
 
    Serial.begin(115200);
    WiFi.begin(ssid, password);  //Connect to the WiFi network
    // Initialize the output variables as outputs
    pinMode(ledPin, OUTPUT);
    // Set outputs to LOW
    digitalWrite(ledPin, HIGH);
    while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
 
        delay(500);
        Serial.println("Waiting to connect...");

    }
 
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());  //Print the local IP
 
    server.on("/open", handleOpenArg);   //Associate the handler function to the path
    
    server.begin(); //Start the server
    Serial.println("Server listening");
 
}
 
void loop() {
    server.handleClient(); //Handling of incoming requests
}
 
void handleOpenArg() { 

String message = "";

if (server.arg("api_key")== ""){     //Parameter not found
  message = "No API key";
}
else{     //Parameter found
  if (server.arg("api_key") == api_key)
  {
    if (server.arg("door_delay")!= "")
    {
      door_delay = server.arg("door_delay").toInt();
    }
    else
    {
      door_delay = 4000;
    }
    message = "Door opening...";  
    digitalWrite(ledPin, LOW);
    delay(door_delay);
    digitalWrite(ledPin, HIGH); 
  }
  else
  {
    message = "Wrong API key";
  }
}
server.send(200, "text/plain", message);          //Returns the HTTP response

}
