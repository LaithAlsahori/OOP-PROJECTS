#include<iostream>
using namespace std;
class ClsPerson
{
private:

	string _FirstName;
	string _LastName;
	string _Email;
	int _PhoneNumber;
	short _ID;

public:

	ClsPerson(string FirstName, string LastName, string Email, int PhoneNumber, short ID)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
		_ID = ID;
	}

	void SetTheFristName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string GetTheFirstName()
	{
		return _FirstName;
	}

	void SetTheLastName(string LastName)
	{
		_LastName = LastName;
	}
	string GetTheLastName()
	{
		return _LastName;
	}

	void SetTheEmail(string Email)
	{
		_Email = Email;
	}
	string GetTheEmail()
	{
		return _Email;
	}

	void SetThePhoneNumber(int PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}
	int GetThePhoneNumber()
	{
		return _PhoneNumber;
	}

	short GetTheID()
	{
		return _ID;
	}

	string FunFullName()
	{
		return _FirstName + " " + _LastName;
	}

	__declspec(property(get = GetTheFirstName, put = SetTheFristName))string FirstName;
	__declspec(property(get = GetTheLastName, put = SetTheLastName))string LastName;
	__declspec(property(get = GetTheEmail, put = SetTheEmail))string Email;
	__declspec(property(get = GetThePhoneNumber, put = SetThePhoneNumber))int PhoneNumber;
	__declspec(property(get = GetTheID)) short ID;

	void FunPrintTheData_Person()
	{
		cout << "INFO ... ";
		cout << "\n===================================";
		cout << "\nTHE FIRST NAME : " << FirstName;
		cout << "\nTHE LAST NAME : " << LastName;
		cout << "\nFULL NAME : " << FunFullName();
		cout << "\n THE EMAIL : " << Email;
		cout << "\nTHE PHONE NUMBER : " << PhoneNumber;
		cout << "\nTHE ID : " << ID;
		cout << "\n===================================";
	}

};
class ClsEmplyee : public ClsPerson
{
private:

	int _Salary;
	string _Title;
	string _Department;
	string _MainProgrammingLanguage;

public:

	ClsEmplyee(string FirstName, string LastName, string Email, int PhoneNumber, short ID
		, int Salary, string Title, string Department, string MainProgrammingLanguage) :
		ClsPerson(FirstName, LastName, Email, PhoneNumber, ID)
	{
		_Salary = Salary;
		_Title = Title;
		_Department = Department;
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	void SetTheSalary(int Salary)
	{
		_Salary = Salary;
	}
	int GetTheSalary()
	{
		return _Salary;
	}

	void SetTheTitle(string Title)
	{
		_Title = Title;
	}
	string GetTheTitle()
	{
		return _Title;
	}

	void SetTheDepartment(string Department)
	{
		_Department = Department;
	}
	string GetTheDepartment()
	{
		return _Department;
	}

	void SetTheMainProgrammingLanguage(string MainProgrammingLanguage)
	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}
	string GetTheMainProgrammingLanguage()
	{
		return _MainProgrammingLanguage;
	}

	__declspec(property(get = GetTheSalary, put = SetTheSalary))int Salary;
	__declspec(property(get = GetTheTitle, put = SetTheTitle))string Title;
	__declspec(property(get = GetTheDepartment, put = SetTheDepartment))string Department;
	__declspec(property(get = GetTheMainProgrammingLanguage, put = SetTheMainProgrammingLanguage))string MainProgrammingLanguage;


	void FunPrintTheData()
	{
		cout << "INFO ... ";
		cout << "\n===================================";
		cout << "\nTHE FIRST NAME : " << FirstName;
		cout << "\nTHE LAST NAME : " << LastName;
		cout << "\nFULL NAME : " << FunFullName();
		cout << "\n THE EMAIL : " << Email;
		cout << "\nTHE PHONE NUMBER : " << PhoneNumber;
		cout << "\nTHE ID : " << ID;
		cout << "\nTHE SALARY : " << Salary;
		cout << "\nTHE TITLE : " << Title;
		cout << "\nTHE DEPARTMENT : " << Department;
		cout << "\nTHE PROGRAMMING LANGUGE : " << MainProgrammingLanguage;
		cout << "\n===================================";
	}
};
int main()
{
	ClsEmplyee Emplyee("laith", "alsahory", "laith@gmail.com", 7999, 101, 5000, "SE", "IT", "C++");

	Emplyee.FunPrintTheData();

	return 0;
}