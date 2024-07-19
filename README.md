# Function-generator-using-ESP-32
I have included header files Arduino.h and driver/dac.h for digital to analog conversion. 
I have connected DAC pin which is 25th pin on ESP32 to ADC pin which is 35th pin with male-to-male jumper wire. 
I have defined 3 touch buttons in which button1 is 4th pin of ESP, button2 is 15th pin of ESP, and button3 is 13th pin of ESP. 
I have defined waveform, amp, and freq variables to change waveform, amplitude and frequency respectively. 
I took the 3 buttons as input in the setup loop.
I have defined separate functions for square wave, triangular wave, sawtooth wave and sinusoidal wave in which 
I have used for loop which will increment and prints the values to the serially and we get plot on serial plotter. 
I have defined an update waveform function in which I have given 0 to 3 values to waveform variable in if else statements which will toggle waveform according to variable value.
In the main loop I have defined variables for touchRead function. 
For button1 I have used modulus operator with 4 so that it will give values 0 to 3 and then called the updateWaveform function. 
For button2 I have incremented the amplitude (4 values of amplitude, we can change according to our need). Same I have done for button3 to increment frequency of the waveform. 
