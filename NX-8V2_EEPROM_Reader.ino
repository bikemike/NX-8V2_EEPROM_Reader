#include <SPI.h>
#include <EEPROM_CAT25.h>
#define SS_PIN   10

EEPROM_CAT25 EEPROM(&SPI, SS_PIN, CAT25640);


char buffer[16];
#define BUFFER_SIZE  (sizeof(buffer) / sizeof(uint8_t))

void setup(void)
{
  EEPROM.begin();
  Serial.begin(9600);
}

void loop(void)
{
  while (!Serial); // Wait for serial monitor to connect

  // Initial Read Byte for previously written contents, print to serial monitor
  String ascii;
  Serial.println("Decimal Dump:  ");
  for (size_t i=0; i < 8192; i++) {
	  if (i%32 == 0)
	  {
		  ascii = "";
		  sprintf(buffer,"%08x", i);
		  Serial.print(buffer);
		  Serial.print(": ");
	  }
	  uint8_t read_byte = EEPROM.readByte(i);
	  sprintf(buffer, "%2x ", read_byte);
	  Serial.print(buffer);
	  sprintf(buffer, "%c", read_byte);
	  if (read_byte > 31 && read_byte < 127)
		  ascii += buffer;
	  else
		  ascii += ".";

	  if (i%32 == 31)
	  {
		  Serial.print(" ");
		  Serial.print(ascii);
		  Serial.println();
	  }
  }
  Serial.println();
  while (1);

}
