# IOT Project :- Smart Water Monitor System
## Overview
The **Smart Water Monnitor System** is an IOT-based project that tracks water usage in real-time using a water flow sensor connected to Arduino.
It detects the **ON/OFF** state of water flow,measures the **flow duration**, calculates **water consumption** in liters/milliliters, and logs a **daily total**.

This project can be used in Homes, Industries and agriculture to monitor and manage water usage efficiently.

## features
Detects **flow ON/OFF** status.
records **Flow duration** for each ON cycle.
Calculates **water volume** in liters and milliliters.
Maintains a **daily total** water usage log.
Outputs data to searial monitor in a structured format.

## components used:-
Arduino UNO
YF-S201 Water flow sensor
Jumper wires
Breadboard

Circuit Connection
| Water Flow Sensor Pin | Arduino Pin |
|-----------------------|-------------|
| VCC                   | 5V          |
| GND                   | GND         |
| Signal (Yellow)       | D2          |

##  How It Works
1. The **flow sensor** sends digital pulses when water flows through it.
2. The Arduino calculates:
   - Start and stop times
   - Flow duration
   - Water consumption (Liters & mL)
3. The system updates the **daily total** and resets every 24 hours.
4. Data is printed to the Serial Monitor for logging or further IoT integration.


##  How to Run
1. Connect the **Arduino** and **flow sensor** as per the wiring diagram.
2. Open `smart_water_monitor.ino` in the **Arduino IDE**.
3. Select your **board** and **COM port**.
4. Upload the code to Arduino.
5. Open the **Serial Monitor** (9600 baud) to view the output.

##Output:-


##  Future Improvements
- Store logs in an **SD card** for offline analysis.
- Send data to a **cloud dashboard** using ESP8266/ESP32 Wi-Fi module.
- Add a **water usage alert system** via SMS or email.

---

##  Author
**Shaik Juveria Tabassum**  
*Created on:* 2023-09-10 

