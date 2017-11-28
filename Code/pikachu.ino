#include <Servo.h>
#include <Ultrasonic.h>

int posBack = 90;
int posFront = 90;
int startPos = 90;
Servo backLegs;
Servo frontLegs;

Ultrasonic ultrasonic(12, 13);

void setup() {
 
  backLegs.attach(9);
  frontLegs.attach(8);
  Serial.begin (9600);

  for (posBack = startPos; posBack <= startPos-25; posBack--) { 
    backLegs.write(posBack);             
    delay(5);                      
  }

  for (posFront = startPos; posFront <= startPos-25; posFront--) { 
    frontLegs.write(posFront);             
    delay(5);
            
  
  }
}

void loop() {
Serial.println(ultrasonic.distanceRead());

if (ultrasonic.distanceRead() > 15||ultrasonic.distanceRead()==0){
for (posBack = startPos-25; posBack <= startPos+25; posBack++) { 
    backLegs.write(posBack);             
    delay(5);                      
  }
   for (posFront = startPos-25; posFront <= startPos+25; posFront++) { 
    frontLegs.write(posFront);             
    delay(5);
            
  
  }
 
   for (posBack = startPos+25; posBack >= startPos-25; posBack--) { 
    backLegs.write(posBack);              
    delay(5);          

  
  }
   for (posFront =startPos+25; posFront >= startPos-25; posFront--) { 
    frontLegs.write(posFront);              
    delay(5);        
      }
}
 else {
  delay(1000);
  for (int back = 0; back <= 5; back++){
  for (posBack = startPos-20; posBack <= startPos+35; posBack++) { 
    backLegs.write(posBack);             
    delay(3);                      
  }
   for (posFront = startPos+25; posFront >= startPos-25; posFront--) { 
    frontLegs.write(posFront);             
    delay(5);
            
  
  }
 
   for (posBack = startPos+35; posBack >= startPos-20; posBack--) { 
    backLegs.write(posBack);              
    delay(3);          
  
  }
   for (posFront = startPos-25; posFront <= startPos+25; posFront++) { 
    frontLegs.write(posFront);              
    delay(5);        
 }
 }
 }

}  


 
 




