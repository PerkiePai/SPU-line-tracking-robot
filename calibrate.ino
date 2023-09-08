void calibratewhite() {
  Serial.println("Waiting For White");
  while (1) {
    if (analogRead(0) > smid) {
      break;
    }
    for (int i = 0; i < 8; i++) {
      smin[i] = min(smin[i], analogRead(i));
    }
  }
}

void calibrateblack() {
  Serial.println("Waiting For Black");
  while (1) {
    if (analogRead(0) < smid) {
      break;
    }

    for (int i = 0; i < 8; i++) {
      smax[i] = max(smax[i], analogRead(i));
    }
  }
}

int sensor_read(int i) {
  int smean = constrain((analogRead(i) - smin[i]) / ((smax[i] - smin[i]) / 50) - 25, 0, 20); //min 0, max 20
  return -smean + 20;
}

void sensor_test() {
  while (1) {
    for (int i = 0; i < 8  ; i++) {
      Serial.print(i);
      
      Serial.print(" ");
      Serial.print(sensor_read(i));
      //Serial.print(sensor_read(i));
      if (i != -1) Serial.print(", ");
    }
    Serial.println();
  }
}
