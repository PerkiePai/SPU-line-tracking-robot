float positional() {

  float ssum = ((sensor_read(0) * 10) + (sensor_read(1) * 20) + (sensor_read(2) * 30) + (sensor_read(3) * 40) + (sensor_read(4) * 50) + (sensor_read(5) * 60) + (sensor_read(6) * 70));
  float saverage = sensor_read(0) + sensor_read(1) + sensor_read(2) + sensor_read(3) + sensor_read(4) + sensor_read(5) + sensor_read(6);

  float total;
  if (saverage == 0) {
    total = 0;
  } else {
    total = ssum / saverage;
  }
  return total;
}
