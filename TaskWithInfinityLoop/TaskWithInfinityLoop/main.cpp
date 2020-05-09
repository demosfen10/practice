#include<iostream>
#include<time.h>
#include<random>
#include<Math.h>
#include<Windows.h>
#include <iomanip>


using namespace std;
//в бесконечном цикле *** типа while () {xi = x_(i - 1) + ...}
//x_i = x_(i-1) + p() * random(t)
// x_i  ---> x_s

float p(double x, double x_s)
{
	return (x_s - x) / (1 + rand() % 1000);
}

void main()
{
	double x_s = 100;
	double x_prev = 0, x_cur = 0;
	srand(time(NULL));
	while (x_s != x_prev)
	{
		x_cur=x_prev+p(x_prev,x_s)*(1 + rand() % 1000);
		x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
	}
	system("pause");
}