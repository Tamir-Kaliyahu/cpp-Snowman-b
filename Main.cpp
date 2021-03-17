/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	int run =1;
	const char yes = 'Y';
	const char no = 'N';
	int ans=0;
	std :: string choise;
	while (run==1)
	{	
	cout << "do you want to build a snowman? (Y/N)"<< endl; 
	cin >> choise;
	if((choise.length())==1)
	{
		if((char)choise.at(0)==no)
		{
			run =0;
			cout << "Thank you! Bye Bye!";
		}
		else
		if((char)choise.at(0)==yes)
		{
			ans = ariel::goSnowman();
			cout << "your snowman is ready! " << endl;
			cout << ariel::snowman(ans) << endl;
		}
		else
		cout << "not an option!" <<endl;
	}
	else
	{
		cout << "not a valid Choise!, enter one char! "<< endl;;
	}
   
	}
	return 0;
}
