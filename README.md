# RFID Attendance System with LCD Greetings and Excel Logging

A microcontroller-based RFID attendance tracking system that records check-ins and check-outs with personalized greetings, buzzer confirmation, and Excel logging.

## Features
- **RFID card detection** using the MFRC522 module.
- **Personalized greetings** on the LCD:
  - First scan: "Welcome to class!"
  - Second scan: "Goodbye!"
- **Excel integration** via serial communication using PLX-DAQ (Parallax Data Acquisition Tool) or similar tools.
- **Audio feedback** using a buzzer.
- **Time and date logging** in an Excel sheet with a "Greeting" column and a "Student State" column to describe the first scan as "IN CLASS" and the second scan as "OUT OF CLASS".

## Components Used
- Arduino Uno (or compatible board)
- MFRC522 RFID Reader
- RFID Tags/Cards
- 16x2 LCD Display
- Buzzer
- Jumper wires
- Breadboard
- Resistors (220Ω & 1KΩ for LCD)


## Schematic Design
<img src=https://github.com/SewarYousef/AttendanceSheetSystem/blob/3ed825f7cf73e9bd50f4dfe09c0f561264050650/Diagram.png align="center" height="500" width="650"/>

## Example Sheet 
<img src=https://github.com/SewarYousef/AttendanceSheetSystem/blob/b99bf5b0b3375fe8142f9a893bbe63e0fe258ec6/Example%20Sheet.png align="center" height="500" width="650"/>
