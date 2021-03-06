#include "Infix.h"
#include "cmath"
using namespace std;

Infix::Infix()
{
}

Infix::~Infix()
{
}

int Infix::UT(string x)
{
	if (x == "t" || x == "p" || x == "n" || x == "s" || x == "!" || x == "g" || x == "#")
		return 3;
	if (x == "*" || x == "/" || x == "%" || x == "^")
		return 2;
	else if (x == "+" || x == "-")
		return 1;
	else if (x == "(")
		return 0;

	return -1;
}
int Infix::HT(string x)
{
	if (x == "(" || x == ")")
		return 3;
	else if (x == "*" || x == "/" || x == "%" || x == "+" || x == "-" || x == "^" || x == "t" || x == "n" || x == "s" || x == "g" || x == "p" || x == "!" || x == "#")
		return 2;
	else
		return 1;
}
string Infix::calculateValue(string c, string b, string a)
{
	float fResult = 0;

	if (b == "t") //sqrt
		fResult = sqrt(atof(a.c_str()));

	if (b == "n") //sin
		fResult = sin(atof(a.c_str()));

	if (b == "s") //cos
		fResult = cos(atof(a.c_str()));

	if (b == "g") //log
		fResult = log(atof(a.c_str()));

	if (b == "#")
	{
		fResult = -(atof(a.c_str()));
	}

	if (b == "!") //frac
	{
		fResult = 1;
		for (int i = 2; i <= int(atof(a.c_str())); i++)
			fResult *= i;
	}
	if (b == "p") //exp
		fResult = exp(atof(a.c_str()));

	if (b == "^")
	{
		fResult = 1;
		for (int i = 1; i <= int(atof(a.c_str())); i++)
			fResult = fResult * atof(c.c_str());
	}

	if (b == "*")
		fResult = atof(c.c_str()) * atof(a.c_str());
	if (b == "/")
		fResult = atof(c.c_str()) / atof(a.c_str());
	if (b == "+")
		fResult = atof(c.c_str()) + atof(a.c_str());
	if (b == "-")
		fResult = atof(c.c_str()) - atof(a.c_str());
	if (b == "%")
		fResult = int(atof(c.c_str())) % int(atof(a.c_str()));


	string strResult = to_string(fResult);
	return strResult;
}
float Infix::calculateValue(vector<string> M)
{
	float fResult = 0;

	Stack* Sh = new Stack();
	Stack* St = new Stack();

	int iLength = M.size();

	for (int i = 0; i < iLength; i++)
	{
		if (HT(M[i]) == 1)
			Sh->Push(M[i]);

		if (HT(M[i]) == 2)
		{
			while (!St->isEmpty() && (UT((M[i])) <= UT(St->getHead()->Info)))
			{
				string a = "";
				string b = "";
				string c = "";
				if (UT(St->getHead()->Info) == 3)
				{
					Sh->Pop(a);
					St->Pop(b);
					Sh->Push(this->calculateValue(c, b, a));
				}
				else
				{
					Sh->Pop(a);
					St->Pop(b);
					Sh->Pop(c);
					Sh->Push(this->calculateValue(c, b, a));
				}
			}
			St->Push(M[i]);
		}

		if (M[i] == "(")
			St->Push(M[i]);

		if (M[i] == ")")
		{
			while (St->getHead()->Info != "(")
			{
				string a = "";
				string b = "";
				string c = "";
				if (UT(St->getHead()->Info) == 3)
				{
					Sh->Pop(a);
					St->Pop(b);
					Sh->Push(this->calculateValue(c, b, a));
				}
				else
				{
					Sh->Pop(a);
					St->Pop(b);
					Sh->Pop(c);
					Sh->Push(this->calculateValue(c, b, a));
				}
			}
			string c = "";
			St->Pop(c);
		}
	}

	while (!St->isEmpty())
	{
		string a = "";
		string b = "";
		string c = "";
		if (UT(St->getHead()->Info) == 3)
		{
			Sh->Pop(a);
			St->Pop(b);
			Sh->Push(this->calculateValue(c, b, a));
		}
		else
		{
			Sh->Pop(a);
			St->Pop(b);
			Sh->Pop(c);
			Sh->Push(this->calculateValue(c, b, a));
		}
	}

	string strResult = "";
	Sh->Pop(strResult);
	fResult = atof(strResult.c_str());
	return fResult;
}