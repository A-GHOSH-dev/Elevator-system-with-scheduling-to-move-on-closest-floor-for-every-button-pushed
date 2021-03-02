#include<Stepper.h> //we include the stepper motor library

//Buttons start

int i=1;    // the value represents where elevator stay ( fisrt time elevator start in the first floor)
int btn4=5; // 4 th floor
int btn3=4; //2 nd floor
int btn2=3; //3 th floor
int btn1=2; //1 st floor 

int buttonState1=0;
int buttonState2=0;
int buttonState3=0;
int buttonState4=0;

//Buttons end


//Stepper motor starts

const int stepsPerRevolution = 90; 
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);    

//Stepper Motor ends



void setup() {
    
 // set the speed at 60 rpm:
  myStepper.setSpeed(5);
  
  
  Serial.begin(9600);

  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(btn3,INPUT);
  pinMode(btn4,INPUT);

}

void loop() {
  buttonState1 = digitalRead(btn1);
  buttonState2 = digitalRead(btn2);
  buttonState3 = digitalRead(btn3);
  buttonState4 = digitalRead(btn4);

//4th Floor
if(buttonState4 == HIGH){
while(i<4){   
    i++;
    //go up
    myStepper.step(-stepsPerRevolution*(4-i));
    
  }
  i=4;

  }
  //Reached 4th Floor

  
 //3rd floor
  if(buttonState3==HIGH){
  
    if(i>3){
      while(i>3) {
      i--;
      //go down
      myStepper.step(stepsPerRevolution*(i-3));
    
    
      }
    }
    if(i<3){
      while(i<3){
        i++;
        //go up
        myStepper.step(-stepsPerRevolution*(3-i));
   
    
    }
        
    }    
    
    
  i=3; //now lift is at 3rd floor
   
   

      
  } 



// 2 nd floor 
  if(buttonState2 == HIGH){
  if(i>2){
    while(i>2)
    {
    i--;
    //go down
    myStepper.step(stepsPerRevolution*(i-2));
    

    }  
    i=2;   
  }
      if(i<2){
      while(i<2){
        i++;
        //go up
        myStepper.step(-stepsPerRevolution*(2-i));
    
      }
      i=2;//lift at 2nd floor
    }
      
    }




    
// 1 st floor 
  if(buttonState1 == HIGH){
    if(i>1){
      while(i>1){
      
      i--;
      //go down
      myStepper.step(stepsPerRevolution*(i-1));
    
    
    }
    }
    i=1;       //lift at 1st floor
  }
  
  
} 
