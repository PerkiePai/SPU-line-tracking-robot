#define smid 800

float motorspeed;

int smin[10] = { 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023 };
int smax[10] = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
};

float error;
float last_error = 0;



int integrel;
int diff = 0;

void setup() {
  set_module();
  Serial.println("start loop");
}

void loop() {

  // sensor_test();
  // Serial.println(positional());

  track1();
  motor(255, 255);
  delay(50);

  trackslow();
  motor(255, 255);
  delay(100);

  trackskip();
  motor(200, 255);
  delay(970);  // 975
  // motor(75,95);
  // delay(1000);
  // trackstop();
  track1();
  //
  while (1) {
    motor(0, 0);
  };
}
