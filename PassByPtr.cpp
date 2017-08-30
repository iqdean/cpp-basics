// CppPassByPtr.cpp 

// 8/27/17	1.0  	Ike Dean
// Refresher on Cpp Programming basics
// To compile/link and run on Linux:    
// 	$ g++ -o CppPassByPtr CppPassByPtr.cpp
// 	         <urProgName> <source code file>

#include <iostream>
using namespace std;

// Color Class Object - holds [r,g,b] color values

class Color
{       
//member variables
	public:
		unsigned char r;    // unsigned char  0-255
		unsigned char g;
		unsigned char b;

// constructor
	Color(unsigned char red, unsigned char grn, unsigned char blu)
	{
		r = red;
		g = grn;
		b = blu;
	}
};

// ModColor object - a class that modifies the Color object passed in as a POINTER

class ModColor
{
	public:
	Color* _pColor;

	ModColor(){}

	void Inc(Color* pColorIn)
	{
		_pColor = pColorIn;
		++_pColor->r;
		++_pColor->g;
		++_pColor->b;
	}

	void Dec(Color* pColorIn)
        {
		_pColor = pColorIn;
                --_pColor->r;
                --_pColor->g;
                --_pColor->b;
        }

	void Print( Color* pColorIn)
	{
		_pColor = pColorIn;
		cout << "MyColor.r: " << (int) _pColor->r << " MyColor.g: " << (int) _pColor->g << " MyColor.b: " << (int) _pColor->b << endl;
	}
};

int main()
{
	cout << "instance MyColor object..." << endl;
	Color MyColor(255,0,128);
	
	cout << "instance MyModColor object ..." << endl;
	ModColor MyModColor;
	MyModColor.Print(&MyColor);

	MyModColor.Inc(&MyColor);
        MyModColor.Print(&MyColor);

	MyModColor.Dec(&MyColor);
        MyModColor.Print(&MyColor);
}

