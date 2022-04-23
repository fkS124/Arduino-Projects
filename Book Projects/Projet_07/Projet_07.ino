int keyVal;
int notes[] = {175, 145, 167, 131};
String names[4] = {"fa", "mi", "ré", "do"};



void setup() {
 Serial.begin(9600);

}

void loop() {
  keyVal = analogRead(A0);

  if (keyVal == 0) {
    noTone(8);
  }
  else if (keyVal == 1023) {
    tone(8, notes[0]);
    Serial.println(names[0]);
  }
  else if (510 <= keyVal && keyVal <= 512) {
    tone(8, notes[1]);
    Serial.println(names[1]);
  }
  else if (921 <= keyVal && keyVal <= 931) {
    tone(8, notes[2]);
    Serial.println(names[2]);
  }
  else if (969 <= keyVal && keyVal <=  971) {
    tone(8, notes[3]);
    Serial.println(names[3]);
  }
  else {
    noTone(8);
  }
}
