#include<iostream>
#include<string>
#include<time.h>
#include<random>
#include<ctime>
#include<Math.h>
using namespace std;

	int randT;
	double t;
	double x;
	const int x_s = 100;
	const int v = 20;
	const int a = 12;
	double ft = 0;

	double getP(double z)
	{

		if (v*v + 2 * a*z >= 0) {
			t = (-v + sqrt(v*v + 2 * a*z)) / a;//взял положительный корень t, выразив через дискриминант 
			return t;
		}
		else {
			cout << "Error D<0!!!" << endl;
		}
	}

	double getFT(double t) //f(t)=v*t+(a/2)*(t^2)
	{
		ft = v*t + (a / 2)*t*t;
		return ft;
	}
	void sravnenie(double x, double x_s)
	{
		
		if (static_cast<float>(x) == static_cast<float>(x_s)) { cout << "f(t)+random = x_s" << endl; }
		else { cout << "f(t)+random NE ravno x_s" << endl; }
	}

void main()
{
	srand(time(NULL));
	int random = 1 + rand() % 10;
	cout << "random= "<<random << endl;
	double z = x_s - random; //z=f(t),  f(t) + random() = x_s
	t = getP(z);
	cout <<"t= "<<t<< endl;
	ft = getFT(t);
	cout << "f(t)= "<<ft << endl;
	x = ft + random;
	cout << "f(t)+random= " <<x << "\tx_s= " << x_s << endl;

	sravnenie(x, x_s);
	system("pause");
}
