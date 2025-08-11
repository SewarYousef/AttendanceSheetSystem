# RFID Attendance System with LCD Greetings and Excel Logging

A microcontroller-based RFID attendance tracking system that records check-ins and check-outs with personalized greetings, buzzer confirmation, and Excel logging.

## ✨ Features
- **RFID card detection** using the MFRC522 module.
- **Personalized greetings** on the LCD:
  - First scan: "Welcome to class!"
  - Second scan: "Goodbye!"
- **Excel integration** via serial communication using PLX-DAQ or similar tools.
- **Visual and audio feedback** using LEDs and a buzzer.
- **Time and date logging** in an Excel sheet with a "Greeting" column.

## 🛠 Components Used
- Arduino Uno (or compatible board)
- MFRC522 RFID Reader
- RFID Tags/Cards
- 16x2 LCD Display
- Buzzer
- Red and Green LEDs
- Jumper wires
- Breadboard
- Resistors (220Ω for LEDs)
