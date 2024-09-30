# Alcohol Detector with MQ3 Sensor and OLED Display

This project involves building an alcohol detector using an MQ3 gas sensor, an OLED display, and an Arduino Nano. The MQ3 sensor detects alcohol concentration in the air and displays the result on the OLED screen. It can be used in applications like breath analyzers or vehicle safety systems.

## [Watch the YouTube Tutorial](https://youtube.com/shorts/-JExOetwxkM)


## Components Required

- Arduino Nano
- MQ3 Alcohol Sensor
- 0.96" OLED Display (I2C)
- Breadboard
- Jumper wires
- Resistor (220Ω)
- Power supply (USB or 9V battery)

## Circuit Diagram

Below is the connection information:

| Component      | Arduino Pin  |
| -------------- | ------------ |
| MQ3 Sensor VCC | 5V           |
| MQ3 Sensor GND | GND          |
| MQ3 Sensor A0  | A0           |
| OLED VCC       | 5V           |
| OLED GND       | GND          |
| OLED SDA       | A4           |
| OLED SCL       | A5           |

## Libraries Used

1. **Adafruit GFX** - A graphics library for drawing shapes and text.
2. **Adafruit SSD1306** - For controlling the OLED display.

Install these libraries in the Arduino IDE using the Library Manager.

## How It Works
1. The MQ3 sensor detects the concentration of alcohol in the air.
2. The sensor output (analog value) is read by the Arduino Nano.
3. The alcohol concentration is calculated and displayed on the OLED screen.
4. The concentration value is also printed to the Serial Monitor for debugging.

### Notes
- Ensure proper power supply for stable readings.
- The MQ3 sensor takes some time to warm up; allow a few minutes before taking accurate readings.
- The output values are for reference purposes and not to be used as a precise measurement device.
## License
- This project is open-source and free to use for personal and educational purposes.
