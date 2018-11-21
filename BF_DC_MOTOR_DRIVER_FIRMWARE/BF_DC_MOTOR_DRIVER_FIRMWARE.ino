int ch1; // Here's where we'll keep our channel values
int motor_speed;

void setup() {

  pinMode(5, INPUT); // Set our input pins as such
  pinMode(10, OUTPUT);
  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {
  ch1 = pulseIn(5, HIGH, 25000); // Read the pulse width of each channel
  Serial.print("Channel 1:"); // Print the value of 
  Serial.println(ch1);        // each channel
  motor_speed = ch1 - 1486;
  Serial.println(motor_speed);
  motor_speed = motor_speed / 2.111;
  Serial.println(motor_speed);
  if (ch1 < 1500) {
    analogWrite(10, 0);
    Serial.println("motor stop.");
  }else{
    analogWrite(10, motor_speed);
    Serial.println(motor_speed);
  }

  delay(100); // I put this here just to make the terminal 
              // window happier
}
