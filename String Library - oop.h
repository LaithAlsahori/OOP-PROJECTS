#pragma once
#include<iostream>
#include<vector>
#include<cctype>
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

	void SetTheStringValue(string Value)
	{
		_Value = Value;
	}

	string GetTheStringValue()
	{
		return _Value;
	}

	__declspec(property(get = GetTheStringValue, put = SetTheStringValue))string Value;

	static vector<string> Split(string Value, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; 

		
		while ((pos = Value.find(Delim)) != std::string::npos)
		{
			sWord = Value.substr(0, pos);
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			Value.erase(0, pos + Delim.length());
		}

		if (Value != "")
		{
			vString.push_back(Value);
		}

		return vString;

	}
	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static short Length(string Value)
	{
		short Counter = 0;

		while (Value[Counter] != '\0')
		{
			Counter++;
		}

		return Counter;
	}
	short Length()
	{
		return Length(_Value);
	}

	static string Erase(string Value, short Start_Index, short NumberOfIndex)
	{
		string Result = "";
		int endIndex = Start_Index + NumberOfIndex;

		for (int i = 0; i <= Length(Value); i++)
		{
			if (i >= Start_Index && i < endIndex)
			{
				continue;
			}

			Result += Value[i];
		}

		return Result;
	}
	string Erase(short Start_Index, short NumberOfIndex)
	{
		return Erase(_Value, Start_Index, NumberOfIndex);
	}

	static short Find(string Value, string FideWhat)
	{
		string Countiner = "";

		for (int i = 0; i <= Length(Value); i++)
		{
			if (Value[i] == FideWhat[0])
			{
				for (int j = 0; j < Length(FideWhat); j++)
				{
					Countiner += Value[i + j];

					if (Countiner == FideWhat)
					{
						return i;
					}
				}

				Countiner = "";
			}
		}

		return -1;
	}
	short Find(string FideWhat)
	{
		return Find(_Value, FideWhat);
	}

	static string SubStr(string Value, short Start_Index, short NumberOfIndex)
	{
		Value = Erase(Value, Start_Index + NumberOfIndex, Length(Value) - (Start_Index + NumberOfIndex));

		Value = Erase(Value, 0, Start_Index);

		return Value;
	}
	string SubStr(short Start_Index, short NumberOfIndex)
	{
		return SubStr(_Value, Start_Index, NumberOfIndex);
	}

	static bool IsEmpty(string Value)
	{
		if (Value == "")
		{
			return true;
		}

		return false;
	}
	bool IsEmpty()
	{
		return IsEmpty(_Value);
	}

	static short LengthOfSpace(string Value, string Limiter = " ")
	{
		short Number = 0;
		short Pos = 0;

		if ((Pos = Find(Value, Limiter)) != -1)
		{
			while (Value[Pos] == ' ')
			{
				Pos++;
				Number++;
			}

			return Number;
		}

		return 0;
	}
	short LengthOfSpace(string Limiter = " ")
	{
		return LengthOfSpace(_Value, " ");
	}

	static short CounterWord(string Value, string Limiter)
	{
		short Pos = 0;
		vector<string> vString;

		while ((Pos = Find(Value, Limiter)) != -1)
		{
			string Word = SubStr(Value, 0, Pos);


			if (!IsEmpty(Word))
			{
				vString.push_back(Word);
			}

			if (Limiter == " ")
			{
				Value = Erase(Value, 0, Pos + LengthOfSpace(Value, " "));
			}
			else
			{
				Value = Erase(Value, 0, Pos + Length(Limiter));
			}
		}

		if (!IsEmpty(Value))
		{
			vString.push_back(Value);
		}

		return vString.size();
	}
	short CounterWord(string Limiter)
	{
		return CounterWord(_Value, Limiter);
	}

	static string ToUpper(string Value, short Start_Index = 0, short NumberOfIndex = 0)
	{

		short End_Index = Start_Index + NumberOfIndex;

		if (NumberOfIndex == 0)
		{
			End_Index = Length(Value);
		}

		for (int i = 0; i < Length(Value); i++)
		{
			if (i >= Start_Index && i < End_Index)
			{
				Value[i] = toupper(Value[i]);
			}
		}

		return Value;
	}
	string ToUpper(short Start_Index = 0, short NumberOfIndex = 0)
	{
		return ToUpper(_Value, Start_Index, NumberOfIndex);
	}

	static string ToLower(string Value, short Start_Index, short NumberOfIndex)
	{
		short End_Index = Start_Index + NumberOfIndex;

		if (NumberOfIndex == 0)
		{
			End_Index = Length(Value);
		}

		for (int i = 0; i < Length(Value); i++)
		{
			if (i >= Start_Index && i < End_Index)
			{
				Value[i] = tolower(Value[i]);
			}
		}

		return Value;
	}
	string ToLower(short Start_Index, short NumberOfIndex)
	{
		return ToLower(_Value, Start_Index, NumberOfIndex);
	}

	static string Clear(string Value)
	{
		return Value = "";
	}
	string Clear()
	{
		return Clear(_Value);
	}

	static string Append(string Original_String, string Value)
	{
		return Original_String + Value;
	}
	string Append(string Value)
	{
		return Append(_Value, Value);
	}

	static string Insert(string Original_String, string Value, short Index = 0)
	{

		string Container = "";

		for (int i = 0; i < Original_String.length(); i++)
		{

			if (Index == i)
			{
				Container += Value;
			}
			Container += Original_String[i];
		}


		if (Index == Original_String.length())
		{
			Container += Value;
		}

		return Container;
	}
	string Insert(string Value, short Index = 0)
	{
		return Insert(_Value, Value, Index);
	}

	static string ConvertFirstLatterToUpper(string Value)
	{
		bool IsFirstLatter = true;
		
		for (int i = 0; i < Length(Value); i++)
		{
			if (IsFirstLatter)
			{
				IsFirstLatter = false;
				Value[i] = toupper(Value[i]);
			}
			if (Value[i] == ' ')
			{
				IsFirstLatter = true;
		    }
		}

		return Value;
	}
	string ConvertFirstLatterToUpper()
	{
		return ConvertFirstLatterToUpper(_Value);
	}

	static string ConvertFirstLowerToUpper(string Value)
	{
		bool IsFirstLatter = true;

		for (int i = 0; i < Length(Value); i++)
		{
			if (IsFirstLatter)
			{
				IsFirstLatter = false;
				Value[i] = tolower(Value[i]);
			}
			if (Value[i] == ' ')
			{
				IsFirstLatter = true;
			}
		}

		return Value;
	}
	string ConvertFirstLowerToUpper()
	{
		return ConvertFirstLowerToUpper(_Value);
	}

	static char InvertLetterCase(char Char)
	{
		return isupper(Char) ? tolower(Char) : toupper(Char);
	}
	
	static string  InvertAllLettersCase(string Value)
	{
		for (short i = 0; i < Length(Value); i++)
		{
			Value[i] = InvertLetterCase(Value[i]);
		}
		return Value;
	}
	string  InvertAllLettersCase()
	{
		return InvertAllLettersCase(_Value);
	}

	enum EnTypeOfLetter {SmallLetter = 1 , CapitalLetter = 2 , All = 3};

	static int CountLetter(string Value, EnTypeOfLetter TypeOfLetter = EnTypeOfLetter::All)
	{
		int counter = 0;

		if (TypeOfLetter == EnTypeOfLetter::All)
		{
			for (short i = 0; i < Length(Value); i++)
			{
				if (isalpha(Value[i]))
				{
					counter++;
				}
			}
		}
		else if (TypeOfLetter == EnTypeOfLetter::CapitalLetter)
		{
			for (short i = 0; i < Length(Value); i++)
			{
				if (isalpha(Value[i]) && isupper(Value[i]))
				{
					counter++;
				}
			}
		}
		else
		{
			for (short i = 0; i < Length(Value); i++)
			{
				if (isalpha(Value[i]) && islower(Value[i]))
				{
					counter++;
				}
			}
		}
	}
	int CountLetter(EnTypeOfLetter TypeOfLetter = EnTypeOfLetter::All)
	{
		return CountLetter(TypeOfLetter = EnTypeOfLetter::All);
	}

	static short  CountSpecificLetter(string Value, char Letter, bool MatchCase = true)
	{

		short Counter = 0;

		for (short i = 0; i < Length(Value); i++)
		{

			if (MatchCase)
			{
				if (Value[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(Value[i]) == tolower(Letter))
					Counter++;
			}

		}

		return Counter;
	}
	short  CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(Letter,MatchCase);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}
	static short  CountVowels(string Value)
	{

		short Counter = 0;

		for (short i = 0; i < Value.length(); i++)
		{

			if (IsVowel(Value[i]))
				Counter++;
		}

		return Counter;
	}
	short  CountVowels()
	{
		return CountVowels(_Value);
	}

	static string TremLeft(string Value)
	{
		short i = 0;
		while (i < Value.length() && Value[i] == ' ')
		{
			i++;
	    }

		return Erase(Value, 0, i);
	}
	string TremLeft()
	{
		return TremLeft(_Value);
	}

	static string TremRight(string Value)
	{
		short i = Value.length() - 1;
		
		while (i >= 0 && Value[i] == ' ')
		{
			i--;
		
		}

		return Erase(Value, i + 1, Value.length());
	}
	string TremRight()
	{
		return TremRight(_Value);
	}

	static string Trem(string Value)
	{
		Value = TremRight(Value);
		Value = TremLeft(Value);

		return Value;
	}
	string Trem()
	{
		return Trem(_Value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());


	}

	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string ReplaceWords(string Value , string StringToReplace , string ReplaceTo, bool MatchCase = true)
	{
		vector<string> vValue;

		vValue = Split(Value, " ");

		for (string &Test : vValue)
		{
			if (MatchCase)
			{
				if (Test == StringToReplace)
				{
					Test = ReplaceTo;
				}
			}
			else
			{
			  if (ToLower(Test,0, Length(Test) - 1) == ToLower(StringToReplace, 0, Length(StringToReplace) - 1))

				{
						Test = ReplaceTo;
				}
			}
			
		}

		return JoinString(vValue, " ");
	}
	string ReplaceWords(string StringToReplace, string ReplaceTo, bool MatchCase = true)
	{
		return ReplaceWords(_Value,StringToReplace,ReplaceTo,MatchCase);
	}

	static string RemovePunctuations(string Value)
	{

		string S2 = "";

		for (short i = 0; i < Value.length(); i++)
		{
			if (!ispunct(Value[i]))
			{
				S2 += Value[i];
			}
		}

		return S2;

	}
	string RemovePunctuations()
	{
		return RemovePunctuations(_Value);
	}
};
