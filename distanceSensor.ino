void setup() {
  // put your setup code here, to run once:
  pinMode (9, OUTPUT); //trig
  pinMode (8, INPUT); //echo
  
  Serial.begin(9600); //communication to computer

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (9, LOW); //starts the pin that takes in the sound as off
  delayMicroseconds(2); // need tiny delay if you use regular delay too long incorrect measurement

  //sends a signal to the sensor 
  digitalWrite (9, HIGH);
  delayMicroseconds(10); //keeps sensor on for 10 microseconds for the signal
  digitalWrite (9, LOW);
  
  long duration = pulseIn (8, HIGH); //detects how long for the sound to hit the sensor and back stored in duration variable in long type 
                                     // long stores huge int as the delaymicroseconds counts in ints and becomes huge values
  // distnace = time x speed (time divided by 2 since it goes to sensor and back)
  // sound speed is 0.034
  int distance = (duration / 2) * 0.034;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");

  delay(500); //delay before looping again

}
