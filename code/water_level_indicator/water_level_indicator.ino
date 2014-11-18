int in1=32;
int in2=28;
int in3 =24;
int in4 =22;

void setup() {
Serial.begin(9600);
     pinMode(in1, INPUT);   
     pinMode(in2, INPUT);     
     pinMode(in3, INPUT);
     pinMode(in4, INPUT);
}

void loop() {
  
     if(digitalRead(in4) == LOW) {
        Serial.println("niveau4 : verre plein");
     } 
     else if(digitalRead(in3) == LOW) {
               Serial.println("niveau3 : verre presque");
     }    
    else if(digitalRead(in2) == LOW) 
      {
        Serial.println("niveau2 : verre à moitie plein");
     } 
     else if(digitalRead(in1) == LOW) {
               Serial.println("niveau1 : verre presque vide");
     }   
    else
   {
   Serial.println("vide");
   } 
      
     
     
//     if(digitalRead(in1) == LOW) {
//        Serial.println("niveau1");
//     } 
//     else {
//               Serial.println("pas niveau1");
//     }    
//      if(digitalRead(in2) == LOW) 
//      {
//        Serial.println("niveau2");
//     } 
//     else {
//               Serial.println("pas niveau2");
//     }    
//      if(digitalRead(in3) == LOW) 
//      {
//        Serial.println("niveau 3");
//     } 
//     else {
//               Serial.println("pas niveau3");
//     }    
//     if(digitalRead(in4) == LOW) 
//      {
//        Serial.println("niveau4");
//     } 
//     else {
//               Serial.println("pas niveau4");
//     }    
     
 
  delay(50);  
 }
