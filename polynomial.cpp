#include "polynomial.h"
#include <iostream>
#include <math.h>


//
// Implementation
//


// Copy constructor
Polynomial::Polynomial(const Polynomial& source)
{
	// ToDo
}	

// Destructor
Polynomial::~Polynomial()
{
	// ToDo
}


Polynomial& Polynomial::operator = (const Polynomial& source)
{
	// ToDo
}



// Sum of *this and source polynomials
Polynomial Polynomial::operator +(const Polynomial& source)
{
	Polynomial c;
	
	// ToDo
	
	return c;
}

Polynomial Polynomial::operator - (const Polynomial& source)
{
	Polynomial c;

	// ToDo
	
	return c;
	
}

Polynomial Polynomial::operator * (const Polynomial& source)
{
	Polynomial c;
	
	// ToDo
	
	return c;	
}

bool Polynomial::operator == (const Polynomial& source)
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

void Polynomial::CreateTerm(const float coef, const int exp)
{
	// ToDo
	
}

