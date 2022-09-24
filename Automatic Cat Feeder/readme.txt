-Components (refer to the components.jpeg inside the images folder):

  -BODY-
  a. 4.7 lt plastic container with snaplock lid
  b. 1.5 lt plastic bottle with a large lid (to allow the flow of kibbles and the motion of the mixer)
  c. 1 lt plastic bottle (for the outside of the container, otherwise the kibbles scatter everywhere)
  d. A metal jar lid (for the lid of the kibble container)
  e. Some Lego parts for the mixer (these are LEGO Technic pieces):
  	9M beams (x2) (to keep the mixer in place)
  	Axles of varying lengths (X4) (X-shaped sticks)
	Connectors with axles holes (x3)
	Several gears of varying radiuses (x4-6)
	Several bushes (to prevent the gears from moving)

  -ELECTRONICS-
  f. Arduino UNO
  g. 360 degrees mini servo (for mixing the kibbles)
  h. Mini servo (for the lid, therefore 90 degrees is sufficient)
  i. 1602A 16x2 LCD with I2C/IIC chip (this chip reduces the number of cables to connect to the Arduino from 12 to 4)
  j. A breadboard (I also used a mini breadboard to separate the LEDs and the button, but it's not essential)
  k. Push button (to pour down a portion of kibbles and reset the timer)
  l. 1 green LED and 1 blue LED (blue = the feeder is on, green = reset/kibble pour down)

  Jumper cables
  12V charger for the DC Barrel Plug

  -OTHERS-
  Drill (to drill holes into the container, you can use whatever you want for this purpose)
  Hot-glue gun (to glue the LCD, the servos and the bottles to the container -also the mixer to the 360 servo)


-Notes:

  Take a look at the images inside the images folder.

  Lid Servo:
  I used a 180 degrees servo for the lid. Depending on what you use, you might need to change the position variables inside the code.

  LEGO Mixer:
  The reason I added a mixer component: After a while, the kibbles started clumping at the mouth of the bottle and stopped pouring down.   To prevent this from happening, I added a mixer.
  You can try making this component by getting creative, you don't need LEGO parts.

  !!! Placing the mixer inside the bottle is a HASSLE. After gluing the bottle to the container you might not be able to change the  pieces. Plan before putting everything together and make sure everything fits, do not make the mistakes I   did :')

  Timer:
  I feed my cat every 6 hours, so I set the time between feedings to 21600 seconds. You can change this time in the setup and inside the turnServo() function.

  1620A LCD with I2C:
  I used this https://create.arduino.cc/projecthub/akshayjoseph666/interface-i2c-16x2-lcd-with-arduino-uno-just-4-wires-273b24 guide, the necessary library (LiquidCrystal_I2C) is included inside the guide.

  Serving Size:
  Increase/decrease the number of iterations inside turnServo() function to adjust serving size.

  Other:
  You can ignore the battery holder, I ended up not using it.


-PINS:

  Blue LED: D6
  Green LED: D7
  Push Button: D8
  Lid Servo: D9
  Mixer Servo (360 degrees): D10
  LCD SCL: A5
  LCD SDA: A4
