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

//предыдущее решение:
float pRandom(double x, double x_s)
{
	return (x_s - x) / (1 + rand() % 1000);
}


//‘ормула ѕ»ƒ-регул€тора, используема€ дл€ расчета
//u(t) = P (t) + I (t) + D (t);
//P (t) = Kp * e (t);
//I (t) = I (t Ч 1) + Ki * e (t);
//D (t) = Kd * (e (t) Ч e (t Ч 1));
/*double P, D, I,error= x_s - x_cur, integral=0, derivative;
P = Kp*error;
integral += error*dt;
I = Ki*integral;
derivative = (x_cur-x_prev) / dt;
D = Kd * derivative;*/

/*double P, I=1, D, d;
P = x_cur;
I += Ki * x_cur;
if (abs(I / Ki) > x_s) { I = I / abs(I) * x_s * Ki; }
D = Kd * (x_cur - x_prev);
x_cur = x_prev ;
d = P + I + D;
if (abs(d) >= x_s) {d = d / abs(d) * x_s;}*/

/*double err_cur, err_prev, P, I, D;
err_cur = x_s - x_cur;
err_prev = x_s - x_prev;
P = Kc*(err_cur - err_prev);
I = Kc*delta_t / tI*err_cur;
D = Kc*tD / delta_t*(x_cur - 2 * (x_prev + x_prev2));*/

/*e[i] = sp[i] - pv[i]
P[i] = Kc * (e[i] - e[i - 1])
I[i] = Kc*delta_t / tauI * (e[i])
D[i] = Kc*tauD / delta_t * (pv[i] - 2 * (pv[i - 1]) + pv[i - 2])
op[i] = op[i - 1] + P[i] + I[i] + D[i]
if op[i] < oplo or op[i] > ophi:
# clip output
op[i] = max(oplo, min(ophi, op[i]))*/

double pid(double x_s, double x_cur, double Kp, double Ki, double Kd,  double x_prev)
{
	double P=0, I=0, D=0,err_cur= x_s - x_cur,err_prev=x_s-x_prev;
	P = Kp*err_cur;
	I += Ki*err_cur;
	D = Kd*(err_cur - err_prev);
	
		return P+I+D;
}

double pi(double x_s, double x_cur, double Kp, double Ki, double Kd, double x_prev)
{
	double P = 0, I = 0, D = 0, err_cur = x_s - x_cur, err_prev = x_s - x_prev;
	P = Kp*err_cur;
	I += Ki*err_cur;

	return P + I;
}

double pd(double x_s, double x_cur, double Kp, double Ki, double Kd, double x_prev)
{
	double P = 0, I = 0, D = 0, err_cur = x_s - x_cur, err_prev = x_s - x_prev;
	P = Kp*err_cur;
	D = Kd*(err_cur - err_prev);

	return P + D;
}

double id(double x_s, double x_cur, double Kp, double Ki, double Kd, double x_prev)
{
	double P = 0, I = 0, D = 0, err_cur = x_s - x_cur, err_prev = x_s - x_prev;
	I += Ki*err_cur;
	D = Kd*(err_cur - err_prev);

	return I + D;
}
double p(double x_s, double x_cur, double Kp, double Ki, double Kd, double x_prev)
{
	double P = 0, I = 0, D = 0, err_cur = x_s - x_cur, err_prev = x_s - x_prev;
	P = Kp*err_cur;

	return P;
}
double i(double x_s, double x_cur, double Kp, double Ki, double Kd, double x_prev)
{
	double P = 0, I = 0, D = 0, err_cur = x_s - x_cur, err_prev = x_s - x_prev;
	I += Ki*err_cur;

	return I;
}
/*double d(double x_s, double x_cur, double Kp, double Ki, double Kd, double x_prev) //все врем€ 0
{
	double P = 0, I = 0, D = 0, err_cur = x_s - x_cur, err_prev = x_s - x_prev;
	D = Kd*(err_cur - err_prev);

	return D;
}*/
void main()
{
	double Kp = 0.0005, Ki = 0.0003, Kd = 0.0003;
	double x_s = 100;
	double x_prev = 0, x_cur = 0;
	srand(time(NULL));

	int i = 0;
	while (x_s != x_prev)
	{
		x_cur = x_prev + pRandom(x_prev, x_s)*(1 + rand() % 1000);
		x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
		i++;
	}
	
	x_prev = 0, x_cur = 0;
	int iPID = 0;
	while (x_s != x_prev)//pid
	{
			x_cur = x_prev + pid(x_s, x_cur, Kp, Ki, Kd, x_prev)*(1 + rand() % 1000);
			x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
		iPID++;
	}
	
	x_prev = 0, x_cur = 0;

	int iPI = 0;
	while (x_s != x_prev)//pi
	{
		x_cur = x_prev + pi(x_s, x_cur, Kp, Ki, Kd, x_prev)*(1 + rand() % 1000);
		x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
		iPI++;
	}
	
	x_prev = 0, x_cur = 0;

	int iPD = 0;
	while (x_s != x_prev)//pd
	{
		x_cur = x_prev + pd(x_s, x_cur, Kp, Ki, Kd, x_prev)*(1 + rand() % 1000);
		x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
		iPD++;
	}

	x_prev = 0, x_cur = 0;

	/*int iID = 0;
	while (x_s != x_prev)//id
	{
		x_cur = x_prev + id(x_s, x_cur, Kp, Ki, Kd, x_prev)*(1 + rand() % 1000);
		x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
		iID++;
	}*/
	
	x_prev = 0, x_cur = 0;

	int iP = 0;
	while (x_s != x_prev)//p
	{
		x_cur = x_prev + p(x_s, x_cur, Kp, Ki, Kd, x_prev)*(1 + rand() % 1000);
		x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
		iP++;
	}
	
	/*x_prev = 0, x_cur = 0;

	int iI = 0;
	while (x_s != x_prev)//i
	{
		x_cur = x_prev + i(x_s, x_cur, Kp, Ki, Kd, x_prev)*(1 + rand() % 1000);
		x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
		iI++;
	}*/
	
	/*x_prev = 0, x_cur = 0;

	int iD = 0;
	while (x_s != x_prev)//d
	{
		x_cur = x_prev + d(x_s, x_cur, Kp, Ki, Kd, x_prev)*(1 + rand() % 1000);
		x_prev = x_cur;
		cout << setprecision(200) << x_cur << endl;
		iD++;
	}*/
	cout << "kol-vo iterciy(pRandom): " << i << endl;
	cout << "kol-vo iterciy(iPID): " << iPID << endl;
	cout << "kol-vo iterciy(iPI): " << iPI <<  endl;
	cout << "kol-vo iterciy(iPD): " << iPD << endl;
	//cout << "kol-vo iterciy(iID): " << iID << endl;//-----ооочень долго
	cout << "kol-vo iterciy(iP): " << iP << endl;  //1к+
	//cout << "kol-vo iterciy(iI): " << iI << endl; //-----ооочень долго
	//cout << "kol-vo iterciy(iD): " << iD << endl;  //все врем€ 0
	x_prev = 0, x_cur = 0;

	system("pause");
}