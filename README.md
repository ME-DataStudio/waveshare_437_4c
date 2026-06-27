# waveshare 4.37in 4 colour (G)
Driving ePaper display 4.37inch 4 colours with ESP32.
1. Arduino -> with GxEPD2 library.
    Based on the work of https://github.com/alexander-toch ESP8266 ePaper Weather Dashboard - battery-driven:
    - ESP32 S3 (UM feathers3
    - waveshare 4.37 inch 4 color epaper with driver board, model G
    Which is in turn is Inspired by Weatherman Dashboard for ESPHome. Implemented Partial display refresh for nicer appearance and Deep Sleep for longer battery life time.
3. ESPhome -> waveshare 4.37in 4 colour is not supported in spi-epaper or waveshare-epaper. Some result with spectra-e6 model but very shake (when driver board is cold it works when it warms up it does not. I posted the YAML here for others who maybe find a wat

