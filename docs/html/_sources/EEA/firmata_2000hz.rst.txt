#include <Firmata.h>
byte analogPin;
byte previousPIN[TOTAL_PORTS];  // PIN means PORT for input
byte previousPORT[TOTAL_PORTS];

void outputPort(byte portNumber, byte portValue)
{
  // only send the data when it changes, otherwise you get too many messages!
  if (previousPIN[portNumber] != portValue) {
    Firmata.sendDigitalPort(portNumber, portValue);
    previousPIN[portNumber] = portValue;
  }
}

void setPinModeCallback(byte pin, int mode) {
  if (IS_PIN_DIGITAL(pin)) {
    pinMode(PIN_TO_DIGITAL(pin), mode);
  }
}

void analogWriteCallback(byte pin, int value)
{
 pinMode(pin, OUTPUT);
 analogWrite(pin, value);
}


void digitalWriteCallback(byte port, int value)
{
  byte i;
  byte currentPinValue, previousPinValue;

  if (port < TOTAL_PORTS && value != previousPORT[port]) {
    for (i = 0; i < 8; i++) {
      currentPinValue = (byte) value & (1 << i);
      previousPinValue = previousPORT[port] & (1 << i);
      if (currentPinValue != previousPinValue) {
        digitalWrite(i + (port * 8), currentPinValue);
      }
    }
    previousPORT[port] = value;
  }
}

void setup()
{
 Firmata.setFirmwareVersion(FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION);
 Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
 Firmata.attach(DIGITAL_MESSAGE, digitalWriteCallback);
 Firmata.attach(SET_PIN_MODE, setPinModeCallback);
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
 byte i;

  for (i = 0; i < TOTAL_PORTS; i++) {
    outputPort(i, readPort(i, 0xff));
  }

  while (Firmata.available()) {
    Firmata.processInput();
  }
}
