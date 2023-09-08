

void setup() {
  Serial.begin(19200);
  //D3-D10 from IR Sensor
  // pinMode(0, INPUT);
  // pinMode(1, INPUT);
  // pinMode(2, INPUT);
  // pinMode(3, INPUT);
  // pinMode(4, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  // pinMode(7,INPUT);
}

void loop() {

  Serial.print(analogRead(0));
  Serial.print(" ; ");
  Serial.print(analogRead(1));
  Serial.print(" ; ");
  Serial.print(analogRead(2));
  Serial.print(" ; ");
  Serial.print(analogRead(3));
  Serial.print(" ; ");
  Serial.print(analogRead(4));
  Serial.print(" ; ");
  Serial.print(analogRead(5));
  Serial.print(" ; ");
  Serial.print(analogRead(6));
  // Serial.print(" ; ");
  //   Serial.print(analogRead(7));
  Serial.println();
  // digitalWrite(4, HIGH);
  // digitalWrite(3, LOW);

  // digitalWrite(10, HIGH);
  // digitalWrite(9, LOW);
  //motor();
}

void motor() {
  Serial.println("Hello");
}
