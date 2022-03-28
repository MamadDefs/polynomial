//
// Spring 2022 COSE213 Assignment 1
//
// Won-Ki Jeong (wkjeong@korea.ac.kr)
//

#ifndef polynomial_h
#define polynomial_h

#include <typeinfo>
#include <iostream>
#include <math.h>


class Polynomial;

class Term {
	friend class Polynomial;

private:
	float coef;
	int exp;
};

class Polynomial
{
public:
	// Default constructor p(x) = 0
	Polynomial()
	{
		capacity = 10;
		terms = 0;
		termArray = new Term[capacity];
	};
	
	// Copy constructor
	Polynomial(const Polynomial& source);

	// Destructor
	~Polynomial();

	// Assignment operator
	Polynomial& operator = (const Polynomial& source);

	// Sum of *this and source polynomials
	Polynomial operator+(const Polynomial& source);
	
	// Subtract of source polynomials from *this
	Polynomial operator-(const Polynomial& source);

	// Product of *this and source polynomials
	Polynomial operator*(const Polynomial& source);
	
	// Compute derivative of the current polynomial
	Polynomial Derivative();

	// Return true if left polynomial is identical to right polynomial
	bool operator==(const Polynomial& source);

	// Evaluate polynomial *this at x and return the result
	float Eval(float x);

	// Create a new term. If the term exists, overwrite its coefficient.
	void CreateTerm(const float coef, const int exp);


	// Print polynomial
	void Print()
	{
		if(terms == 0) std::cout << "0" << std::endl;
		else
		{
			for(int i=0; i<terms; i++)
			{
				float c = termArray[i].coef;
				int e = termArray[i].exp;
							
				if(c > 0 && i > 0)
				{
					std::cout << "+";
				}
				
				std::cout << c;
				if(e > 0) std::cout<<"x^"<<e;
			}
			std::cout << std::endl;
		}
	}
	
	int Capacity() const { return capacity; }
	int Terms() const { return terms; }
	Term& GetTerm(int x) const { return termArray[x]; } 

private:
	Term *termArray;
	int capacity; // max # of terms in this polynomial
	int terms;	  // current # of terms in this polynomial
};


#endif
