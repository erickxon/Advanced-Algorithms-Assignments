#include <iostream>
using namespace std;
//500562687 - John Lescano
 /*
 to run:
		g++ lab2.cpp
		./a.out x y
*/

float linpower(float x, int y){
	if(y==0)
		return 1;
	float xx = (y>0)?x:1/x;
	float result = (y%2)?xx*linpower(x,y/2)*linpower(x,y/2):linpower(x,y/2)*linpower(x,y/2);
	return result;

}

float logpower(float x, int y){
	if(y==0)
		return 1;
	float power = logpower(x,y/2);
	float xx = (y>0)?x:1/x;
	float result = (y%2)?xx*power*power:power*power;
	return result;
}

int main(int argc, char* argv[])
{
	double d = atof(argv[1]);
	double f = atof(argv[2]);
	cout << "Linear time: linpower("<<d<<","<<f<<") = " << linpower(d, f) << endl;
	cout << "Logarithmic time: logpower("<<d<<","<<f<<") = " << logpower(d, f) << endl;
	return 0;
}
