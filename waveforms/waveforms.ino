// #include <cmath>
#define pi 3.141592653589
int value1 = 0;
float value2;
float value3;
float period;
float B;
// float period_in_ms = period * 1000;
float period_in_ms;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {

    String content = Serial.readStringUntil('\n');
    period_in_ms = content.toInt();

    // if (content == "square") {
      
      

    }
    // else {
    //   value = 0;
    //   Serial.println(value);
    // }

    for (int i = 0; i < period_in_ms / 2; i++) {
        // Square Wave
        value1 = 1;
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
        delay(1);
      }

      for (int j = 0; j < period_in_ms / 2; j++) {
        // Square wave
        value1 = 0;
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
        delay(1);
      }
  // }

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
