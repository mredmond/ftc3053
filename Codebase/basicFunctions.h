          #include <JoystickDriver.c>


int verboseAutoThreshold()
{
	int lightVal = 0;
	int darkVal = 0;
	int tHold = 0;


	nxtDisplayString(3, "Autothresholding");
  wait1Msec(2000);

	eraseDisplay();

	nxtDisplayString(0, "Read Light");
	while(nNxtButtonPressed == -1)
	{
	}

	lightVal = SensorValue[S2];

	nxtDisplayString(1, "Light: %d", lightVal);

	while(nNxtButtonPressed != -1)
	{
	}

	nxtDisplayString(2, "Read Dark");
	while(nNxtButtonPressed == -1)
	{
	}

	darkVal = SensorValue[S2];

	nxtDisplayString(3, "Dark: %d", darkVal);

	while(nNxtButtonPressed != -1)
	{
	}

	tHold = (lightVal + darkVal) / 2;

	nxtDisplayString(4, "THold: %d", tHold);

	wait1Msec(2000);

	return tHold;
}

void leftPivotDeg(int deg)
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	while (nMotorEncoder[motorB] > -(0.19 * deg))
	{
		motor[motorB] = -30;
		motor[motorC] =  30;
	}
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
}

void rightPivotDeg(int deg)
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	while (nMotorEncoder[motorB] < (0.19 * deg))
	{
		motor[motorB] = 30;
		motor[motorC] = -30;
	}
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
}

void pivot180()
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	while(nMotorEncoder[motorB] < 0.19*180 && nMotorEncoder[motorC] < -0.19*180)
	{
		motor[motorB] = 30;
		motor[motorC] =-30;
	}
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
}

void backward(int cm)
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	while(nMotorEncoder[motorB] >= -cm*20.4)
	{
		  motor[motorB] = -79;
	  	motor[motorC] = -75;
	}
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
}

void forward(int cm)
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	while(nMotorEncoder[motorB] <= cm*20.4)
	{
		motor[motorB] = 79;
		motor[motorC] = 75;
	}
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
}

void accelerate(int startSpeed, int endSpeed, int dVinverse, int totalcm)
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	int i = startSpeed;
	while(nMotorEncoder[motorB] <= totalcm*20.4)
	{
		while(i < endSpeed)
		{
			motor[motorB] = i;
			motor[motorC] = (75.0/79.0) * i;
			wait1Msec(dVinverse);
			i++;
		}
	}
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
}

void decelerate(int startSpeed, int endSpeed, int dVinverse, int totalcm)
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	int i = startSpeed;
	while(nMotorEncoder[motorB] <= totalcm*20.4)
	{
		while(i > endSpeed)
		{
			motor[motorB] = i;
			motor[motorC] = (75.0/79.0) * i;
			wait1Msec(dVinverse);
			i--;
		}
	}
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
}
