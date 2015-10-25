###Example-01 - Each core blinks an LED

####Decription
Totally there are 4 LED's used in this example.
3 of them is connected to the GPIO pins from the expansion header of Raspberry Pi2
The pending one LED is the ACT LED(i.e the Green LED) on the Raspberry Pi PCB

It recommeneded to connect the 3 LED's to breadboard and wore them accordingly to understand the example well. But if you don't have the additional 3 LED's, breadboard and wires, the ACT LED on the PCB would blink.

####Video
Before you try this, see the video - https://www.youtube.com/watch?v=lLHOH9A4hoU

<iframe width="560" height="315" src="https://www.youtube.com/embed/lLHOH9A4hoU" frameborder="0" allowfullscreen></iframe>

####Circuit Diagram
3 LED's are connected via individual 330Ohm resistors to the ground.

LEDs are coonected to the following GPIO's - GPIO16, GPIO20, GPIO21

Below breadboard and schematic is drawn using http://fritzing.org/

![Breadboard wiring](https://github.com/jeffreyantony/multipi/blob/master/Example_01/doc/3LED_BreadBoard.png)

Schematic
![Schematic wiring](https://github.com/jeffreyantony/multipi/blob/master/Example_01/doc/3LED_schem.png)


