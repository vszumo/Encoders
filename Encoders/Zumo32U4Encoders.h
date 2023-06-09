 // Copyright Pololu Corporation.  For more information, see http://www.pololu.com/
  
 #pragma once
  
 #include <stdint.h>
  
 class Zumo32U4Encoders
 {
  
 public:
  
     static void init()
     {
         static bool initialized = 0;
         if (!initialized)
         {
             initialized = true;
             init2();
         }
     }
  
     static int16_t getCountsLeft();
  
     static int16_t getCountsRight();
  
     static int16_t getCountsAndResetLeft();
  
     static int16_t getCountsAndResetRight();
  
     static bool checkErrorLeft();
  
     static bool checkErrorRight();
  
 private:
  
     static void init2();
 };