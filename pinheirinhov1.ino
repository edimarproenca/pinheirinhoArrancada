
// variables RightCar
  int stage1SensorRightCar = 14;
  int stage2SensorRightCar = 15;
  int stage1RightCar = 13;
  int stage2RightCar = 11;
  int greenRightCar = 6;
  int redRightCar = 4;

// variables LeftCar
  int stage1SensorLeftCar = 17;
  int stage2SensorLeftCar = 16;
  
  int stage1LeftCar = 12;
  int stage2LeftCar = 10;
  int greenLeftCar = 5;
  int redLeftCar = 3;
  
  int yellow1 = 9;
  int yellow2 = 8;
  int yellow3 = 7;
  int buttonState[4] = {0,0,0,0};
  
  
  
void setup() {
  pinMode(stage1SensorRightCar, INPUT);
  pinMode(stage2SensorRightCar, INPUT);
  pinMode(stage1RightCar,OUTPUT);
  pinMode(stage2RightCar,OUTPUT);
  pinMode(greenRightCar,OUTPUT);
  pinMode(redRightCar,OUTPUT);
  
  pinMode(stage1SensorLeftCar, INPUT);
  pinMode(stage2SensorLeftCar, INPUT);
  pinMode(stage1LeftCar,OUTPUT);
  pinMode(stage2LeftCar,OUTPUT);
  pinMode(greenLeftCar,OUTPUT);
  pinMode(redLeftCar,OUTPUT);
  
  pinMode(yellow1,OUTPUT);
  pinMode(yellow2,OUTPUT);
  pinMode(yellow3,OUTPUT);  
}

void loop() {
  detectStages();
  if(verifyStages() == 4){
     delay(1000);
       yellowRotine();
  }

}

int verifyStages(){
  int result = 0;
  for(int i = 0; i<4;i++){
    result+=buttonState[i];
  }
  return result;
}

void detectStages(){
  executeStageLights(stage1SensorLeftCar, stage1LeftCar, 1);
  executeStageLights(stage2SensorLeftCar, stage2LeftCar, 0);
  executeStageLights(stage1SensorRightCar, stage1RightCar, 2);
  executeStageLights(stage2SensorRightCar, stage2RightCar, 3);
}

void executeStageLights(int sensor, int light, int auxState){
  buttonState[auxState] = digitalRead(sensor);
  if(buttonState[auxState] == HIGH){
    digitalWrite(light, HIGH);
  }else{
    digitalWrite(light, LOW);
  }  
}

bool falseStartDetect(int indexButtonState, int sensor,int redLight){
   int result = true;
   buttonState[indexButtonState] = digitalRead(sensor);
   if(buttonState[indexButtonState] == LOW){
      digitalWrite(redLight, HIGH);
      result = false;
   }else{
      digitalWrite(redLight, LOW);
   }
   return result;
}

void yellowRotine(){
        falseStartDetect(1, stage1SensorLeftCar,redLeftCar);
        falseStartDetect(2, stage1SensorRightCar,redRightCar);
        digitalWrite(yellow1, HIGH);
        delay(800);
        falseStartDetect(1, stage1SensorLeftCar,redLeftCar);
        falseStartDetect(2, stage1SensorRightCar,redRightCar);
        digitalWrite(yellow2, HIGH);
        delay(800);
        falseStartDetect(1, stage1SensorLeftCar,redLeftCar);
        falseStartDetect(2, stage1SensorRightCar,redRightCar);
        digitalWrite(yellow3, HIGH);
        delay(800);
        digitalWrite(yellow1, LOW);
        digitalWrite(yellow2, LOW);
        digitalWrite(yellow3, LOW);
        digitalWrite(greenRightCar, !falseStartDetect(2, stage1SensorRightCar,redRightCar));
        digitalWrite(greenLeftCar, !falseStartDetect(1, stage1SensorLeftCar,redLeftCar));
}



void testeLeds(){
  int temp = 1000;
  digitalWrite(greenRightCar,LOW);
  digitalWrite(greenLeftCar,LOW);
  digitalWrite(redRightCar,LOW);
  digitalWrite(redLeftCar,LOW);
  digitalWrite(stage1RightCar,HIGH);
  digitalWrite(stage1LeftCar,HIGH);
  delay(temp);
  digitalWrite(stage2RightCar,HIGH);
  digitalWrite(stage2LeftCar,HIGH);
  delay(temp);
  digitalWrite(stage1RightCar,LOW);
  digitalWrite(stage1LeftCar,LOW);
  digitalWrite(stage2RightCar,LOW);
  digitalWrite(stage2LeftCar,LOW);
  digitalWrite(yellow1,HIGH);
  delay(temp);
  digitalWrite(yellow2,HIGH);
  delay(temp);
  digitalWrite(yellow3,HIGH);
  delay(temp);
  digitalWrite(stage1RightCar,LOW);
  digitalWrite(stage1LeftCar,LOW);
  digitalWrite(stage2RightCar,LOW);
  digitalWrite(stage2LeftCar,LOW);
  digitalWrite(yellow1,LOW);
  digitalWrite(yellow2,LOW);
  digitalWrite(yellow3,LOW);
  digitalWrite(greenRightCar,HIGH);
  digitalWrite(greenLeftCar,HIGH);
  delay(temp);
  digitalWrite(greenRightCar,LOW);
  digitalWrite(greenLeftCar,LOW);
  digitalWrite(redRightCar,HIGH);
  digitalWrite(redLeftCar,HIGH);
  delay(temp);
}
