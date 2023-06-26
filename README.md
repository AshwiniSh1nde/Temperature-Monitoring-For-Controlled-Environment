# Temperature Monitoring for Controlled Environment

The Temperature Monitoring for Controlled Environment project is designed to monitor and display the temperature in a controlled environment, such as an Electric Vehicle (EV). It utilizes temperature sensors, a keypad, and an LCD display to provide real-time temperature readings and user-defined temperature limits. The system also includes visual indicators and an audible alarm to alert users when the temperature exceeds the specified limits.

## Features

- Real-time temperature monitoring: Displays the current temperature in Celsius on an LCD display.
- User-defined temperature limits: Allows users to set lower and upper temperature limits using a keypad.
- Temperature limit alert: Provides visual and audible alerts when the temperature exceeds the specified limits.
- LCD display: Shows the current temperature, user-defined temperature limits, and status messages.
- Red and green LEDs: Indicate temperature status (green for normal, red for limit exceeded).
- Buzzer: Sounds an alarm when the temperature exceeds the specified limits.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- Temperature sensor (e.g., DS18B20 or NTC thermistor)
- Keypad (e.g., 4x4 membrane keypad)
- LCD display (e.g., 20x4 I2C LCD)
- Red and green LEDs
- Buzzer
- Resistors, jumper wires, and breadboard for circuit connections

## Libraries

The following libraries are used in this project:

- `Wire.h` - for I2C communication with the LCD display.
- `Keypad.h` - for interfacing with the keypad.
- `LiquidCrystal_I2C.h` - for controlling the I2C LCD display.
- `DHT.h` - for reading temperature and humidity (optional, if using DHT sensor).

Make sure to install these libraries in your Arduino IDE before uploading the code.

## Circuit Diagram

Include a circuit diagram or a clear description of the wiring connections between the Arduino and the components used in the project.

## Usage

1. Connect the temperature sensor, keypad, LCD display, LEDs, and buzzer to the Arduino board as per the circuit diagram.
2. Open the Arduino IDE and upload the code to the Arduino board.
3. Open the serial monitor to view the temperature readings and system messages.
4. The LCD display will show the current temperature, user-defined temperature limits, and status messages.
5. Use the keypad to set the lower and upper temperature limits.
6. The system will compare the current temperature with the specified limits and activate the LEDs and buzzer if the temperature exceeds the limits.
7. Monitor the temperature readings and system alerts to ensure the controlled environment remains within the desired temperature range.

## Future Scope

- Implement temperature monitoring and control for critical components in EVs, such as electric motors, power electronics, and charging systems.
- Remote monitoring: Integrate wireless communication to enable remote monitoring of temperature readings and alerts.
- Mobile app integration: Develop a mobile application for real-time temperature monitoring and control.

Feel free to explore and implement additional features and improvements based on your specific requirements and use case.


## Thank You!
