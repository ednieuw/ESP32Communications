# ESP32 Communications template (Readme is in progress)
A template sketch to connect WIFI, get NTP, WPS, OTA, SoftAP, DNS, HTML & BLE UART menu, HTML page menu, HTML serial monitor and control with IR-remote control, rotary encoder or keypad and WS2812 RGB or SK6812 RGBW LED strips.
The sketch is developed on a Arduino Nano ESP32 which is a ESP32-S3.

This is a basic sketch for a ESP32 connected with an LDR, a rotary, or three button membrane switch, or IR-remote controler and a DS3231 RTC-module. The DS3231 is for use when no WIFI is available and an accurate time in needed.

The sketch is a spin-off from the Arduino Nano ESP32 word clock. This sketch has been stripped from the word clock specifics and can be used for all kind of developments where WIFI , BLE, Serial input and output is needed.

With a small or a larger Fritzing PCB design, PCB's [can be ordered from PCBway](https://www.pcbway.com) for less than €10. They are designed for an Arduino Nano ESP32. 

The microcontroller can be controlled with 
- a BLE serial terminal program on your PC like the serial monitor of the Arduino IDE,
- a tablet or phone with a serial terminal app like: [BLE serial terminal](https://ednieuw.home.xs4all.nl/BLESerial/IOSappMain.html) or
- with a HTML page.

A software-enabled access point is created on your browser that can be accessed with the url: http://169.4.1.1 to set up and configure the WIFI SSID and password to your router through a smartphone or web browser.

There is also a WPS method that can be started with option Z in the menu.

<img width="800" alt="image" src="https://github.com/user-attachments/assets/960cc1ec-c4db-4e78-b8f7-7657d71cef14" />

With an Over the air (OTA) connection .bin software updates can be loaded. 

An unique Bluetooth station name given to the device in the menu of the device is also shown in your router.

Settings are stored permanently in the ESP32.

Start up logging in the Arduino IDE Serial monitor
```
Serial started
Stored settings loaded
LED strip started
Found I2C address: 0X57
Found I2C address: 0X68
External RTC module IS found
DS3231 RTC started
BLE started
Starting WIFI/NTP
[WiFi] WiFi is disconnected, will reconnect
WiFi lost connection.
[WiFi] WiFi is disconnected, will reconnect
Connected to access point
Connected to : FRITZ!BoxEd
Obtained IP address: 192.168.178.49
IP Address: 192.168.178.49
NTP is On and synced
___________________________________
I Menu, II long menu
K LDR reads/sec toggle On/Off
N Display off between Nhhhh (N2208)
R Reset settings
@ = Restart
___________________________________
Slope: 50     Min: 5     Max: 255 
BLE name: WordClock
IP-address: 192.168.178.49/update
WIFI=On NTP=On BLE=On FastBLE=Off
31/05/2025 15:55:31 
___________________________________
Web page started
WIFI started
31/05/2025 15:55:31
```
The software can be used on this PCB: [small PCB](https://github.com/ednieuw/ESP32Communications/tree/main/PCBdesigns). <br>
Fritzing design with Gerber files in this repository.  
Five PCB's [can be ordered from **PCBway**](https://www.pcbway.com) for ~25€ / $. 

![V02 Small Nano ESP32-3D](https://github.com/user-attachments/assets/6a37ebcb-5f9a-473c-9b27-9e47973a8ea1)
