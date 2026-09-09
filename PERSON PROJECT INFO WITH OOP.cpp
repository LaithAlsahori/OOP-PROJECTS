#include<iostream>
using namespace std;
class ClsPersonInfo
{
private:

	short _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;

public:

	ClsPersonInfo(short ID,string FirstName,string LastName,string Email,string PhoneNumber)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}

	short GetID()
	{
		return _ID;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	void SetPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}

	string GetPhoneNumber()
	{
		return _PhoneNumber;
	}

	__declspec(property(get = GetID))short ID;
	__declspec(property(get = GetFirstName , put = SetFirstName))string FirstName;
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;
	__declspec(property(get = GetEmail, put = SetEmail))string Email;
	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber))string PhoneNumber;

	string FunFullName()
	{
		return _FirstName + " " + _LastName;
	}

	void FunPrintTheInfo()
	{
		cout << "INFO : ";
		cout << "\n============================";
		cout << "\nTHE ID : " << _ID;
		cout << "\nTHE FIRST NAME : " << _FirstName;
		cout << "\nTHE LAST NAME : " << _LastName;
		cout << "\nTHE FULL NAME : " << FunFullName();
		cout << "\nTHE EMAIL : " << _Email;
		cout << "\nTHE PHONE NUMBER :" << _PhoneNumber;
		cout << "\n============================\n";
	}

	void FunSendMassage(string Subject , string Body)
	{
		cout << "the following massage sent successufully to Email : " << _Email;
		cout << "\nsubject : " << Subject;
		cout << "\nbody : " << Body;
	}

	void FunSendSMS(string SMS)
	{
		cout << "\nthe following SMS sent successfully to phone number : " << _PhoneNumber;
		cout << endl <<SMS;
	}
};
int main()
{
	ClsPersonInfo PersonInfo(101,"laith","mousa","laith@gmail.com","07999");

	PersonInfo.FunPrintTheInfo();

	PersonInfo.FunSendMassage("Hi", "How are you ? ");

	cout << endl;

	PersonInfo.FunSendSMS("How are you ? ");
	return 0;
}