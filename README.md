# NX-8V2_EEPROM_Reader
NX-8V2 EEPROM Reader (CAT 25640)

This repository contains a small arduino sketch to read the EEPROM used on a Networx NX-8V2 security system. It outputs the data in a HEX/ASCII format.

I created this sketch to determine the access codes for the security system installed in my house.

The offset for the user code is at 0xA04 and is two bytes. The code is in hexidecimal so if you see 12 34 in the hex output then the code is "1234".
