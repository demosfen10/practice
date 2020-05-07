#include<iostream>
#include<string>
#include<time.h>
#include<random>
#include<ctime>
#include<Math.h>
using namespace std;
/*class Function //f(t)=v*t+(a/2)*(t^2)
{
public:
	const double a;
	const double v;
	const double x_s;
	int t=1;//время
	int n = 10;//размер массивов
	int* ft = new int[n];
	int* arrayX=new int[n];
	//double x = ;
		double p() //у p(...) должен быть аргумент.
	{//здесь выходит t
		return t;
	}
		void random() //диапазон зависит от выбранных А и V
			          //чтобы он не сильный разброс имел -1, 3, 2, 7, 5, 9 - это хороший
	{
	}
		void func(double a, double v, double t)
		{
			double f;
			for (int i = 0; i < sizeof(ft)/sizeof(*ft);i++)
			{
				ft[i] = v*t + (a / 2)*t*t;
			}
			
		}
		void cicl() {
			for (int i = 0; i < sizeof(arrayX) / sizeof(*arrayX); i++)
			{
				arrayX[i] = ft[i] + rand();
			}
		}
};*/
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
		else{
			cout << "Error D<0!!!" << endl;
		}
}

double getFT(double tt) //f(t)=v*t+(a/2)*(t^2)
{
	tt = t;
	ft = v*tt + (a / 2)*tt*tt;
	return ft;
}
void sravnenie(double x, double x_s)
{
	if (x == x_s) { cout << "f(t)+random = x_s" << endl; }
	else { cout << "f(t)+random NE ravno x_s" << endl; }
}
void main()
{
	
	srand(time(NULL));
	int random = 1 + rand() % 10;
	cout << "random= "<<random << endl;
	double z = x_s - random;
	t = getP(z);
	cout <<"t= "<<t<< endl;
	ft = getFT(t);
	cout << "f(t)= "<<ft << endl;
	x = ft + random;
	cout << "f(t)+random= " <<x << "\tx_s= " << x_s << endl;

	sravnenie(x, x_s);
	system("pause");
}
