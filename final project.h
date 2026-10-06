#pragma once
#include<iostream>
using namespace std;
class ClsString
{
private:

	string _Value;

public:

	ClsString()
	{
		_Value = "";
	}

	ClsString(string Value)
	{
		_Value = Value;
	}

	void SetTheValue(string Value)
	{
		_Value = Value;
	}
	string GetTheValue()
	{
		return _Value;
	}

	__declspec(property(get = GetTheValue, put = SetTheValue))string Value;

	static int Counter(string Value)
	{
		int Counter = 0;

		while (Value[Counter] != '\0')
		{
			Counter++;
		}

		return Counter;
	}

	int Counter()
	{
		return Counter(_Value);
	}

	static string Cut(string Value, short start_Index, short Number_Of_Index = 0)
	{
		string Container = "";

		for (int i = 0; i < Counter(Value); i++)
		{
			if (i == start_Index)
			{
				while (Number_Of_Index != 0 && Value[i] != '\0')
				{
					Container += Value[i];
					Number_Of_Index--;
					i++;
				};
				break;
			}
		}

		return Container;
	}

	string Cut(short start_Index, short Number_Of_Index = 0)
	{
		return Cut(_Value, start_Index, Number_Of_Index);
	}

	static string Remove(string Value, short start_Index, short Number_Of_Index)
	{
		Value = Cut(Value, 0, start_Index) + Cut(Value, start_Index + Number_Of_Index, Counter(Value) - (start_Index + Number_Of_Index));

		return Value;
	}

	string Remove(short start_Index, short Number_Of_Index)
	{
		return Remove(_Value, start_Index, Number_Of_Index);
	}

	static short Find(string Value, string Word)
	{
		string Continer = "";
		short Postion = 0;
		bool Flag = true;

		for (int i = 0; i <= Counter(Value); i++)
		{
			if (Value[i] != ' ')
			{
				Continer += Value[i];

				if (Flag)
				{
					Postion = i;
				}

				if (Continer == Word)
				{
					return Postion;
				}

				Flag = false;
			}
			else
			{
				Continer = "";

				Flag = true;
			}
		}

		return string::npos;
	}

	short Find(string Word)
	{
		return Find(_Value, Word);
	}

	static string Insert(string Value, string Word , short Index)
	{
		string Continer = "";

		if (Index < 0 || Index > Counter(Value)) {
			return Value; 
		}

		for (int i = 0 ; i <= Counter(Value) ; i++)
		{
	
			if (i == Index)
			{
				for (int j = 0; j <= Counter(Word); j++)
				{
					Continer += Word[j];
				}
			}

			Continer += Value[i];

		}

		return Continer;
	}

	string Insert(string Word, short Index)
	{
		return Insert(_Value,Word,Index);
	}

	static string Replace(string Value, string Word,short Start_Index)
	{
		for (int i = 0 ; i <= Counter(Value) ; i++)
		{
			if ( i == Start_Index)
			{
				for (int j = 0; j <= Counter(Word); j++)
				{
					Value[i] = Word[j];

					i++;
				}
			}
		}

		return Value;
	}

	string Replace(string Word, short Start_Index)
	{
		return Replace(_Value, Word, Start_Index);
	}
};


