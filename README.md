# ESP32 Communications template
A template sketch to connect WIFI get NTP, WPS, OTA, SoftAP, DNS, HTML & BLE UART menu.
The sketch is developed on a Arduino Nano ESP32 which is a ESP32-S3

This is the basic sketch for a ESP32 connected with an LDR, a rotary or three button membrane switch and a DS3231 RTC-module. The last is for use when no WIFI is available and a accurate time in needed

The program can be controlled with a BLE serial terminal program on your PC, tablet ot phone or with a HTML page.
Asoftware-enabled access point is created on your WIFI  to set up and configure the WIFI SSID and password to your router through a smartphone or web browser.
This is also possible with the BLE serial terminal app or the serial monitor of your IDE

With an Over the air (OTA) connection .bin updates can be loaded.

The Bluetooth name of the device is also shown in your router. 
![menu in a browser](https://github.com/user-attachments/assets/3f36f63e-41ea-4e3b-8fa6-faf5a0c125ef)

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
The software can be used on this PCB:[small PCB](https://github.com/ednieuw/Arduino-ESP32-Nano-Wordclock/tree/main/PCB-small) but it can also be connected via the Arduino pins directly.

![V02 Small Nano ESP32-3D](https://github.com/user-attachments/assets/6a37ebcb-5f9a-473c-9b27-9e47973a8ea1)
