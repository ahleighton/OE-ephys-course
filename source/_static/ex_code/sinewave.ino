// Simple DAC sine wave test, 7Hz
 
float phase = 0.0;
float twopi = 3.14159 * 2;
elapsedMicros usec = 0;
float pin = A14;
 
void setup() {
  analogWriteResolution(12);
}
 
void loop() {
  float val = sin(phase) * 2000.0 + 2050.0;
  analogWrite(pin, (int)val);
  phase = phase + 0.02;
  if (phase >= twopi) phase = 0;
  while (usec < 500) ; // wait
  usec = usec - 500;
}
