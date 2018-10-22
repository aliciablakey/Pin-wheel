 /* 
    source: www.electroschematics.com
    You'll need to change the led pins and the codes 
    accordingly to your configuration and IR remote
    */
     
    #include <IRremote.h>
     
    int RECV_PIN = 12; // the pin where you connect the output pin of TSOP4838
    int led1 = 8;
    int led2 = 9;
    int led3 = 10;
    int led4 = 11;
    int itsONled[] = {0,0,0,0,0};
    /* the initial state of LEDs is OFF (zero) 
    the first zero must remain zero but you can 
    change the others to 1's if you want a certain
    led to light when the board is powered */
    #define code1  33772 // code received from button A
    #define code2  52972 // code received from button B
    #define code3  3494 // code received from button C
    #define code4  65160 // code received from button D     
    IRrecv irrecv(RECV_PIN);
     
    decode_results results;
     
