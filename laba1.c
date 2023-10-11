#include <stdio.h>
#include <math.h>
float u (float y, float x, float z)
{
float w=-sqrt(y*y+((4*x*x)/3));
float g=(5*cos(x*y)*cos(x*y)*cos(x*y)*cos(x*y))/(x*z);
return w+g;
}
int main()
{
 for(float x=1;x<=3;x+=1.3)
 {
 for(float y=2;y<=4;y+=1.3)
 {
 for(float z=0.5;z<=1.5;z+=0.8)
 {
 printf("y=%f x=%f z=%f u(y,x,z)=%f\n",y,x,z,u(y,x,z));
 }
 } 
 }
 return 0;
}
