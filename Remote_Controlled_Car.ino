#include <IRremote.h>
#include <IRremoteInt.h>
//#include <IRremoteTools.h>

//www.elegoo.com
//2016.12.9

#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

//Motor Stuff
int PWM_A = 8;
int in_A1 = 7;
int in_A2 = 6;

int PWM_B = 5;
int in_B1 = 4;
int in_B2 = 3;



/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'


//Car Motor Colors:
//Red: Motor 1+2 positive
//Black: Ground, Motor 1+2 negative
//Orange: Motor 3+4 postive, PWM-A+B
//Green: Motor 3+4 negative
//Blue: Vin
//Dark Blue: BIN-A+B
//White: Standby
//Yellow: AIN-A+B





/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{
  int sensorValue = 0;
  //sensorValue = digitalRead(ledPin);

  switch(results.value)

  {
  case 16753245: 
    //Moves Car forward
    if (sensorValue == 0){
      Serial.println("FORWARD");
        digitalWrite(in_A1, HIGH);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, HIGH);
        digitalWrite(PWM_B, HIGH);
      break;
    }
    //Stops the car
    if (sensorValue==1){
      Serial.println("STOP");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, HIGH);
      break;
    }
  case 3810010651:
    //Sets power button to turn led light on
    if (sensorValue == 0){
      Serial.println("FORWARD");
        digitalWrite(in_A1, HIGH);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, HIGH);
        digitalWrite(PWM_B, HIGH);
      break;
    }
    //Sets power button to turn led light off
    if (sensorValue==1){
      Serial.println("STOP");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, HIGH);
      break;
    }
  case 0xFFE21D: 
      Serial.println("STOP");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, HIGH);
      break;
  case 4001918335:
      Serial.println("STOP");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, HIGH);
      break;
  case 0xFF629D:
      Serial.println("FORWARD");
        digitalWrite(in_A1, HIGH);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, HIGH);
        digitalWrite(PWM_B, HIGH);  
      break;
  case 5316027:
        Serial.println("FORWARD");
        digitalWrite(in_A1, HIGH);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, HIGH);
        digitalWrite(PWM_B, HIGH);
      break;
  case 0xFF22DD: 
        Serial.println("LEFT");    
        digitalWrite(in_A1, HIGH);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, 127);
        
        digitalWrite(in_B1, HIGH);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, 127);
      break;
  case 1386468383:
        Serial.println("LEFT");    
        digitalWrite(in_A1, HIGH);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, 127);
        
        digitalWrite(in_B1, HIGH);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, 127);    
      break;
  case 0xFF02FD:  
        Serial.println("STOP");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, HIGH);
      break;
  case 3622325019: 
        Serial.println("STOP");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, LOW);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, HIGH);
      break; 
  case 0xFFC23D: 
        Serial.println("RIGHT");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, HIGH);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, HIGH);
        digitalWrite(PWM_B, HIGH);   
      break;
  case 553536955: 
        Serial.println("RIGHT");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, HIGH);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, LOW);
        digitalWrite(in_B2, HIGH);
        digitalWrite(PWM_B, HIGH);  
      break;
  case 0xFFE01F: Serial.println("DOWN"); break;
  case 4034314555: Serial.println("DOWN"); break;
  case 0xFFA857:   
        Serial.println("BACKWARDS");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, HIGH);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, HIGH);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, HIGH);
      break;
  case 2747854299: 
        Serial.println("BACKWARDS");
        digitalWrite(in_A1, LOW);
        digitalWrite(in_A2, HIGH);
        digitalWrite(PWM_A, HIGH);

        digitalWrite(in_B1, HIGH);
        digitalWrite(in_B2, LOW);
        digitalWrite(PWM_B, HIGH);
      break;
  case 3855596927: Serial.println("UP"); break;
  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 2538093563: Serial.println("EQ"); break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 4039382595: Serial.println("ST/REPT"); break;
  case 0xFF6897: Serial.println("0");    break;
  case 3238126971: Serial.println("0"); break;
  case 0xFF30CF: Serial.println("1");    break;
  case 2534850111: Serial.println("1"); break;
  case 0xFF18E7: Serial.println("2");    break;
  case 1033561079: Serial.println("2"); break;
  case 0xFF7A85: Serial.println("3");    break;
  case 1635910171: Serial.println("3"); break;
  case 0xFF10EF: Serial.println("4");    break;
  case 2351064443: Serial.println("4"); break;
  case 0xFF38C7: Serial.println("5");    break;
  case 1217346747: Serial.println("5"); break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 71952287: Serial.println("6"); break;
  case 0xFF42BD: Serial.println("7");    break;
  case 851901943: Serial.println("7"); break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 465573243: Serial.println("8"); break;
  case 0xFF52AD: Serial.println("9");    break;
  case 1053031451: Serial.println("9"); break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" other button : ");
    Serial.println(results.value);

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
  //pinMode (ledPin, OUTPUT);
  pinMode(in_A1, OUTPUT);
  pinMode(in_A2, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  
  pinMode(in_B1, OUTPUT);
  pinMode(in_B2, OUTPUT);
  pinMode(PWM_B, OUTPUT); 
  
}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }
  
}/* --(end main loop )-- */
