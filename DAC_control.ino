
/*
 * this code controls the 5 MSBs of the 12 input bits on DAC on the TI ASLK
 * every 10 seconds, the program changes modes from, 11111, 00111, 00000
 * 11111 programs an oscillator circuit to 153 Hz
 * 00111 programs the circuit to 63 Hz
 * 00000 programs the circuit to 7.8 Hz
 * 
*/

#define MSB1 2
#define MSB2 3
#define MSB3 4
#define MSB4 5
#define MSB5 6
#define CS 17


void setup() {
  // put your setup code here, to run once:
  pinMode(MSB1, OUTPUT);
  pinMode(MSB2, OUTPUT);
  pinMode(MSB3, OUTPUT);
  pinMode(MSB4, OUTPUT);
  pinMode(MSB5, OUTPUT);
  pinMode(CS, OUTPUT);

  //start the CS pin to HIGH so that it does not latch data yet (it is active low)
  digitalWrite(CS, HIGH);
}

void loop() {

    //freq 153 Hz (11111)
    digitalWrite(MSB1, HIGH);
    digitalWrite(MSB2, HIGH);
    digitalWrite(MSB3, HIGH);
    digitalWrite(MSB4, HIGH);
    digitalWrite(MSB5, HIGH);  

   //latch data with CS pin   
    delay(100);
    digitalWrite(CS, LOW);
    delay(100);
    //prevent data from being latched
    digitalWrite(CS, HIGH);
    //delay 10 sec to obersve freq change
    delay(10000);

    //freq 63 Hz (00111)
    digitalWrite(MSB1, LOW);
    digitalWrite(MSB2, LOW);
    digitalWrite(MSB3, HIGH);
    digitalWrite(MSB4, HIGH);
    digitalWrite(MSB5, HIGH);  

    //latch data with CS pin    
    delay(100); 
    digitalWrite(CS, LOW);
    //prevent data from being latched
    delay(100);
    digitalWrite(CS, HIGH);
    //delay 10 sec to obersve freq change
    delay(10000);

    //freq 7.8 Hz (00000)
    digitalWrite(MSB1, LOW);
    digitalWrite(MSB2, LOW);
    digitalWrite(MSB3, LOW);
    digitalWrite(MSB4, LOW);
    digitalWrite(MSB5, LOW);    

    //latch data with CS pin    
    delay(100); 
    digitalWrite(CS, LOW);
    //prevent data from being latched
    delay(100);
    digitalWrite(CS, HIGH);
    //delay 10 sec to obersve freq change
    delay(10000);
}

