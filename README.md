# MiniQ Robot Kit v2
## Overview
* Original storepage: [DFRobot](https://www.dfrobot.com/product-555.html)
* Schematic: [Original](https://github.com/Arduinolibrary/DFRobot_MiniQ_2WD_V2.0_ROB0081/blob/master/ROB0081_V2_Schematic.pdf?raw=true), [archive.org](https://web.archive.org/web/20220313234132/https://raw.githubusercontent.com/Arduinolibrary/DFRobot_MiniQ_2WD_V2.0_ROB0081/master/ROB0081_V2_Schematic.pdf) (in case they take it down)
* Arduino Leonardo compatible ATMega 32u4 board

The original storepage has a schematic, some poorly writen sample code and a couple of PDFs explaining said code.

The board has a power on toggle switch and is powered from 4xAA batteries.



## Peripherals
| Peripheral | Pins | Description |
| ---------- | ---- | ----------- |
| 2x Motors  | 5, 6 - PWM; 7, 12 - Direction | Basic motor library included with examples. Direction held HIGH is backwards. |
| 2x Encoders | 0, 1 | Conveniently placed on INT2 and INT3 |
| WS2812 RGB LED | 10 | Library widely available |
| 2x Photosensitive diodes | A5 | Two diodes connected in a voltage divider |
| IR receiver | 17 | Library widely available, used for the bundled IR remote |
| 2x IR LEDs | 8, 13 | Can be used for basic obstacle detection with the IR receiver |
| 3x Buttons | A6 | Three buttons with LEDs connected through a voltage divider | 
| I2C Compass | - | Can be accessed through I2C - Library widely available |
| Buzzer | 16 | Connected through a transistor - can be controlled using PWM |

If you need more information, you can look in the schematics, they are pretty well made.

## Examples
There a few rewritten examples in this repository that include a really simple motor library.

You can open them using PlatformIO but they can be really easily adapted to Arduino IDE.