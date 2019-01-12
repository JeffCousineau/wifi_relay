# wifi_relay
Web server for NodeMCU (esp8266) to control a relay. Can receive POST request from an IFTTT applet.
V1 : simple web interface with a button to trigger your relay for 5 seconds.
V2 : 

## Configuration
* V1 : Set your SSID and your PASSWORD
```
const char* ssid     = "";    
const char* password = "";
```
* V2 : also set an API key for more security
```
const char* api_key = "";
```

## Usage
* When uploading your project to your NodeMCU, note the IP adress using the Arduino IDE serial monitor. If you don't get an IP adress, it means your NodeMCU can't connect to your wifi, verify your credentials and make sure your on 2.4gHz.    

* **V1** : To use your web server on your local network, you simply need to open the ip adress on your cellphone or your computer. If you want to use it outside your network, you need to port forward on your router and then you will need to use your external ip which can be found using https://www.whatismyip.com.    

* **V2**    
  * First, port forward your ip on your router to access the web server from outside your network.  
  * Install IFTTT on your cellphone. This will let you make a POST request to your server by simply using a button on your cellphone.
  * Add a new service, IF : button press, THEN : webhooks
  * The same technique can be use to trigger a POST request with a voice command using your google home.

# References
* https://techtutorialsx.com/2016/10/22/esp8266-webserver-getting-query-parameters/
