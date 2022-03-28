//
// Spring 2022 COSE213 Assignment 1
//
// Won-Ki Jeong (wkjeong@korea.ac.kr)
//

#include "polynomial.h"
#include <iostream>

int main()
{
	Polynomial f, g;
	
	f.CreateTerm(-4, 3);
	f.CreateTerm(2.3, 2);
	f.CreateTerm(-3, 0);
	
	std::cout << "f = ";
	f.Print();
	
	g.CreateTerm(3, 4);
	g.CreateTerm(-8, 0);
	g.CreateTerm(-4, 3);
	
	std::cout << "g = ";
	g.Print();
	
	g.CreateTerm(5, 2);
	std::cout << "g (creating a new term) = ";
	g.Print();
	
	// copy constructor test
	std::cout << "h (created from f) = ";
	Polynomial h = f;
	h.Print();
	
	// assignment operator test
	std::cout << "h (assigned from g) = ";
	h = g;	
	h.Print();
	
	// Add test
	std::cout << "f + g = ";
	h = f + g;	
	h.Print();
	
	// Subtract test
	std::cout << "f - g = ";
	h = f - g;
	h.Print();
	
	// Equal test
	if(f == g)
		std::cout << "f and g are same" << std::endl;
	else
		std::cout << "f and g are different" << std::endl;
	
	// Eval test
	std::cout << "f(3.5) is " << f.Eval(3.5) << std::endl;
		
	// Derivative test
	Polynomial i = f.Derivative(); 
	std::cout << "Derivative of f = ";
	i.Print();
	
	return 0;
}
