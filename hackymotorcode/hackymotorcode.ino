const int dirPin1 = 2;
const int dirPin2 = 4;
const int stepPin1 = 3;
const int stepPin2 = 5;
int dir1 = 0;
int dir2 = 0;
int period1 = 1000;
int period2 = 1000;
int on = 0;
char input = 'x';

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(dirPin1,OUTPUT);
pinMode(dirPin2,OUTPUT);
pinMode(stepPin1,OUTPUT);
pinMode(stepPin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    input = Serial.read();
  }
  if (input == 'w'){
    dir1 = 0;
    on = 1;
  }
  if (input == 's'){
    dir1 = 1;
    on = 1;
  }
  if (input == 'a'){
    dir2 = 0;
    on = 1;
  }
  if (input == 'd'){
    dir2 = 1;
    on = 1;
  }
  if (input == 'x'){
    on = 0;
  }

  digitalWrite(dirPin1,dir1);
  digitalWrite(dirPin2,dir2);

  if(on == 1){

  if(micros()%period1%2==1){
    digitalWrite(stepPin1,LOW);
  }
  else{
    digitalWrite(stepPin1,HIGH);
  }

  if(micros()%period2%2==1){
    digitalWrite(stepPin2,LOW);
  }
  
  else{
    digitalWrite(stepPin2,HIGH);
  }

  }
}
