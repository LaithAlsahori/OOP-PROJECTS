#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cmath>
#include "ClsString.h"

using namespace std;

class ClsDate
{
private:
	short _Day;
	short _Month;
	short _Year;

public:
	ClsDate()
	{
		time_t T = time(0);
		tm* Now = localtime(&T);

		_Day = Now->tm_mday;
		_Month = Now->tm_mon + 1;
		_Year = Now->tm_year + 1900;
	}

	ClsDate(string Date)
	{
		vector<string> vDate = ClsString::Split(Date, "/");

		if (vDate.size() == 3)
		{
			_Day = stoi(vDate[0]);
			_Month = stoi(vDate[1]);
			_Year = stoi(vDate[2]);
		}
		else
		{
			_Day = 0;
			_Month = 0;
			_Year = 0;
		}

		if (!IsValid(*this))
		{
			_Day = 0;
			_Month = 0;
			_Year = 0;
		}
	}

	ClsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;

		if (!IsValid(*this))
		{
			_Day = 0;
			_Month = 0;
			_Year = 0;
		}
	}

	ClsDate(short Days, short Year)
	{
		vector<short> vDate = ConvertDaysToDate(Days, Year);

		_Day = vDate[0];
		_Month = vDate[1];
		_Year = vDate[2];
	}

	void SetDay(short Day) { _Day = Day; }
	short GetDay() { return _Day; }

	void SetMonth(short Month) { _Month = Month; }
	short GetMonth() { return _Month; }

	void SetYear(short Year) { _Year = Year; }
	short GetYear() { return _Year; }

	__declspec(property(get = GetDay, put = SetDay)) short Day;
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	static bool IsLeapYear(short Year)
	{
		return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month == 2)
		{
			return (IsLeapYear(Year)) ? 29 : 28;
		}
		else if (Month == 1 || Month == 3 || Month == 5 ||
			Month == 7 || Month == 8 || Month == 10 ||
			Month == 12)
		{
			return 31;
		}
		return 30;
	}
	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static bool IsValid(ClsDate Date)
	{
		if (Date._Year >= 1)
		{
			if (Date._Month >= 1 && Date._Month <= 12)
			{
				int Days = NumberOfDaysInMonth(Date._Month, Date._Year);

				if (Days >= Date._Day && Date._Day >= 1)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool IsValid()
	{
		return IsValid(*this);
	}

	static vector<short> ConvertDaysToDate(short Days, short Year)
	{
		vector<short> vDate(3);
		short Month = 1;
		short Day = 1;

		while (Days >= 365)
		{
			if (IsLeapYear(Year))
			{
				Days -= 366;
				Year++;
			}
			else
			{
				Days -= 365;
				Year++;
			}
		}

		while (Days > NumberOfDaysInMonth(Month, Year))
		{
			Days -= NumberOfDaysInMonth(Month, Year);
			Month++;

			if (Month > 12)
			{
				Month = 1;
				Year++;
			}
		}

		Day = Days == 0 ? 1 : Days;

		vDate[0] = Day;
		vDate[1] = Month;
		vDate[2] = Year;

		return vDate;
	}
	vector<short> ConvertDaysToDate(short Days)
	{
		return ConvertDaysToDate(Days, _Year);
	}

	static short GetNumberOfDay(short Day, short Month, short Year)
	{
		short A = (14 - Month) / 12;
		short Y = Year - A;
		short M = Month + (12 * A) - 2;

		short D = (Day + Y + (Y / 4) - (Y / 100) +
			(Y / 400) + ((31 * M) / 12)) % 7;

		return (D == 0) ? 1 : D + 1;
	}
	short GetNumberOfDay()
	{
		return GetNumberOfDay(_Day, _Month, _Year);
	}

	static string NameOfMonth(short Month)
	{
		switch (Month)
		{
		case 1: return "JANUARY";
		case 2: return "FEBRUARY";
		case 3: return "MARCH";
		case 4: return "APRIL";
		case 5: return "MAY";
		case 6: return "JUNE";
		case 7: return "JULY";
		case 8: return "AUGUST";
		case 9: return "SEPTEMBER";
		case 10: return "OCTOBER";
		case 11: return "NOVEMBER";
		case 12: return "DECEMBER";
		default: return "INVALID MONTH";
		}
	}
	string NameOfMonth()
	{
		return NameOfMonth(_Month);
	}

	static void MonthCalender(ClsDate Date, bool StartFromDayOne = true)
	{
		short Space = 0;

		cout << "<-------------[" << NameOfMonth(Date._Month) << "]------------->\n";
		cout << "SUN   MON   TUE   WED   THU   FRI   SAT\n";

		if (StartFromDayOne)
		{
			Space = GetNumberOfDay(1, Date._Month, Date._Year);
			while (Space > 1)
			{
				cout << "      ";
				Space--;
			}
			for (int i = 1; i <= NumberOfDaysInMonth(Date._Month, Date._Year); i++)
			{
				cout << setw(2) << i << "    ";

				if (GetNumberOfDay(i, Date._Month, Date._Year) == 7)
				{
					cout << endl;
				}
			}
		}
		else
		{
			Space = GetNumberOfDay(Date._Day, Date._Month, Date._Year);
			while (Space > 1)
			{
				cout << "      ";
				Space--;
			}
			for (int i = Date._Day; i <= NumberOfDaysInMonth(Date._Month, Date._Year); i++)
			{
				cout << setw(2) << i << "    ";

				if (GetNumberOfDay(i, Date._Month, Date._Year) == 7)
				{
					cout << endl;
				}
			}
		}
		cout << "\n<-------------------------------------->\n";
	}
	void MonthCalender(bool StartFromDayOne = true)
	{
		MonthCalender(*this, StartFromDayOne);
	}

	static void YearCalender(ClsDate Date)
	{
		for (int i = 1; i <= 12; i++)
		{
			Date._Month = i;
			MonthCalender(Date, true);
			cout << endl;
		}
	}
	void YearCalender()
	{
		YearCalender(*this);
	}

	static int CalculateAgeFromDate(ClsDate Date, bool AddEndDay = 1)
	{
		return ConvertDateToDays(Date, AddEndDay);
	}
	int CalculateAgeFromDate(bool AddEndDay = 1)
	{
		return CalculateAgeFromDate(*this, AddEndDay);
	}

	static void Print(ClsDate Date)
	{
		cout << to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	void Print()
	{
		Print(*this);
	}

	static bool IsDate1BeforDate2(ClsDate Date1, ClsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true :
			(Date1._Year == Date2._Year) ?
			((Date1._Month < Date2._Month) ? true :
				(Date1._Month == Date2._Month) ?
				((Date1._Day < Date2._Day) ? true : false) : false) : false;
	}
	bool IsDate1BeforDate2(ClsDate Date2)
	{
		return IsDate1BeforDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(ClsDate Date1, ClsDate Date2)
	{
		return (Date1._Year == Date2._Year) ?
			((Date1._Month == Date2._Month) ?
				((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}
	bool IsDate1EqualDate2(ClsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static ClsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return ClsDate(Day, Month, Year);
	}

	static int NumberOfDaysInYear(short Year)
	{
		return (IsLeapYear(Year)) ? 366 : 365;
	}
	int NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static int NumberOfHoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}
	int NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);
	}

	static int NumberOfHoursInYear(short Year)
	{
		if (IsLeapYear(Year))
		{
			return 366 * 24;
		}
		else
		{
			return 365 * 24;
		}
	}
	int NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static int NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);
	}

	static int NumberOfSecondsInMonth(short Month, short Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);
	}

	static int DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		int TotalDays = 0;

		for (int i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);
		}

		TotalDays += Day;

		return TotalDays;
	}
	static int DaysFromTheBeginingOfTheYear(ClsDate Date)
	{
		int TotalDays = 0;

		for (int i = 1; i < Date._Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Date._Year);
		}

		TotalDays += Date._Day;

		return TotalDays;
	}
	int DaysFromTheBeginingOfTheYear()
	{
		return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}

	static ClsDate OrderOfDateUsingDays(int NumberOfDays, short Year)
	{
		short Month = 1;
		short Day = 1;

		while (true)
		{
			short DaysInYear = IsLeapYear(Year) ? 366 : 365;
			if (NumberOfDays > DaysInYear)
			{
				NumberOfDays -= DaysInYear;
				Year++;
			}
			else
			{
				break;
			}
		}

		while (true)
		{
			short DaysInMonth = NumberOfDaysInMonth(Month, Year);
			if (NumberOfDays > DaysInMonth)
			{
				NumberOfDays -= DaysInMonth;
				Month++;

				if (Month > 12)
				{
					Month = 1;
					Year++;
				}
			}
			else
			{
				break;
			}
		}

		Day = (NumberOfDays == 0) ? 1 : NumberOfDays;

		return ClsDate(Day, Month, Year);
	}
	ClsDate OrderOfDateUsingDays(int NumberOfDays)
	{
		return OrderOfDateUsingDays(NumberOfDays, _Year);
	}

	void AddDays(int Days)
	{
		while (Days > 0)
		{
			if (NumberOfDaysInMonth(_Month, _Year) >= _Day)
			{
				_Day++;
				Days--;

				if (NumberOfDaysInMonth(_Month, _Year) < _Day)
				{
					_Day = 1;
					_Month++;

					if (_Month > 12)
					{
						_Year++;
						_Month = 1;
						_Day = 1;
					}
				}
			}
		}
	}

	static bool IsLastDayInMonth(ClsDate Date)
	{
		return NumberOfDaysInMonth(Date._Month, Date._Year) == Date._Day;
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}
	static bool IsLastDayInMonth(short Day, ClsDate Date)
	{
		return NumberOfDaysInMonth(Date._Month, Date._Year) == Day;
	}
	bool IsLastDayInMonth(short Day)
	{
		return IsLastDayInMonth(Day, *this);
	}

	static bool IsLastMonthInYear(ClsDate Date)
	{
		return Date._Month == 12;
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(*this);
	}
	static bool IsLastMonthInYear(short Month)
	{
		return Month == 12;
	}

	static ClsDate AddOneDay(ClsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}
	void AddOneDay()
	{
		*this = AddOneDay(*this);
	}

	static void SwapTowDates(ClsDate& Date1, ClsDate& Date2)
	{
		ClsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}
	void SwapTowDates(ClsDate& Date2)
	{
		SwapTowDates(*this, Date2);
	}

	static ClsDate IncreaseDateByOneDay(ClsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}
	ClsDate IncreaseDateByOneDay()
	{
		return IncreaseDateByOneDay(*this);
	}

	static int ConvertDateToDays(ClsDate Date, bool AddEndDay = 1)
	{
		int CounterOfDays = 0;
		ClsDate Now = GetSystemDate();


		while (IsDate1BeforDate2(Date, Now))
		{
			CounterOfDays++;
			Date = IncreaseDateByOneDay(Date);
		}

		if (AddEndDay)
		{
			return CounterOfDays + 1;
		}

		return CounterOfDays;
	}
	int ConvertDateToDays(bool AddEndDay = 1)
	{
		return ConvertDateToDays(*this, AddEndDay);
	}

	static int GetDeffirentDays(ClsDate Date1, ClsDate Date2)
	{
		int TheDeffirent = 0;

		TheDeffirent = abs(ConvertDateToDays(Date1, 1) - ConvertDateToDays(Date2, 1));

		return TheDeffirent;
	}
	int GetDeffirentDays(ClsDate Date2)
	{
		return GetDeffirentDays(*this, Date2);
	}

	static ClsDate IncreaseDateOneWeek(ClsDate& Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}
	ClsDate IncreaseDateOneWeek()
	{
		return IncreaseDateOneWeek(*this);
	}

	static ClsDate IncreaseDateXweek(ClsDate& Date, short NumberOfWeeks)
	{
		for (int i = 1; i <= NumberOfWeeks; i++)
		{
			Date = IncreaseDateOneWeek(Date);
		}

		return Date;
	}
	ClsDate IncreaseDateXweek(short NumberOfWeeks)
	{
		return IncreaseDateXweek(*this, NumberOfWeeks);
	}

	static ClsDate IncreaseOneMonth(ClsDate& Date)
	{

		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date.Month++;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}
	ClsDate IncreaseOneMonth()
	{
		return IncreaseOneMonth(*this);
	}

	static ClsDate IncreaseXmonth(ClsDate& Date, short NumberOfMonth)
	{
		for (int i = 1; i <= NumberOfMonth; i++)
		{
			Date = IncreaseOneMonth(Date);
		}

		return Date;
	}
	ClsDate IncreaseXmonth(short NumberOfMonth)
	{
		return IncreaseXmonth(*this, NumberOfMonth);
	}

	static ClsDate IncreaseXdays(ClsDate& Date, short NumberOfdays)
	{
		for (int i = 1; i <= NumberOfdays; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}
	ClsDate IncreaseXdays(short NumberOfdays)
	{
		return IncreaseXdays(*this, NumberOfdays);
	}

	static ClsDate IncreaseOneYear(ClsDate& Date)
	{
		Date._Year++;

		return Date;
	}
	ClsDate IncreaseOneYear()
	{
		return IncreaseOneYear(*this);
	}

	static ClsDate IncreaseXyear(ClsDate& Date, short NumberOfYears)
	{
		for (int i = 1; i <= NumberOfYears; i++)
		{
			Date = IncreaseOneYear(Date);
		}

		return Date;
	}
	ClsDate IncreaseXyear(short NumberOfYears)
	{
		return IncreaseXyear(*this, NumberOfYears);
	}

	static ClsDate IncreaseOneDecade(ClsDate& Date)
	{
		Date._Year += 10;

		return Date;
	}
	ClsDate IncreaseOneDecade()
	{
		return IncreaseOneDecade(*this);
	}

	static ClsDate IncreaseXdecade(ClsDate& Date, short NumberOfDecade)
	{
		for (int i = 1; i <= NumberOfDecade; i++)
		{
			Date = IncreaseOneDecade(Date);
		}

		return Date;
	}
	ClsDate IncreaseXdecade(short NumberOfDecade)
	{
		return IncreaseXdecade(*this, NumberOfDecade);
	}

	static ClsDate IncreaseOneCentury(ClsDate& Date)
	{
		Date._Year += 100;

		return Date;
	}
	ClsDate IncreaseOneCentury()
	{
		return IncreaseOneCentury(*this);
	}

	static ClsDate IncreaseOneMillennium(ClsDate& Date)
	{
		Date._Year += 1000;

		return Date;
	}
	ClsDate IncreaseOneMillennium()
	{
		return IncreaseOneMillennium(*this);
	}

	static ClsDate DecreaseDateOneDay(ClsDate Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Year--;
				Date._Day = NumberOfDaysInMonth(Date._Month, Date._Year);
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInMonth(Date._Month, Date._Year);
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}
	ClsDate DecreaseDateOneDay()
	{
		return DecreaseDateOneDay(*this);
	}

	static ClsDate DecreaseDateOneWeek(ClsDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateOneDay(Date);
		}

		return Date;
	}
	ClsDate DecreaseDateOneWeek()
	{
		return DecreaseDateOneWeek(*this);
	}

	static ClsDate DecreaseDateXweek(ClsDate Date, short NumberOfWeeks)
	{
		for (int i = 1; i <= NumberOfWeeks; i++)
		{
			Date = DecreaseDateOneWeek(Date);
		}

		return Date;
	}
	ClsDate DecreaseDateXweek(short NumberOfWeeks)
	{
		return DecreaseDateXweek(*this, NumberOfWeeks);
	}

	static ClsDate DecreaseDateOneMonth(ClsDate& Date)
	{

		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
			Date.Month--;

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}


		return Date;
	}
	ClsDate DecreaseDateOneMonth()
	{
		return DecreaseDateOneMonth(*this);
	}

	static ClsDate DecreaseDateXmonth(ClsDate& Date, short NumberOfMonth)
	{
		for (int i = 1; i <= NumberOfMonth; i++)
		{
			Date = DecreaseDateOneMonth(Date);
		}

		return Date;
	}
	ClsDate DecreaseDateXmonth(short NumberOfMonth)
	{
		return DecreaseDateXmonth(*this, NumberOfMonth);
	}

	static ClsDate DecreaseDateXday(ClsDate Date, short NumberOfdays)
	{
		for (int i = 1; i <= NumberOfdays; i++)
		{
			Date = DecreaseDateOneMonth(Date);
		}

		return Date;
	}
	ClsDate DecreaseDateXday(short NumberOfdays)
	{
		return DecreaseDateXday(*this, NumberOfdays);
	}

	static ClsDate DecreaseOneYear(ClsDate& Date)
	{
		Date._Year--;

		return Date;
	}
	ClsDate DecreaseOneYear()
	{
		return DecreaseOneYear(*this);
	}

	static ClsDate DecreaseXyear(ClsDate& Date, short NumberOfYears)
	{
		for (int i = 1; i <= NumberOfYears; i++)
		{
			Date = DecreaseOneYear(Date);
		}

		return Date;
	}
	ClsDate DecreaseXyear(short NumberOfYears)
	{
		return DecreaseXyear(*this, NumberOfYears);
	}

	static ClsDate DecreaseOneDecade(ClsDate& Date)
	{
		Date._Year -= 10;

		return Date;
	}
	ClsDate DecreaseOneDecade()
	{
		return DecreaseOneDecade(*this);
	}

	static ClsDate DecreaseXdecade(ClsDate& Date, short NumberOfDecade)
	{
		for (int i = 1; i <= NumberOfDecade; i++)
		{
			Date = DecreaseOneDecade(Date);
		}

		return Date;
	}
	ClsDate DecreaseXdecade(short NumberOfDecade)
	{
		return IncreaseXdecade(*this, NumberOfDecade);
	}

	static ClsDate DecreaseOneCentury(ClsDate& Date)
	{
		Date._Year -= 100;

		return Date;
	}
	ClsDate DecreaseOneCentury()
	{
		return DecreaseOneCentury(*this);
	}

	static ClsDate DecreaseOneMillennium(ClsDate& Date)
	{
		Date._Year -= 1000;

		return Date;
	}
	ClsDate DecreaseOneMillennium()
	{
		return DecreaseOneMillennium(*this);
	}

	static bool IsEndOfWeek(ClsDate Date)
	{
		short DayIndex = GetNumberOfDay(Date._Day, Date.Month, Date.Year);

		return (DayIndex == 6 || DayIndex == 7);
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsBusinessDay(ClsDate Date)
	{
		return !IsEndOfWeek(Date);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short NumberOfUntilDaysToEndWeek(ClsDate Date)
	{
		return 7 - GetNumberOfDay(Date._Day, Date.Month, Date.Year);;
	}
	short NumberOfUntilDaysToEndWeek()
	{
		return NumberOfUntilDaysToEndWeek(*this);
	}

	static short NumberOfUntilDaysToEndMonth(ClsDate Date)
	{
		return NumberOfDaysInMonth(Date._Month, Date._Year) - Date._Day;
	}
	short NumberOfUntilDaysToEndMonth()
	{
		return NumberOfUntilDaysToEndMonth(*this);
	}

	static int NumberOfUntilDaysToEndYear(ClsDate Date)
	{
		int Counter = 0;

		Counter = NumberOfDaysInMonth(Date._Month, Date._Year) - Date._Day;

		Date._Month ++;

		while (Date._Month<= 12)
		{
			Counter += NumberOfDaysInMonth(Date._Month, Date._Year);

			Date._Month++;
		}

		return Counter;
	}
	int NumberOfUntilDaysToEndYear()
	{
		return NumberOfUntilDaysToEndYear(*this);
	}

	static int CalculateBusinessDay(ClsDate DateFrom, ClsDate DateTo)
	{
		int Counter = 0;

		while (IsDate1BeforDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
			{
				Counter++;

				DateFrom = IncreaseDateByOneDay(DateFrom);
			}
		}

		return Counter;
	}
	
	static int CalculateVacationDay(ClsDate DateFrom, ClsDate DateTo)
	{
		return CalculateBusinessDay(DateFrom, DateTo);
	}

	static ClsDate CalculateVacationReturnDate(ClsDate &DateFrom, short NumberOfVacation)
	{
		
		while (IsEndOfWeek(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		for (int i = 1 ; i < NumberOfVacation ; i++)
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);

			while (IsEndOfWeek(DateFrom))
			{
				DateFrom = IncreaseDateByOneDay(DateFrom);
			}
		}

		return DateFrom;
	}
	ClsDate CalculateVacationReturnDate(short NumberOfVacation = 1)
	{
		return CalculateVacationReturnDate(*this,NumberOfVacation);
	}

	static bool IsDate1AfterDate2(ClsDate Date1, ClsDate Date2)
	{
		return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(ClsDate Date2)
	{
		return IsDate1AfterDate2(*this,Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	static enDateCompare CompareDates(ClsDate Date1, ClsDate Date2)
	{
		if (IsDate1BeforDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;

	}
	enDateCompare CompareDates(ClsDate Date2)
	{
		return CompareDates(*this, Date2);
	}
};