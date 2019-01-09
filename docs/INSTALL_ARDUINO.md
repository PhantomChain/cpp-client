

# Arduino Builds


### requirements:

**Arduino IDE:**  
Download and install the Arduino IDE (>=1.8.5) from the following link:  
```https://www.arduino.cc/en/Main/Software```

#

### dependencies:

Using the Arduino IDE's built in Library Manager,  
install the following Libraries  
- ArduinoJson v5.13.2
- AUnit

#

### Using with the Arduino IDE
> include the following header in your Arduino Sketch:  
```cpp
#include <phantomClient.h>
```

#

### Arduino Example using the Adafruit Feather ESP8266

```cpp
#include <phantomClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "your_network";
const char* password = "your_password";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.print("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());

  Phantom::Client::Connection<Phantom::Client::API::Two> connection(CustomNetwork);

  Serial.println(phantomClient.blocks.all().c_str());
  Serial.println();
  
  Serial.println(phantomClient.delegates.all().c_str());
  Serial.println();
  
  Serial.println(phantomClient.delegates.count().c_str());
  Serial.println();
  
  Serial.println(phantomClient.peers.all().c_str());
  Serial.println();
  
  Serial.println(phantomClient.transactions.all().c_str());
  Serial.println();

}

void loop() {}
```
