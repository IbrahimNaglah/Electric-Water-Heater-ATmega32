# Electric-Water-Heater-ATmega32

**You can find the following Schematic in Simulation_Proteus Folder:**
![image](https://github.com/IbrahimNaglah/Electric-Water-Heater-ATmega32/assets/101402062/4a56a21e-3464-4b8f-9a8e-ad80736ca39a)


## How System Works (Simulation)
![System Flowchart](https://private-user-images.githubusercontent.com/101402062/293686806-9de1840b-7bc1-4548-94e5-44e4d2f5b4c7.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MDQxOTY5NzgsIm5iZiI6MTcwNDE5NjY3OCwicGF0aCI6Ii8xMDE0MDIwNjIvMjkzNjg2ODA2LTlkZTE4NDBiLTdiYzEtNDU0OC05NGU1LTQ0ZTRkMmY1YjRjNy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwMTAyJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDEwMlQxMTU3NThaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04ZGU1Mjc2MTA1OGVjMzExNTllMWEzNGYzYTkyNDdhMGYxZjVkNDA3MzJhNGU4ODEyZGFlMWYxNjc1ZTRlMzE4JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.8AIeNFAoAuw-JOG84tnrUgja18LznpKNZz41hbOkAuQ)

<p> The microcontroller used in the project is the Atmega32, categorized in the AVR Family. It controls the entire system and dictates how the system responds to various actions.</p>

<p> To read temperature sensor we need ADC, The Analog-to-Digital Converter (ADC) measures analog signals from a temperature sensor, converting them into digital values. These values are then processed in microcontroller and displayed on a 7-Segment display to showcase the temperature in a readable format and Current value displayed is the Current temperature value. </p>

<p>The Control Buttons section allows for the adjustment of the desired temperature setting and facilitates the system's power control by resetting the Microcontroller. The UP button increases the set temperature, while the DOWN button decreases it.</p>
<p>Whenever the temperature is set, the data is stored in an external storage device known as EEPROM. Based on the most recent temperature setting, the cooling or heating elements will respond accordingly to regulate the water temperature.</p>
