#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);
const int channel = 1;

void setup() {
  MIDI.begin();
}

void loop() {
  int note;
  for (note=10; note <= 127; note++) {
    MIDI.sendNoteOn(note, 100, channel);
    delay(200);
    MIDI.sendNoteOff(note, 100, channel);
  }
  delay(2000);
}
