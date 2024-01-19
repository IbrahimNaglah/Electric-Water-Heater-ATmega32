# Electric-Water-Heater-ATmega32

**You can find the following Schematic in Simulation_Proteus Folder:**
![image](https://github.com/IbrahimNaglah/Electric-Water-Heater-ATmega32/assets/101402062/4a56a21e-3464-4b8f-9a8e-ad80736ca39a)


## How System Works (Simulation)
![image](https://github.com/IbrahimNaglah/Electric-Water-Heater-ATmega32/assets/101402062/a45d7900-24d6-47b1-bc5a-869319d8dd79)


<p> The microcontroller used in the project is the Atmega32, categorized in the AVR Family. It controls the entire system and dictates how the system responds to various actions.</p>

<p> To read temperature sensor we need ADC, The Analog-to-Digital Converter (ADC) measures analog signals from a temperature sensor, converting them into digital values. These values are then processed in microcontroller and displayed on a 7-Segment display to showcase the temperature in a readable format and Current value displayed is the Current temperature value. </p>

<p>The Control Buttons section allows for the adjustment of the desired temperature setting and facilitates the system's power control by resetting the Microcontroller. The UP button increases the set temperature, while the DOWN button decreases it.</p>
<p>Whenever the temperature is set, the data is stored in an external storage device known as EEPROM. Based on the most recent temperature setting, the cooling or heating elements will respond accordingly to regulate the water temperature.</p>
