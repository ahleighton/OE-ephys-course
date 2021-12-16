.. _Sinewave:

***********************************
Sinewave
***********************************

// Copy this text to a new sketch in the Arduino software (clear the default 'void loop etc first) and save as Sinewave.ino

.. code-block::

  // Simple DAC sine wave test, 7Hz

  float pin = A14;
  float freq = 5; // [Hz]
  float adc_depth = 12;

  void setup() {
    analogWriteResolution(adc_depth);
  }

  void loop() {
    float curr_time = millis() / 1000.0; // [s]
    float sinusoid = sin(2.0 * PI * freq * curr_time);
    int val = (sinusoid + 1) / 2.0 * pow(2, adc_depth);
    analogWrite(pin, val);
  }
