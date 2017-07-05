#include "Stepper.h"
#include <wiringPi.h>
#include <iostream>


using namespace std;

int main( int argc, char** argv )
{
    wiringPiSetup();
    
    // Create the stepper controller
    Stepper motor(200,5,6,10,11);
    
    //Setup LED PIN
    pinMode(25, OUTPUT);
    digitalWrite(25, HIGH);
    
    int count = 0;
    bool lastStateHigh = true;
    while(true) {
        motor.setSpeed(10);
        motor.step(200);
        delay(500);
        
        motor.setSpeed(100);
        motor.step(-100);
        delay(500);
        
        //Alternate LED
        digitalWrite(25,(lastStateHigh)?LOW:HIGH);
        lastStateHigh = !lastStateHigh;
        
        cout<<"Iteration: "<<count++<<endl;
    }
    
    return 0;
}
