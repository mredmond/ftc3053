#include <basicFunctions.h>

task main()
{
   rightPivotDeg(90);
   wait1Msec(2000);

   leftPivotDeg(90);
   wait1Msec(2000);

   pivot180();
   wait1Msec(2000);

   backward(25);
   wait1Msec(2000);

   forward(25);
   wait1Msec(2000);

   accelerate(15, 90, 30, 80);
   decelerate(90, 15, 30, 80);


}
