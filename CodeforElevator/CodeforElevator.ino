#include <Stepper.h>

const int stepsPerRevolution = 64;  //change this for your motor

// initialize the stepper library om pins
Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7);
//defining constants

int k = 0;

int current = 0;
boolean buttons[4];
buttons[]={0,0,0,0};

void setup() {
  // set the speed at 96 rpm:
  myStepper.setSpeed(5);
}

void loop() {
   k=0;
   input();
   
   for(i=0;i<k;i++)
   {
    
   int destination=dest(); 
   myStepper.step(stepsPerRevolution*destination);
   current=abs(destination);
   }
   


void input()
{
   int i;
   for(i=0;i<4;i++)
   {
      buttons[i]=digitalRead(i+2);
      if(buttons[i]==HIGH)
      {
        k++;
      }
      if(i==current)
      {
        buttons[i]=LOW;
      }
   }
}

int dest()
{
  int i,d,m=4,n,t;
  for(i=0;i<4;i++)
  {
    if(buttons[i]==HIGH && i!=current)
    {
        if(m>=abs(current-i))
        {
          m=abs(current-i);//no. of floors to travel
          n=current-i;//direction and no. of floors to travel
        }
        
    }
    
  }
  d=n;
  return d;
}
