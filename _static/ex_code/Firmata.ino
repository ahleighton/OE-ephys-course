 #include <Firmata.h>
 byte analogPin;
 void analogWriteCallback(byte pin, int value)
{
  pinMode(pin, OUTPUT);
  analogWrite(pin, value);
}
 void setup()
{
  Firmata.setFirmwareVersion(FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
  Firmata.begin();
  delayMicroseconds(1000);
}
 
void loop()
{
  while (Firmata.available()) {
    Firmata.processInput();
  }
  delayMicroseconds(500);
  for (analogPin = 0; analogPin < TOTAL_ANALOG_PINS; analogPin++) {
    Firmata.sendAnalog(analogPin, analogRead(analogPin));
  }
}
