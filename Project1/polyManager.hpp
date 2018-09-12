#include<iostream>
class PolyManager{
public:
	bool add(Poly& p1, Poly& p2);
	bool subtract(Poly& p1, Poly& p2);
	bool multiple(Poly& p1, Poly& p2);
	bool derivative(Poly& p1);
	void display();
	void calculate(Poly& p1,int x);
private:
	Poly* head;
	Poly* tail;
};
