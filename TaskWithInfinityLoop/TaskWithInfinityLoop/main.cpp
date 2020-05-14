#include<iostream>
#include<time.h>
#include<random>
#include<Math.h>
#include<Windows.h>
#include <iomanip>
#include<fstream> 
#include<string>
#include<list>

using namespace std;
//в бесконечном цикле *** типа while () {xi = x_(i - 1) + ...}
//x_i = x_(i-1) + p() * random(t)
// x_i  ---> x_s

//предыдущее решение:
float pRandom(double x, double x_s)
{
	return (x_s - x) / (1 + rand() % 1000);
}


//Формула ПИД-регулятора, используемая для расчета
//u(t) = P (t) + I (t) + D (t);
//P (t) = Kp * e (t);
//I (t) = I (t — 1) + Ki * e (t);
//D (t) = Kd * (e (t) — e (t — 1));


double pid(double x_s, double x_cur, double Kp, double Ki, double Kd,  double x_prev)
{
	double P=0, I=0, D=0,err_cur= x_s - x_cur,err_prev=x_s-x_prev;
	P = Kp*err_cur;
	I += Ki*err_cur;
	D = Kd*(err_cur - err_prev);
	
		return P+I+D;
}


void main()
{
	setlocale(LC_ALL, "");
	double Kp = 0.0005, Ki = 0.0003, Kd = 0.0003;
	double x_s = 100;
	double x_prev = 0, x_cur = 0;
	srand(time(NULL));
	int allCicl;
	cout << "Сколько раз хотите прогнать все значения?" << endl;
	cin >> allCicl;
	string *bestResult=new string[allCicl];
	for ( int k = 0; k < allCicl; k++) {//делаем несколько проверок
		int iRandom = 0;
		ofstream out;
		out.open("pRandom.txt");
		if(out.is_open())
		while (x_s != x_prev)//pRandom
		{
			x_cur = x_prev + pRandom(x_prev, x_s)*(1 + rand() % 1000);
			x_prev = x_cur;
			out << setprecision(200) << x_cur << endl;
			iRandom++;
		}
		out.close();

		x_prev = 0, x_cur = 0;
		int iPID = 0;
		ofstream outPID;
		outPID.open("pid.txt");
		if(outPID.is_open())
		while (x_s != x_prev)//pid
		{
			x_cur = x_prev + pid(x_s, x_cur, Kp, Ki, Kd, x_prev)*(1 + rand() % 1000);
			x_prev = x_cur;
			outPID << setprecision(200) << x_cur << endl;
			iPID++;
		}
		outPID.close();

		x_prev = 0, x_cur = 0;
		int iPI = 0;
		ofstream outPI;
		outPI.open("pi.txt");
		if (outPI.is_open())
		while (x_s != x_prev)//pi
		{
			x_cur = x_prev + pid(x_s, x_cur, Kp, Ki, 0, x_prev)*(1 + rand() % 1000);
			x_prev = x_cur;
			outPI << setprecision(200) << x_cur << endl;
			iPI++;
		}
		 outPI.close();

		x_prev = 0, x_cur = 0;
		int iPD = 0;
		ofstream outPD;
		outPD.open("pd.txt");
		if (outPD.is_open())
		while (x_s != x_prev)//pd
		{
			x_cur = x_prev + pid(x_s, x_cur, Kp, 0, Kd, x_prev)*(1 + rand() % 1000);
			x_prev = x_cur;
			outPD << setprecision(200) << x_cur << endl;
			iPD++;
		}
		outPD.close();
		
		//четыре next метода описал, но не использую тк высчитываются очень долго...и не рациональны!
		/*x_prev = 0, x_cur = 0;
		int iID = 0;
		ofstream outID;
		outID.open("id.txt");
		if (outID.is_open())
		while (x_s != x_prev)//id
		{
			x_cur = x_prev + pid(x_s, x_cur, 0, Ki, Kd, x_prev)*(1 + rand() % 1000);
			x_prev = x_cur;
			outID << setprecision(200) << x_cur << endl;
			iID++;
		}
		outID.close();*/

		/*x_prev = 0, x_cur = 0;
		int iP = 0;
		ofstream outP;
		outPI.open("p.txt");
		if (outP.is_open())
		while (x_s != x_prev)//p
		{
			x_cur = x_prev + pid(x_s, x_cur, Kp, 0, 0, x_prev)*(1 + rand() % 1000);
			x_prev = x_cur;
			outP << setprecision(200) << x_cur << endl;
			iP++;
		}
		outP.close();*/

		/*x_prev = 0, x_cur = 0;
		int iI = 0;
		ofstream outI;
		outI.open("i.txt");
		if (outI.is_open())
		while (x_s != x_prev)//i
		{
			x_cur = x_prev + pid(x_s, x_cur, 0, Ki, 0, x_prev)*(1 + rand() % 1000);
			x_prev = x_cur;
			outI << setprecision(200) << x_cur << endl;
			iI++;
		}
		outI.close();*/
		
		/*x_prev = 0, x_cur = 0;
		int iD = 0;
		while (x_s != x_prev)//d
		{
			x_cur = x_prev + pid(x_s, x_cur, 0, 0, Kd, x_prev)*(1 + rand() % 1000);
			x_prev = x_cur;
			cout << setprecision(200) << x_cur << endl;
			iD++;
		}*/
		
		cout << "kol-vo iterciy(Random): " << iRandom << endl;
		cout << "\t";
		cout << "kol-vo iterciy(PID): " << iPID << endl;
		cout << "\t";
		cout << "kol-vo iterciy(PI): " << iPI << endl;
		cout << "\t";
		cout << "kol-vo iterciy(PD): " << iPD << endl;
		cout << "\t";
		//cout << "kol-vo iterciy(ID): " << iID << endl;//-----ооочень долго
		//cout << "kol-vo iterciy(P): " << iP << endl;  //1к+
		//cout << "kol-vo iterciy(I): " << iI << endl; //-----ооочень долго
		//cout << "kol-vo iterciy(D): " << iD << endl;  //все время 0
		const int masSize = 4;
		int mass[masSize] = { iRandom,iPID,iPI,iPD};
		string arr[masSize] = {"Random","PID","PI","PD"};
		int max = 0, min = 0;
		string sMax = "", sMin = "";
		
		for (int z = 0; z < masSize; z++)
		{
			if (mass[z] > max) {
				max = mass[z];
				min = mass[z];
				sMax = arr[z];
			}
		}
		for (int z = 0; z < masSize; z++)
		{
			if (mass[z] < min)
			{
				min = mass[z];
				sMin = arr[z];
			}
		}
		cout << "-------------------------------" << endl;
		cout << "max: " << max << " :(" << sMax << ") \tmin: " << min << " :(" << sMin << ") <---the best one" << endl;
		cout << endl;
		x_prev = 0, x_cur = 0;
		bestResult[k] = sMin;
	}
	int Random=0, PID=0, PI=0, PD=0;
	for (int i = 0; i < allCicl; i++)
	{
		string bR = bestResult[i];
		char cstr[sizeof(bR) + 1];
		strcpy(cstr, bR.c_str());
		int sr = strcmp(cstr, "Random");

		if (sr == 0)
		{
			Random++;
		}
		else
		{
			int sr = strcmp(cstr, "PID");
			if (sr == 0)
			{
				PID++;
			}
			else
			{
				int sr = strcmp(cstr, "PI");
				if (sr == 0)
				{
					PI++;
				}
				else
				{
					int sr = strcmp(cstr, "PD");
					if (sr == 0)
					{
						PD++;
					}

				}
			}
		}
	}
	cout << endl;
	cout << "количество повторений как TheBestResult из " << allCicl <<" --->"<< endl;
	cout <<"Random: "<< Random<<" \tPID: "<<PID <<" \tPI: "<< PI << "\tPD: " << PD << endl;
		
	system("pause");
}