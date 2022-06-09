#include <iostream>
#include <string>
#include <vector>
#include "Infix.h"
#include <fstream>

using namespace std;

void Introduce()
{
	fstream f;
	f.open("Note.txt", ios::in);
	string line;
	while (!f.eof())
	{
		char temp[255];
		f.getline(temp, 255);
		string line = temp;
		cout << line << std::endl;
	}
	system("pause");
	system("cls");
}

int foundSpace(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			return i;
	}
	return -1;
}

void deleteSpace(string& str)
{
	int index;

	while ((index = foundSpace(str)) != -1)
		str.erase(index, 1);
}

int foundOperator(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'sqrt' || str[i] == 'cos' || str[i] == 'sin' || str[i] == 'log' || str[i] == 'exp' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '!' || str[i] == '%')
			return i;
	}
	return -1;
}

int foundNumber(string str)
{
	for (int i = 0; i < str.length();i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			return i;
	}
	return -1;
}
void detailOperator(string& Input)
{
	for (int i = 0; i < Input.length(); i++)
	{
		if (Input[i] == '-' && Input[i + 1] == '-')
		{
			Input.replace(i, 2, "+");
			detailOperator(Input);
		}

		if ((Input[i] == '+' && Input[i + 1] == '-') || (Input[i]) == '-' && Input[i + 1] == '+')
		{
			Input.replace(i, 2, "-");
			detailOperator(Input);
		}

		if ((Input[i] == '*' || Input[i] == '/') && (Input[i + 1] == '+'))
		{
			Input.erase(i + 1, 1);
			detailOperator(Input);
		}
	}
}

void parseInput(string Input, vector<string>& M)
{
	int length = Input.length();
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (Input[i] >= '0' && Input[i] <= '9')
		{
			if (i < length - 1)
			{
				int j = i + 1;
				if (Input[j] == '(' || Input[j] == ')' || Input[j] == '*' || Input[j] == '/' || Input[j] == '+' || Input[j] <= '-' || Input[j] == '%' || Input[j] == '^' || Input[j] == 't' || Input[j] == 'n' || Input[j] == 'p' || Input[j] == 'cos' || Input[j] == 'g' || Input[j] == '!' || Input[j] == '#')
				{
					M.push_back(Input.substr(i - count, 1 + count));
					count = 0;
				}
				else
					count++;
			}
			else
			{
				M.push_back(Input.substr(i - count, count + 1));
				break;
			}
		}
		else
		{
			if (Input[i] == '(' || Input[i] == ')' || Input[i] == '*' || Input[i] == '/' || Input[i] == '+' || Input[i] == '-' || Input[i] == '%' || Input[i] == '^' || Input[i] == 't' || Input[i] == 's' || Input[i] == 'p' || Input[i] == 'g' || Input[i] == '!' || Input[i] == 'n' || Input[i] == '#')
			{
				string temp(1, Input[i]);
				M.push_back(temp);
			}
		}
	}
}

void quickTransition(string& Input)
{
	int count = 0;

	for (int i = 0; i < Input.length(); i++)
	{
		if ((Input.find("sin")) != -1)
		{
			int i = Input.find("sin");
			Input.erase(i, 3);
			while (true)
			{
				if (Input[i] == '(')
					count = count + 1;

				if (Input[i] == ')' && count != 0)

					(count) = count - 1;

				if (Input[i] == ')' && count == 0)
				{
					Input.insert(i + 1, "n");
					break;
				}
				i++;
			}
		}
		else if ((Input.find("cos")) != -1)
		{
			int i = Input.find("cos");
			Input.erase(i, 3);
			while (true)
			{
				if (Input[i] == '(')
					count = count + 1;
				if (Input[i] == ')' && count != 0)
					(count) = count - 1;

				if (Input[i] == ')' && count == 0)
				{
					Input.insert(i + 1, "s");
					break;
				}
				i++;
			}
		}
		else if ((Input.find("sqrt")) != -1)
		{
			int i = Input.find("sqrt");
			Input.erase(i, 4);
			while (true)
			{
				if (Input[i] == '(')
					count = count + 1;
				if (Input[i] == ')' && count != 0)
					(count) = count - 1;

				if (Input[i] == ')' && count == 0)
				{
					Input.insert(i + 1, "t");
					break;
				}
				i++;
			}
		}
		else if ((Input.find("log")) != -1)
		{
			int i = Input.find("log");
			Input.erase(i, 3);
			while (true)
			{
				if (Input[i] == '(')
					count = count + 1;
				if (Input[i] == ')' && count != 0)
					(count) = count - 1;

				if (Input[i] == ')' && count == 0)
				{
					Input.insert(i + 1, "g");
					break;
				}
				i++;
			}
		}
		else if ((Input.find("exp")) != -1)
		{
			int i = Input.find("exp");
			Input.erase(i, 3);
			while (true)
			{
				if (Input[i] == '(')
					count = count + 1;
				if (Input[i] == ')' && count != 0)
					(count) = count - 1;

				if (Input[i] == ')' && count == 0)
				{
					Input.insert(i + 1, "p");
					break;
				}
				i++;
			}
		}
		else if ((Input.find("(-")) != -1)
		{
			int i = Input.find("(-");
			Input.erase(i + 1, 1);
			while (true)
			{
				if (Input[i] == '(')
					count = count + 1;
				if (Input[i] == ')' && count != 0)
					(count) = count - 1;

				if (Input[i] == ')' && count == 0)
				{
					Input.insert(i + 1, "#");
					break;
				}
				i++;
			}
		}

	}
}

bool Step1(string& Input)
{
	if (foundNumber(Input) != -1 && foundSpace(Input) != -1 && foundOperator(Input) == -1)
	{
		return false;
	}
	if (foundNumber(Input) == -1 && foundOperator(Input) != -1)
	{
		return false;
	}
	return true;
}

void Step2(string& Input, float& Result)
{
	Infix* infix = new Infix();
	vector<string> M;
	deleteSpace(Input);
	detailOperator(Input);
	quickTransition(Input);
	parseInput(Input, M);
	Result = infix->calculateValue(M);
}

void Process(string& Input)
{
	if (Step1(Input) == true)
	{
		float Result = 0;
		Step2(Input, Result);
		cout << "Result: " << Result << endl;
	}
	else
		cout << "Result: Error" << endl;
}

void main()
{
	Introduce();

	string Input;
	cout << "\nEnter: ";
	getline(cin, Input);

	Process(Input);
	system("pause");
}