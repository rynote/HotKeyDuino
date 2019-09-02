Starting with this Hackaday.io story:
https://hackaday.com/2012/06/29/turning-an-arduino-into-a-usb-keyboard/

Guide I’m following:
http://mitchtech.net/arduino-usb-hid-keyboard/

Need to setup the DFU installer…
Install MacPorts
https://www.macports.org/install.php#pkg
 
Install the DFU programer:
sudo port install dfu-programmer
 
Gotta short the reset pins… the left pair (closed to the USB port). 
This makes it ready to re-flash. After flashing, then you power cycle.

Installing of the normal firmware.
sudo dfu-programmer atmega16u2 erase
sudo dfu-programmer atmega16u2 flash Arduino-usbserial-uno.hex
sudo dfu-programmer atmega16u2 reset

One liner FLASH UNO FW:
sudo dfu-programmer atmega16u2 erase && sudo dfu-programmer atmega16u2 flash Arduino-usbserial-uno.hex && sudo dfu-programmer atmega16u2 reset

Installing of the USB HID firmware.
sudo dfu-programmer atmega16u2 erase
sudo dfu-programmer atmega16u2 flash --debug 1 Arduino-keyboard-0.3.hex
sudo dfu-programmer atmega16u2 reset

One liner FLASH USB HID FW:
sudo dfu-programmer atmega16u2 erase && sudo dfu-programmer atmega16u2 flash --debug 1 Arduino-keyboard-0.3.hex && sudo dfu-programmer atmega16u2 reset

So, short the pins, erase, flash UNO fw, reset, power cycle.
Load the sketch in the IDE and upload it.
Then short the pins, erase, flash with Arduino-keyboard-0.3.hex , reset , power cycle.   
