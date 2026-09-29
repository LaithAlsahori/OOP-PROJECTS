#include<iostream>
using namespace std;
class ClsShop
{
private:

	string _Name;
	string _PhoneNumber;
	string _Address;

public:

	ClsShop(string Name,string PhoneNumber,string Address)
	{
		_Name = Name;
		_PhoneNumber = PhoneNumber;
		_Address = Address;
	}

	void SetTheName(string Name)
	{
		_Name = Name;
	}
	string GetTheName()
	{
		return _Name;
	}

	void SetThePhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}
	string GetThePhoneNumber()
	{
		return _PhoneNumber;
	}

	void SetTheAddress(string Address)
	{
		_Address = Address;
	}
	string GetTheAddress()
	{
		return _Address;
	}

	__declspec(property(get = GetTheName, put = SetTheName))string Name;
	__declspec(property(get = GetThePhoneNumber, put = SetThePhoneNumber))string PhoneNumber;
	__declspec(property(get = GetTheAddress, put = SetTheAddress))string Address;

	void FunPrint()
	{
		cout << "THE DATA OF SHOP .... \n";
		cout << "THE NAME OF SHOP : " << Name;
		cout << "\nTHE PHONE NUMBER OF SHOP : " << PhoneNumber;
		cout << "\nTHE ADDRESS OF SHOP : " << Address;
	}

	class ClsEmployee
	{
	private:

		string _Name;
		string _PhoneNumber;
		int _Salary;

	public:

		ClsEmployee(string Name, string PhoneNumber, int Salary)
		{
			_Name = Name;
			_PhoneNumber = PhoneNumber;
			_Salary = Salary;
		}

		void SetTheName(string Name)
		{
			_Name = Name;
		}
		string GetTheName()
		{
			return _Name;
		}

		void SetThePhoneNumber(string PhoneNumber)
		{
			_PhoneNumber = PhoneNumber;
		}
		string GetThePhoneNumber()
		{
			return _PhoneNumber;
		}

		void SetTheSalary(int Salary)
		{
			_Salary = Salary;
		}
		int GetTheSalary()
		{
			return _Salary;
		}

		__declspec(property(get = GetTheName, put = SetTheName))string Name;
		__declspec(property(get = GetThePhoneNumber, put = SetThePhoneNumber))string PhoneNumber;
		__declspec(property(get = GetTheSalary, put = SetTheSalary))int Salary;

		void FunPrint()
		{
			cout << "THE DATA OF EMPLYEE .... \n";
			cout << "THE NAME OF EMPLOYEE : " << Name;
			cout << "\n THE PHONE NUMBER OF EMPLOYEE : " << PhoneNumber;
			cout << "\nTHE SALARY OF EMPLOYEE : " << Salary;
		}

		class ClsTest
		{

		};
	};
};
int main()
{
	ClsShop Shop("NiceShop","7999"," one street");
	


	Shop.FunPrint();


	
	return 0;
}