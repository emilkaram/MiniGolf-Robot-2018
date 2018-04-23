particle photon arduino code
/*
* created by Emil Ibrahim
* Control MiniGolf ROBOT with Smartphone via bluetooth
*/

SYSTEM_MODE(MANUAL);
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int pos = 60;    // variable to store the servo position 


int motor1Pin1 = D0; 
int motor1Pin2 = D1; 
int motor2Pin1 = D5; 
int motor2Pin2 = D6; 


int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;

void setup() {
    
    myservo.attach(A5);  // attaches the servo on pin A5 to the servo object 
     
    
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    myservo.write(20);
    delay(15);
    myservo.write(75);
    delay(15);
   
    
   
// initialize serial communication at 9600 bits per second:
    Serial1.begin(9600);
}

void loop() {
    
    
        
        //if some date is sent, reads it and saves in state
    if(Serial1.available() > 0){     
      state = Serial1.read();   
      flag=0;
    }  
    
    
    
   
    // if the state is 'F' the DC motor will go forward
    if (state == 'F') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial1.println("Go Forward!");
          flag=1;
        }
    }
    
    // if the state is 'R' the motor will turn left
    else if (state == 'R') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial1.println("Turn LEFT");
          flag=1;
        }
        
    }
    // if the state is 'S' the motor will Stop
    else if (state == 'S' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial1.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
    // if the state is 'L' the motor will turn right
    else if (state == 'L') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial1.println("Turn RIGHT");
          flag=1;
        }
       
    }
    // if the state is 'B' the motor will Reverse
    else if (state == 'B') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial1.println("Reverse!");
          flag=1;
        }
    }
    
    
      // if the state is 'X' the servo will rotate right
    else if (state == 'X') {
         
         myservo.write(20);              // tell servo to go to position in variable 'pos' 
         delay(15);
        
        
        if(flag == 0){
          Serial1.println("Servo RIGHT");
          flag=1;
        }
       
    }
    
      // if the state is 'Y' the servo rotate left
     else if (state == 'Y') {
         
         myservo.write(75);              // tell servo to go to position in variable 'pos' 
         delay(15);
         
        
        
        if(flag == 0){
          Serial1.println("Servo RIGHT");
          flag=1;
        }
       
    }
    
    
    //For debugging purpose
    //Serial1.println(state);
}
