const int relayPin = 26;
int buttonState = 0;
char msg[3];
bool startFlag;
bool endFlag;
byte index;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0) {
    currByte = Serial.read();
    if(currByte == '<') {
      startFlag = TRUE;
    } else if(currByte == '>') {
      endFlag = TRUE;
    } else {
      if(index < 4) {
        if(currByte == '42') {
          digitalWrite(relayPin, HIGH);
          digitalWrite(relayPin, LOW);
        }
      }
    }
    index++;
  }
}