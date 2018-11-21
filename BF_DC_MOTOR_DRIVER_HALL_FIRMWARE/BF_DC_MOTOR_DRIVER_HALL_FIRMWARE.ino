int brake_pin = 2;
int start_stop_pin = 4;
int run_brake_pin = 7;
int throttle_pin = A0;
int motor_pin = 10;
int motor_speed;
int brake_status;
int throttle_value;
long throttle_value_to_motor_speed = 3.14;

void setup() {
  pinMode (brake_pin, INPUT_PULLUP);
  pinMode (throttle_pin, INPUT);
  pinMode (motor_pin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(start_stop_pin, LOW);
  digitalWrite(run_brake_pin, LOW);
}

void loop() {
  throttle_value = analogRead(throttle_pin);
  //Serial.println(throttle_value);
  if (digitalRead(brake_pin) == HIGH) {
    digitalWrite(run_brake_pin, LOW);
    //Serial.println("BRAKE ON, MOTOR BRAKE.");
  } else if (digitalRead(brake_pin) == LOW) {
    digitalWrite(run_brake_pin, HIGH);
    //Serial.println("BRAKE OFF, MOTOR RUN.");
    if (throttle_value < 180) {
      motor_speed = 0;
      digitalWrite(start_stop_pin, LOW);
      analogWrite(motor_pin, motor_speed);
      //Serial.println("MOTOR STOP.");
    } else if (throttle_value > 800) {
    motor_speed = 255;
    analogWrite(motor_pin, motor_speed);
    //Serial.println("Motor at maximum speed!");
    } else {
      motor_speed = throttle_value / throttle_value_to_motor_speed;
      analogWrite(motor_pin, motor_speed);
      //Serial.println(motor_speed);
    }
  } else {
    Serial.println("BRAKE ERROR!");
  }
}

