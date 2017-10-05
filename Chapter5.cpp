// Chapter5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;
using std::string;

const int ArSize = 101;


void pause()
{
	std::cin.clear();
	std::cout << "\nPress enter to continue...";
	std::cin.ignore();
}

void clear()
{
	cin.clear();
	cout.clear();
	system("CLS");
}

int totalsum()
{
	clear();
	cout << "Enter the first integer: ";
	int x;
	cin >> x;
	cout << "Enter the second integer: ";
	int y;
	cin >> y;
	int total = 0;
	if (x < y)
	{
		for (int i = x; i <= y; i++)
			total += i;
	}
	else if (x > y)
	{
		for (int i = x; i >= y; --i)
			total += i;
	}
	else total = x + y;
	cout << "Sum: " << total;
	pause();
	return 0;
}

int formore()
{
	/*cout << "Enter the number of factorials to calculate: ";
	int ArSize;
	cin >> ArSize;*/
	std::array<long double, ArSize> factorials{ };
	factorials[1] = factorials[0] = 1LL;
	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];
	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << "\n";
	pause();
	return 0;
}

int cumusum(long long n)
{
	clear();
	cin.ignore(100, '\n');
	long long sum{ n };
	cout << "Enter 0 to quit.\n";
	for (;;)
	{
		cout << "Enter a number under 10000: ";
		int temp;
		cin >> temp;
		if (!(temp < -10000 || temp > 10000) && temp != 0)
		{
			sum += temp;
			cout << "Total sum: " << sum << "\n";
		}
		else if (temp == 0)
		{
			cout << "Total sum: " << sum << "\n";
			cin.get();
			pause();
			return 0;
		}
		else cumusum(0LL);
	}
	return 0;
}

int interest()
{
	clear();
	double dmon = 100;  // daphne's principal
	double din = .1;  // daphne's interest
	double dcur = dmon;  // daphne's current funds
	double cint = .05;  // cleo's interest (compound)
	double ccur = 100;  // cleo's current funds
	cout << "Daphne starts with $" << dcur << " at 10% simple interest.\n"
		<< "Cleo starts with $" << ccur << " at 5% compund interest.\n";
	cin.ignore();
	pause();
	int years = 0;
	while (dcur >= ccur)
	{
		years++;
		cout << "\nYear " << years << ":\n";
		dcur += dmon * din;
		ccur += ccur * cint;
		cout << "Daphne: " << dcur << "\nCleo: " << ccur << "\n";
	}
	cout << "\nIt took " << years << " years for Cleo's funds to overtake Daphne's\n";
	pause();
	return 0;
}

int cppfool()
{
	clear();
	string months[12]{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int sales[12]{ };
	int cnt = 0;
	for (string i : months)
	{
		cout << i << ": ";
		int sale;
		cin >> sale;
		sales[cnt] = sale;
		cnt++;
	}
	long total = 0;
	for (int i : sales)
		total += i;
	cout << "Total sales: " << total;
	pause();
	return 0;
}

int cppfooltwod()
{
	clear();
	int months[3][12]{ };
	string mos[12]{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	//for (int i = 0; i < 3; i++)
	/*{
		for (int f = 0; f < 12; f++)
		{
			months[i][f] = mos[f];
		}
	}*/
	int sales[12]{ };
	for (int f = 0; f < 3; f++)
	{
		int cnt = 0;
		cout << "Year " << f + 1 << ":\n";
		for (string i : mos)
		{
			cout << i << ": ";
			int sale;
			cin >> sale;
			months[f][cnt] = sale;
			cnt++;
		}
	}
	long totals[3]{ };
	long total = 0;
	for (int f = 0; f < 3; f++)
	{
		for (int i : months[f])
		{
			total += months[f][i];
			totals[f] += months[f][i];
		}
	}
	cout << "Year 1 sales: " << totals[0] << "\nYear 2 sales: " << totals[1] << "\nYear 3 sales: " << totals[2];
	cout << "\nTotal sales: " << total;
	pause();
	return 0;
}

int carray()
{
	clear();
	struct car
	{
		string make;
		int year;
	};
	cout << "How many cars do you wish to catalog? ";
	int count;
	cin >> count;
	car* cars = new car[count];
	for (int i = 0; i < count; i++)
	{
		cin.get();;
		cout << "Car #" << i + 1 << ":\n";
		cout << "Make: ";
		std::getline(cin, cars[i].make);
		cout << "Year: ";
		cin >> cars[i].year;
		cout << "\n";
	}
	cout << "Here is your colelction:\n";
	for (int i = 0; i < count; i++)
	{
		cout << cars[i].year << " " << cars[i].make << "\n";
	}
	delete[] cars;
	pause();
	return 0;
}

int asteree()
{
	clear();
	cout << "Enter number of rows: ";
	int rows = 0;
	cin >> rows;
	int f = rows;
	for (int y = 0; y < rows; y++)
	{
		f -= 1;
		for (int x = f; x > 0; --x)
			cout << ".";
		for (int l = f; l < rows; l++)
			cout << "*";
		cout << "\n";
	}
	pause();
	return 0;
}

int main()
{
	for (;;)
	{
		clear();
		cout << "0. Quit\n1. Sum of numers in between\n2. Factorials up to 100\n"
			 << "3. Cumulative Sum\n4. Interest\n5. Annual Book Sales\n"
			 << "6. 3 Years of Book Sales\n7. Car Array\n8. * Tree\n> ";
		int c;
		cin >> c;
		bool doo = true;
		if (c == 3) doo = false;
		if (c == 0) break;
		if (c == 1) c = totalsum();
		if (c == 2) c = formore();
		if (c == 3) c = cumusum(0LL);
		if (c == 4) c = interest();
		if (c == 5) c = cppfool();
		if (c == 6) c = cppfooltwod();
		if (c == 7) c = carray();
		if (c == 8) c = asteree();
		if (doo) cin.ignore(100, '\n');
	}
	pause();
	return 0;
}

