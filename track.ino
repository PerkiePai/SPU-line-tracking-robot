#define kp 10 //  basespeed
#define kd 45           //75
#define ki 3000         //currently zero integrel
#define baseSpeed 255   //210 +10
#define baseSpeed2 150  //150
#define slowspeed 130


float positionalRead;

void track1() {
  while (1) {
    positionalRead = positional();

    error = positionalRead - 40;
    Serial.println(error);

    if (sensor_read(0) >= 18 && sensor_read(1) >= 18 && sensor_read(2) >= 18 && sensor_read(3) >= 18 && sensor_read(4) >= 18 && sensor_read(5) >= 18 && sensor_read(6) >= 18) {
      break;  // default is 275
    } else if (sensor_read(0) < 16 && sensor_read(1) < 16 && sensor_read(2) < 16 && sensor_read(3) < 16 && sensor_read(4) < 16 && sensor_read(5) < 16 && sensor_read(6) < 16) {

      if (diff == 1) {
        motor(220, -167);
      } else if (diff == 2) {
        motor(-167, 220);
      }


    } else {

      if (sensor_read(0) >= 5 || sensor_read(1) >= 5) {
        diff = 1;
      } else if (sensor_read(5) >= 5 || sensor_read(6) >= 5) {
        diff = 2;
      }

      //integrel = error + integrel;
      integrel = 0;
      motorspeed = (error * kp) + ((error - last_error) * kd);  //+ (integrel / ki);
      last_error = error;
      Serial.println(error);
      motor(constrain(baseSpeed - motorspeed, -255, 255), constrain(baseSpeed + motorspeed, -255, 255));
    }
  }
}

void trackslow() {
  while (1) {
    positionalRead = positional();

    error = positionalRead - 40;
    Serial.println(error);

    if (sensor_read(0) >= 18 && sensor_read(1) >= 18 && sensor_read(2) >= 18 && sensor_read(3) >= 18 && sensor_read(4) >= 18 && sensor_read(5) >= 18 && sensor_read(6) >= 18) {
      break;  // default is 275
    } else if (sensor_read(0) < 16 && sensor_read(1) < 16 && sensor_read(2) < 16 && sensor_read(3) < 16 && sensor_read(4) < 16 && sensor_read(5) < 16 && sensor_read(6) < 16) {

      if (diff == 1) {
        motor(250, -190);
      } else if (diff == 2) {
        motor(-190, 250);
      }


    } else {

      if (sensor_read(0) >= 5 || sensor_read(1) >= 5) {
        diff = 1;
      } else if (sensor_read(5) >= 5 || sensor_read(6) >= 5) {
        diff = 2;
      }

      //integrel = error + integrel;
      integrel = 0;
      motorspeed = (error * kp) + ((error - last_error) * kd);  //+ (integrel / ki);
      last_error = error;
      Serial.println(error);
      motor(constrain(baseSpeed - motorspeed, -255, 255), constrain(baseSpeed + motorspeed, -255, 255));
    }
  }
}


void trackskip() {
  while (1) {
    positionalRead = positional();

    error = positionalRead - 40;
    if (sensor_read(4) >= 18 && sensor_read(5) >= 18 && sensor_read(6) >= 18)  {
      break;  // default is 275
    } else if (sensor_read(0) < 16 && sensor_read(1) < 16 && sensor_read(2) < 16 && sensor_read(3) < 16 && sensor_read(4) < 16 && sensor_read(5) < 16 && sensor_read(6) < 16) {

      if (diff == 1) {
        motor(220, -167);
      } else if (diff == 2) {
        motor(-167, 220);
      }


    } else {

      if (sensor_read(0) >= 5 || sensor_read(1) >= 5) {
        diff = 1;
      } else if (sensor_read(5) >= 5 || sensor_read(6) >= 5) {
        diff = 2;
      }

      //integrel = error + integrel;
      integrel = 0;
      motorspeed = (error * kp) + ((error - last_error) * kd);  //+ (integrel / ki);
      last_error = error;
      Serial.println(error);
      motor(constrain(baseSpeed - motorspeed, -255, 255), constrain(baseSpeed + motorspeed, -255, 255));
    }
  }
}

void trackstop() {
  while (1) {
    positionalRead = positional();

    error = positionalRead - 40;

    if (sensor_read(0) >= 20 && sensor_read(1) >= 20 && sensor_read(2) >= 20 && sensor_read(3) >= 20 && sensor_read(4) >= 20 && sensor_read(5) >= 20 && sensor_read(6) >= 20) {
      motor(0, 0);
      break;  // default is 275
    } else if (sensor_read(0) < 16 && sensor_read(1) < 16 && sensor_read(2) < 16 && sensor_read(3) < 16 && sensor_read(4) < 16 && sensor_read(5) < 16 && sensor_read(6) < 16) {

      if (diff == 2) {
        motor(100, -30);
      } else if (diff == 1) {
        motor(-30, 100);
      }


    } else {

      if (sensor_read(0) >= 5 || sensor_read(1) >= 5) {
        diff = 1;
      } else if (sensor_read(5) >= 5 || sensor_read(6) >= 5) {
        diff = 2;
      }

      //integrel = error + integrel;
      integrel = 0;
      motorspeed = (error * kp) + ((error - last_error) * kd);  //+ (integrel / ki);
      last_error = error;
      Serial.println(error);
      motor(constrain(baseSpeed + motorspeed, -255, 255), constrain(baseSpeed - motorspeed, -255, 255));
    }
  }
}
