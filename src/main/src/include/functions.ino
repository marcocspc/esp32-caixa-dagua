float get_dist_cm() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  return distance;
}

void print_distance_cm(float distance) {
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

//Funcoes matematicas para troncos de cone
float obter_h_zero() {
  float h0 = ht - get_dist_cm();
  
  if (h0 < 0 || h0 > ht) {
    h0 = 0;
  }

  return h0;
}

float obter_r_zero() {
  float h0 = obter_h_zero();
  return (r * (H - h + h0))/(H - h);
}


float obter_volume_tronco_cone() {
  float h0 = obter_h_zero();
  float r0 = obter_r_zero();
  return ((PI * h0) / 3) * ((r0 * r0) + (r0 * r) + (r * r));
}

float cm3_para_litro (float volume) {
  return volume / 1000;
}


void print_volume_litros() {
  float volume = obter_volume_tronco_cone();
  volume = cm3_para_litro(volume);

  Serial.print("Volume de agua: ");
  Serial.print(volume);
  Serial.println(" litros");
}
