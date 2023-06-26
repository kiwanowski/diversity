#include <Audio.h>

AudioInputI2S            i2s2;           //xy=201,202
AudioOutputI2S           i2s1;           //xy=664,214
AudioConnection          patchCord1(i2s2, 0, i2s1, 0);
AudioConnection          patchCord2(i2s2, 1, i2s1, 1);

void setup() {
  AudioMemory(12);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
