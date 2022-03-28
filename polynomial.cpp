#include "polynomial.h"
#include <iostream>
#include <math.h>

//
// Implementation
//
/*
// Copy constructor
Polynomial::Polynomial(const Polynomial &source)
{
	// ToDo
}

// Destructor
Polynomial::~Polynomial()
{
	// ToDo
}

Polynomial &Polynomial::operator=(const Polynomial &source)
{
	// ToDo
}

// Sum of *this and source polynomials
Polynomial Polynomial::operator+(const Polynomial &source)
{
	Polynomial c;

	// ToDo

	return c;
}

Polynomial Polynomial::operator-(const Polynomial &source)
{
	Polynomial c;

	// ToDo

	return c;
}

Polynomial Polynomial::operator*(const Polynomial &source)
{
	Polynomial c;

	// ToDo

	return c;
}

bool Polynomial::operator==(const Polynomial &source)
{
	bool ret;

	// ToDo

	return ret;
}

float Polynomial::Eval(float x)
{
	float ret = 0;

	// ToDo

	return ret;
}

// Compute derivative of the current polynomial
Polynomial Polynomial::Derivative()
{
	Polynomial c;

	// ToDo

	return c;
}
*/
void Polynomial::CreateTerm(const float coef, const int exp)
{
	if (Capacity() > Terms())
	{
		bool flag = true;
		Term temp;
		temp.coef = coef;
		temp.exp = exp;
		for (int i = 0; i < Terms(); i++)
		{
			if (termArray[i].exp == exp)
			{
				termArray[i].coef += coef;
				flag = false;
				break;
			}
			else if (termArray[i].exp < exp)
			{
				for (int j = Terms(); j > i; j--)
				{
					termArray[j] = termArray[j - 1];
				}
				termArray[i] = temp;
				terms++;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			termArray[Terms()] = temp;
			terms++;
		}
	}
	else
	{
		// start of extend
		capacity += 5;
		Term *newArray = new Term[capacity];
		Term *buffer = termArray;
		termArray = newArray;
		for (int i = 0; i < Terms(); i++)
			termArray[i] = buffer[i];
		delete[] buffer;
		// end of extend
		// adding a new term
		bool flag = true;
		Term temp;
		temp.coef = coef;
		temp.exp = exp;
		for (int i = 0; i < Terms(); i++)
		{
			if (termArray[i].exp == exp)
			{
				termArray[i].coef += coef;
				flag = false;
				break;
			}
			else if (termArray[i].exp < exp)
			{
				for (int j = Terms(); j > i; j--)
				{
					termArray[j] = termArray[j - 1];
				}
				termArray[i] = temp;
				terms++;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			termArray[Terms()] = temp;
			terms++;
		}
	}
}
