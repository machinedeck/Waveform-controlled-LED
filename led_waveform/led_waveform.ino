// #include <cmath>
#define pi 3.141592653589
String type_;
int led_light = 0;
int value1 = 0;
int led = 7;
float value2;
float value3;
float period;
float B;
// float period_in_ms = period * 1000;
float period_in_ms;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED_BUILTIN, LOW);
  if (Serial.available() > 0) {

    String content = Serial.readStringUntil('\n');
    period_in_ms = content.substring(2).toInt();
    type_ = content[0];

    // if (content == "square") {
      
      

    }
    // else {
    //   value = 0;
    //   Serial.println(value);
    // }
    // if (period_in_ms == )
    if (period_in_ms >= 0 && period_in_ms <= 1000) {
      for (int i = 0; i < period_in_ms / 2; i++) {
          // Square Wave
          value1 = 1;
          led_light = 255 * value1;
          analogWrite(led, led_light);
          Serial.print("Square:");
          Serial.print(value1);

          Serial.print(",");

          // Sawtooth wave
          value2 = i / period_in_ms;
          Serial.print("Sawtooth:");
          Serial.print(value2);

          Serial.print(",");

          // Sine wave
          value3 = 0.5 * sine(period_in_ms, i) + 0.5;
          Serial.print("Sine:");
          Serial.println(value3);

          // Square Wave
          if (type_ == "A") {
            led_light = 255 * value1;
          }

          // Sawtooth Wave
          else if (type_ == "B") {
            led_light = 255 * value2;
          }

          // Sine Wave
          else if (type_ == "A") {
            led_light = 255 * value3;
          }

          else {
            led_light = 0;
          }

          analogWrite(led, led_light);
          delay(1);
        }

        for (int j = 0; j < period_in_ms / 2; j++) {
          // Square wave
          value1 = 0;
          led_light = 255 * value1;
          analogWrite(led, led_light);
          Serial.print("Square:");
          Serial.print(value1);

          Serial.print(",");

          // Sawtooth wave
          value2 = (period_in_ms / 2 + j) / period_in_ms;
          Serial.print("Sawtooth:");
          Serial.print(value2);

          Serial.print(",");

          // Sine wave
          value3 = 0.5 * sine(period_in_ms, j + period_in_ms / 2) + 0.5;
          Serial.print("Sine:");
          Serial.println(value3);

          // Square Wave
          if (type_ == "A") {
            led_light = 255 * value1;
          }

          // Sawtooth Wave
          else if (type_ == "B") {
            led_light = 255 * value2;
          }

          // Sine Wave
          else if (type_ == "A") {
            led_light = 255 * value3;
          }

          else {
            led_light = 0;
          }

          analogWrite(led, led_light);
          delay(1);
        }
  }

}

int factorial (int n) {
  int fact = 1;
  if (n == 0) {
    return 1;
  }

  else {
    // int fact = 1;
    for (int i = 1; i <= n; i++) {
      fact = fact * i;
    }
    return fact;
  }
}

float sine (float p, int t) {
  float B = p / (2 * pi);
  float sum_ = 0;
  for (int i = 0; i < 4; i++) {
    sum_ = sum_ + pow(- 1, i) * pow(B * t, 2 * i + 1) / factorial(2 * i + 1);
  }
  return sum_;
}
