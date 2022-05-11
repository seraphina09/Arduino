#define LED1 27 // blue
#define LED2 26 // red
#define LED3 34 // green
#define LED4 13 // yellow
#define LED5 33 // white

#define BUTTON1 14 //push button
#define BUTTON2 32 // on/off button

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);  
  pinMode(LED2, OUTPUT); 
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(BUTTON2, INPUT);
}

void loop() {
  int buttonStatus = digitalRead(BUTTON1);
  Serial.println(buttonStatus);

    whileint i;

    
    while(i<6);
    degitalWrite(LED1, HIGH);
    delay(500);
    degitalWrite(LED1, LOW);
    delay(500);
    }


//問１。交差して転倒するように。ON→青点灯・OFF→赤点灯
//void setup() {
//  Serial.begin(115200);
//  pinMode(LED1, OUTPUT);　  
//  pinMode(LED2, OUTPUT); 
//  pinMode(BUTTON, INPUT_PULLUP);
//}
// int buttonStatus = digitalRead(BUTTON1);
// Serial.println(buttonStatus);
 
//  if(buttonStatus == 1){
//    
//    digitalWrite(LED1, HIGH);
//    digitalWrite(LED2, LOW);
//  }else {
//    digitalWrite(LED2, HIGH);
//    digitalWrite(LED1, LOW);
//  }

}
