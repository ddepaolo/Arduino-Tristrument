int trig = 10;
int echo = 11;
long duration;
long distance;
int force;
void setup() {
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);
Serial.begin(9600);
}
void loop() {
digitalWrite(trig, LOW); //triggers on/off and then reads data
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
distance = (duration / 2) * .0344; //344 m/s = speed of sound. We're converting into cm
int notes[7] = {261, 294, 329, 349, 392, 440, 494}; //Putting several notes in an array
// mid C D E F G A B
force = analogRead(A0); //defining force as FSR data
if (distance < 0 || distance > 50 || force < 100) { //if not presed and not in front
noTone(12); //dont play music
}
else if ((force > 100)) { //if pressed
int sound = map(distance, 0, 50, 0, 6); //map distance to the array of notes
tone(12, notes[sound]); //call a certain note depending on distance
}
}
