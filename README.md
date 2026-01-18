# Liquid Crystal Display 16x2

## Finding the Address
Scanned the address for the LCD and received 0x27 (default address)
<details>
<summary>Code</summary>

```C
#include <Arduino.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


void setup()
{
  Wire.begin();
  Serial.begin(115200);
  while (!Serial);
  Serial.println("\nI2C Scanner");

}

void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("\nScanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknow error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }
  delay(5000);
}
```
</details>

## Getting Started
In order to operate the LCD, I installed the LiquidCrystal_I2C .zip file from the Random Nerd Tutorials website and extracted the files to the builtin Arduino Framework in PlatformIO. From here, I followed the tutorial on how to display "Hello, World!" on the top and bottom row of the display.

### Process
I ran into some issue at the beginning when attempting to build and upload my code to the board. The first issue was not secifying with dependancy to use within the library so that the system would not be working to include every dependancy that was not necessary.

The second issue I ran into was that my serial port could not be found despite my computer being able to locate it. After troubleshooting, I instead allowed PlatformIO to auto detect the port, but there was a tradeoff. Even though I could now upload the sketch, the serial monior would not show the message being loaded. I ended up switching from the USB port to the UART port on my dev board to fix the issue. 

The third issue, which was not really an issue, more so an oversight, was that I believed the upload was not successful because I could not see the text displayed, but this was due to the backlight contrast. This was easily remedied by turning the potentiometer on the LCD shield to increase the contrast.

### Output

**insert images**

## Displaying Scrolling Text
This section is where I display scrolling text on my LCD and my process of doing so.