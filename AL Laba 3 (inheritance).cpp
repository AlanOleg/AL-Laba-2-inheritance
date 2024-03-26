#include <iostream>
using namespace std;

class square 
{
protected:
	double a;
public:
	square(double a)
	{
		this->a = a;
	}

	virtual double perimeter() 
	{
		return (a * 4);
	}

	virtual void print()
	{
		cout << "\nP = " << this->perimeter() << " a = " << a;
	}
};

class rectangle: public square
{
public:
	double b;
	rectangle(double a, double b): square(a)
	{
		this->b = b;
	}

	double perimeter()
	{
		return (square::perimeter() + 2 * (b - a));
	}

	void print()
	{
		square::print();
		cout << " b = " << b << endl;
	}
};

void main()
{
	square square1(4); // Создается квадрат с вызовом конструктора
	rectangle rectangle1(5, 6); // Создается прямоугольник с вызовом конструктора
	square* test; // Указатель типа базового класса
	test = &square1; // Настраиваем на объект базового класса
	test->print(); // Вызов метода через указатель, вызывается метод класса square
	test = &rectangle1; // Настриваем указатель на объект производного класса
	test->print(); // Вызов метода через указатель, вызывается метод класса rectangle
	// Если метод print в классе square был объявлен без virtual, то вызывался бы метод print класса square
}
