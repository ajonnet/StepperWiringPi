#include <rpi-hw.hpp>
#include <rpi-hw/time.hpp>
#include <rpi-hw/gpio.hpp>
#include <rpi-hw/motor/stepper.hpp>
#include <iostream>

using namespace rpihw;
using namespace std;

int main( int argc, char** argv )
{
    // Create the stepper controller
    motor::stepper dev( 200, 24, 25, 8, 7 );
    dev.setSequence(dev.seq_full);
    
    //gpio pin
    gpio &io = gpio::get();
    io.setup(20,OUTPUT);
    io.write(20,HIGH);
    io.setup(21,OUTPUT);
    io.write(21,HIGH);
    bool lastStateHigh = true;
    
    int count = 0;
    while(true) {
        // Start demo
        dev.setSpeed( 10.0 );
        dev.rotate( -180.0 );
        time::msleep( 500 );
        
        dev.setSpeed( 3.0 );
        dev.rotate( 45.0 );
        time::msleep( 500 );
        
        dev.setSpeed( 6.0 );
        dev.rotate( 45.0 );
        time::msleep( 500 );
        
        dev.setSpeed( 9.0 );
        dev.rotate( 45.0 );
        time::msleep( 500 );
        
        dev.setSpeed( 11.0 );
        dev.rotate( 45.0 );
        time::msleep( 500 );
        
        dev.setSpeed( 14.0 );
        dev.rotate( 90.0 );
        time::msleep( 500 );
        
        dev.setSpeed( 14.0 );
        dev.rotate( 90.0 );
        time::msleep( 500 );
        
        dev.setDirection( motor::DIRECTION_CCW );
        dev.rotate( 360.0 );
        time::msleep( 500 );
        
        io.write(21,(lastStateHigh)?LOW:HIGH);
        lastStateHigh = !lastStateHigh;
        
        cout<<"Iteration: "<<count++<<endl;
    }
    
    return 0;
}
