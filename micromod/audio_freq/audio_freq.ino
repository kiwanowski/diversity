#include <Audio.h>

int freq = 30;

AudioSynthWaveform       waveform1;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(waveform1, 0, i2s1, 0);
AudioConnection          patchCord2(waveform1, 0, i2s1, 1);

void setup() {
  AudioMemory(12);
  waveform1.begin(1, freq, WAVEFORM_SINE);
  
}

void loop() {
  waveform1.frequency(freq);
  freq = freq * 1.1;
  delay(500);
  if (freq > 3500) freq = 10;
}
