const int LDR = A0;
const int G = 3; 
const int Y = 4;
const int R = 5;
const float Res = 10000.0;
const float A = 127410;
const float B = -0.8582;
void setup() {
  pinMode(LDR, INPUT);
  pinMode(G, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(R, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int sensorValues = analogRead(LDR);
  float Vout = sensorValues * (5.0/1023.0);
  float Rldr =(5-Vout)*Res/Vout;
  float lux = cal_lux(Rldr);
  Serial.println("LDR Value");
  Serial.println(lux);
  if(lux>30){
    digitalWrite(R, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(G, HIGH);
    delay(500);
  }else{
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(G, LOW);
    delay(500);
    
}
  
  // put your main code here, to run repeatedly:

}
 float cal_lux(float data){
    return pow(data/A, 1.0/B);
  }
