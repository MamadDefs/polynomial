assign_1 : main.o polynomial.o
	g++ main.o polynomial.o -o final

main.o : main.cpp
	g++ -c main.cpp -o main.o

polynomial.o : polynomial.cpp
	g++ -c polynomial.cpp -o polynomial.o
