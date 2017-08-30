// CppPassByRef.cpp 

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

// ModColor Class Object with methods designed to use parameters 
// that are passed-by-reference: 
//
// Return_Type  Function_Name(Param1type& Param1, Param2type& Param2, etc)
//                                      |                   |
// The & designates a reference in cpp__/___________________/

class ModColor
{
	public:

	ModColor(){}

	void Inc(Color& ColorIn)
	{
		++ColorIn.r;
		++ColorIn.g;
		++ColorIn.b;
	}

	void Dec(Color& ColorIn)
        {
                --ColorIn.r;
                --ColorIn.g;
                --ColorIn.b;
        }

	void Print( Color& ColorIn)
	{
		cout << "MyColor.r: " << (int) ColorIn.r << " MyColor.g: " << (int) ColorIn.g << " MyColor.b: " << (int) ColorIn.b << endl;
	}
};

class TC1
{
	public:
	TC1(){}

	void Test1(Color& ColorIn, ModColor& Modulator)
	{
		Modulator.Print(ColorIn);
		Modulator.Dec(ColorIn);
		Modulator.Print(ColorIn);
		Modulator.Inc(ColorIn);
		Modulator.Print(ColorIn);

	}
};

int main()
{
	cout << "instance MyColor object..." << endl;
	Color MyColor(255,0,128);
	
	cout << "instance MyModColor object ..." << endl;
	ModColor MyModColor;
	MyModColor.Print(MyColor);

	MyModColor.Inc(MyColor);
        MyModColor.Print(MyColor);

	MyModColor.Dec(MyColor);
        MyModColor.Print(MyColor);

	for (int i = 0; i<10; i++)
	{
	 MyModColor.Inc(MyColor);
	}

	cout << "=========================================================== " << endl;
	cout << "instance myTC1 class & call myTC1.Test(MyColor, MyModColor) " << endl;
	TC1 myTC1;
	myTC1.Test1(MyColor, MyModColor);

}

