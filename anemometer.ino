  }
  http.end();
}

void displayWindData() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed:");
  lcd.setCursor(8, 0);
  lcd.print(windSpeed);
  lcd.print(" m/s");
  
  lcd.setCursor(0, 1);
  lcd.print("Dir: ");
  lcd.print(windDirection);   // e.g., 360
  lcd.write(223);             // ° symbol
  lcd.print(" ");
  lcd.print(compassDir);      // e.g., NNW
}

void sendToFirebase(float speed, int direction) {
  if (!Firebase.ready()) return;
  
  Firebase.setFloat(fbData, DATA_PATH "/Speed", speed);
  Firebase.setInt(fbData, DATA_PATH "/Direction", direction);
}

void setMotorSpeed(int speedA, int speedB, int speedC, int speedD) {
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
  analogWrite(ENC, speedC);
  analogWrite(END, speedD);
}

void moveForward() {
  lcd.clear();
  lcd.print("Moving Forward");
  delay(1000); // Show message for 1 seconds
  displayWindData(); // Return to wind data display
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  setMotorSpeed(200, 200, 200, 200);
  motorsActive = true;
}

void moveBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  setMotorSpeed(200, 200, 200, 200);
  motorsActive = true;
  lcd.clear();
  lcd.print("Moving Backward");
}

void turnRight() {
  lcd.clear();
  lcd.print("Turning Right");
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
