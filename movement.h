#ifndef movement_h
#define movement_h
#include "mymath.h"
#include "arduino.h"

class motor
{
public:
	motor();
	motor(int inA,int inB,int pwm);
	void output(int power);
private:
	int inA,inB,pwm;
};

class movement
{
public:
	movement();
	void setX(double x);
	void setY(double y);
	void setYaw(int yaw);
	void setDir(int dir,int pwm);
	double getX();
	double getY();
	void moveMotor(int mo0,int mo1,int mo2);
	void move();
	void move(double x,double y,int yaw);
	void move(int dir,int yaw,int pwm);
	void stop();
private:
	mymath f;
	motor m0,m1,m2;
	double x,y,yaw;
};
#endif