#include "polynomial.h"
#include <iostream>
#include <math.h>

//
// Implementation
//

// Copy constructor
Polynomial::Polynomial(const Polynomial &source)
{
	this->capacity = source.capacity;
	this->terms = source.terms;
	this->termArray = new Term[this->capacity];
	for (int i = 0; i < this->terms; i++)
		this->termArray[i] = source.termArray[i];
}

// Destructor
Polynomial::~Polynomial()
{
	delete[] termArray;
}

Polynomial &Polynomial::operator=(const Polynomial &source)
{
	delete[] this->termArray;
	this->capacity = source.capacity;
	this->terms = source.terms;
	this->termArray = new Term[this->capacity];
	for (int i = 0; i < this->terms; i++)
		this->termArray[i] = source.termArray[i];
	return *this;
}

// Sum of *this and source polynomials
Polynomial Polynomial::operator+(const Polynomial &source)
{
	Polynomial c;
	c = *this;
	for (int i = 0; i < source.Terms(); i++)
		c.CreateTerm(source.termArray[i].coef, source.termArray[i].exp);
	return c;
}

Polynomial Polynomial::operator-(const Polynomial &source)
{
	Polynomial c;
	c = *this;
	for (int i = 0; i < source.Terms(); i++)
		c.CreateTerm(-source.termArray[i].coef, source.termArray[i].exp);
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
	float ret = 0, result;
	for (int i = 0; i < this->terms; i++)
	{
		result = 1;
		// multiply of coef into result
		result *= this->termArray[i].coef;
		// calculating the result of power
		for (int j = 0; j < this->termArray[i].exp; j++)
			result *= x;
		// adding result into ret
		ret += result;
	}
	return ret;
}

// Compute derivative of the current polynomial
Polynomial Polynomial::Derivative()
{
	Polynomial c;

	// ToDo

	return c;
}
// creating new term for our polynomial
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
