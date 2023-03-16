#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
public:
	double Re, Im;
	Complex(double re = 0, double im = 0) {
		Re = re;
		Im = im;
	}

	Complex operator+(const Complex& c)const
	{
		return Complex(Re + c.Re, Im + c.Im);
	}
	Complex operator-(const Complex& c)const
	{
		return Complex(Re - c.Re, Im - c.Im);
	}
	Complex operator*(const Complex& c)const
	{
		return Complex(Re * c.Re - Im*c.Im, Re * (c.Im + c.Re * Im));
	}
	Complex operator/(const Complex& c)const
	{
		return Complex((Re * c.Re + Im * c.Im) / (c.Re * c.Re + c.Im * c.Im), (-Re * c.Re + Im * Re) / (c.Re * c.Re + c.Im * c.Im));
	}

	double Mod()
	{
		return sqrt(Re * Re + Im * Im);
	}

	double Arg()
	{
		if (Mod() == 0)
			return 0;
		if (Re > 0)
			return atan(Im / Re);
		if (Re < 0)
			if (Im >= 0)
				return acos(-1) + atan(Im / Re);
			else
				return -acos(-1) - atan(Im / Re);
		else if (Im > 0)
			return acos(0);
		else if (Im < 0)
			return -acos(0);
	}


	double Re()
	{
		return Re;
	}

	double Im()
	{
		return Im;
	}

};
inline ostream& operator << (ostream& o, const Complex& c)
{
	o << '(' << c.Re << ", " << c.Im << ')';
	return o;
}