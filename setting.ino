void set_module() {
  Serial.begin(19200);

  //5-6 for leftMotor
  //9-10 for rightMotor
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < 4; i++) {
    calibratewhite();
    Serial.println("white found");
    calibrateblack();
    Serial.println("black found");
  }
  
  digitalWrite(LED_BUILTIN, HIGH);  //turn built in LED ON after calibration finished
  delay(2000);
}

void motor(int ma, int mb) {
  if (ma > 0) {
    analogWrite(4, 0);
    analogWrite(3, ma);
  } else{
    analogWrite(4, -ma);
    analogWrite(3, 0);
  }
  if (mb > 0) {
    analogWrite(9, 0);
    analogWrite(10, mb);
  } else{
    analogWrite(9, -mb);
    analogWrite(10, 0);
  }
}
