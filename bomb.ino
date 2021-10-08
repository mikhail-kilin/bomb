#define red 2
#define green 3
#define boom 4
#define data A0

int state;
int count;

int barrier = 150;

void setup() {
  Serial.begin(9600);
  state = 0;
  count = 0;
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(boom, OUTPUT);
}

void loop() {
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(boom, LOW);
  int input = analogRead(data);
  Serial.print(input);
  Serial.print(" ");
  Serial.print(count);
  Serial.print(" ");
  Serial.println(state);
  if (state == 0) {
    digitalWrite(red, HIGH);
    digitalWrite(boom, LOW);
    digitalWrite(green, LOW);
    if (input > barrier) {
      state = 1;
    }
  } else if (state == 1) {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(boom, LOW);
    if (input < barrier) {
      state = 2;
    }
  } else if (state == 2) {
    digitalWrite(boom, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    delay(1000);
    state = 3;
  } else {
    delay(1000);
  }
  delay(50);
}
