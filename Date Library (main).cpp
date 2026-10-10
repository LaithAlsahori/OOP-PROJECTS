#include<iostream>
#include"ClsDate.h"
using namespace std;
int main()
{

	ClsDate Date1(18, 9, 2005);
	ClsDate Date2(10,9,2005);
	
	cout << Date1.FunIsDate1EqualDate2(Date1, Date2);

	return 0;
}