#include "movement.h"

movement::movement():m0(24,25,3),m1(23,22,2),m2(28,29,5){

}
void movement::setX(double x){
	this->x = x;
}
void movement::setY(double y){
	this->y = y;
}
void movement::setYaw(int yaw){
	this->yaw = yaw;
}
void movement::setDir(int dir,int pwm){
	setX(pwm*f.mycos(dir));
	setY(pwm*f.mysin(dir));
}
double movement::getX(){
	return this->x;
}
double movement::getY(){
	return this->y;	
}
void movement::moveMotor(int mo0,int mo1,int mo2){
	m0.output(mo0);
	m1.output(mo1);
	m2.output(mo2);
}
void movement::move(){
	int mo[3];
	mo[0] = round(this->x * f.mycos(300) + this->y * f.mysin(300) + this->yaw);
	mo[1] = round(-x + yaw);
	mo[2] = round(this->x * f.mycos(60) + this->y * f.mysin(60) + this->yaw);
	for(int i = 0;i < 3;i++){
		if(mo[i]>255){
			double temp = mo[i];
			mo[0] *= 255.0/temp;
			mo[1] *= 255.0/temp;
			mo[2] *= 255.0/temp;
		}
		if(mo[i]<-255){
			double temp = mo[i];
			mo[0] *= -255.0/temp;
			mo[1] *= -255.0/temp;
			mo[2] *= -255.0/temp;
		}
	}
	m0.output(mo[0]);
	m1.output(mo[1]);
	m2.output(mo[2]);
}
void movement::move(double x,double y,int yaw){
	setX(x);
	setY(y);
	setYaw(yaw);
	this->move();
}
void movement::move(int dir,int yaw,int pwm){
	setX(pwm*f.mycos(dir));
	setY(pwm*f.mysin(dir));
	setYaw(yaw);
	this->move();
}
void movement::stop(){
		m0.output(0);
		m1.output(0);
		m2.output(0);
}
motor::motor(){
	this->inA = inA;
	this->inB = inB;
	this->pwm = pwm;
}
motor::motor(int inA,int inB,int pwm){
	this->inA = inA;
	this->inB = inB;
	this->pwm = pwm;
}
void motor::output(int power){
	if (power > 0) {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
    analogWrite(pwm, power);
  }
  else {
    power *= -1;
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
    analogWrite(pwm, power);
  }
}