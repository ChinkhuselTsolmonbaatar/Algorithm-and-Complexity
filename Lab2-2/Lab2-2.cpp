#include<iostream>
#include<cmath>
#include<vector>
#include "Benchmark.h"
std::vector<long long> Divisors2(long long o)
{
	std::vector<long long> v;
	long long div = sqrt(o);
	for (long long i = 1; i <= div; i++)
	{
		if (o % i == 0)
			v.push_back(i);

	}
	for (long long i = div; i > 1; i--)
	{
		if (o % i == 0)
			v.push_back(o / i);
	}
	return v;
}
std::vector<long long> Divisors1(long long o)
{
	std::vector<long long> v;
	for (long long i = 1; i <= o; i++)
	{
		if (o % i == 0)
			v.push_back(i);

	}
	return v;
}
int main()
{
	std::cout << "Enter an integer number:";
	long long number;
	std::cin >> number;
	Benchmark <std::chrono::microseconds> t;
	std::vector<long long> div = Divisors1(number);
	int duration = t.elapsed();
	std::cout << "Used Divisors1 function: ";
	std::cout << duration << " " << std::endl;

	Benchmark <std::chrono::microseconds> t1;
	 div = Divisors2(number);
	duration = t1.elapsed();
	std::cout << "Used Divisors2 function: ";
	std::cout << duration << " "<<std::endl;
	
	return 0;
}