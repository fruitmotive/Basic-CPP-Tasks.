#include <iostream>

using namespace std;

class ComplexNumber
{private:
double RePart;
double ImPart;
public:
ComplexNumber();
void set(double Setter_of_RePart, double Setter_of_ImPart);
void Show();
ComplexNumber Sum(ComplexNumber);
ComplexNumber Sub(ComplexNumber);
ComplexNumber Mult(ComplexNumber);
ComplexNumber Div(ComplexNumber);

ComplexNumber operator+(ComplexNumber);
ComplexNumber operator-(ComplexNumber);
ComplexNumber operator*(ComplexNumber);
ComplexNumber operator/(ComplexNumber);
ComplexNumber operator*(double);
friend ComplexNumber operator*(double,ComplexNumber);

~ComplexNumber();};

ComplexNumber::ComplexNumber()
{RePart=0;
ImPart=0;}

void ComplexNumber::set(double Setter_of_RePart, double Setter_of_ImPart)
{RePart = Setter_of_RePart;
ImPart = Setter_of_ImPart;}

void ComplexNumber::Show ()
{cout<<RePart<<" + "<<"("<<ImPart<<")"<<"*i"<<endl;}

ComplexNumber ComplexNumber::operator+(ComplexNumber A)
{ComplexNumber B;
B.RePart = RePart + A.RePart;
B.ImPart = ImPart + A.ImPart;
return(B);}

ComplexNumber ComplexNumber::operator-(ComplexNumber A)
{ComplexNumber B;
B.RePart = RePart - A.RePart;
B.ImPart = ImPart - A.ImPart;
return(B);}

ComplexNumber ComplexNumber::operator*(ComplexNumber A)
{ComplexNumber B;
B.RePart = RePart*A.RePart - ImPart*A.ImPart;
B.ImPart = RePart*A.ImPart + ImPart*A.RePart;
return(B);}

ComplexNumber ComplexNumber::operator/(ComplexNumber A)
{ComplexNumber B;
B.RePart = (RePart*A.RePart + ImPart*A.ImPart)/((A.RePart)*(A.RePart)+(A.ImPart)*(A.ImPart));
B.ImPart = (ImPart*A.RePart - RePart*A.ImPart)/((A.RePart)*(A.RePart)+(A.ImPart)*(A.ImPart));
return(B);}

ComplexNumber::~ComplexNumber()
{cout<<"Goodbye!"<<endl;}

ComplexNumber ComplexNumber::operator*(double a)
{ComplexNumber B;
B.RePart = RePart*a;
B.ImPart = ImPart*a;
return(B);}

ComplexNumber operator*(double a,ComplexNumber A)
{ComplexNumber B;
B.RePart = A.RePart*a;
B.ImPart = A.ImPart*a;
return(B);}

int main()
{ComplexNumber A, B, C, D;
double a,b,c;

cout<<"Enter the first number: ";
cin>>a;cin>>b;
A.set(a,b);

cout<<"Enter the second number: ";
cin>>a;cin>>b;
B.set(a,b);

cout<<"Enter the third number: ";
cin>>a;cin>>b;
D.set(a,b);

cout<<"Enter the number to multiply the third number by it: ";
cin>>c;

C = A+B;
cout<<"Sum: ";
C.Show();

C = A-B;
cout<<"Subtraction: ";
C.Show();

C = A*B;
cout<<"Multiplication: ";
C.Show();

C = A/B;
cout<<"Division: ";
C.Show();

C = D*c;
cout<<"Multiplication by number as A*a: ";
C.Show();

C = c*D;
cout<<"Multiplication by number as a*A: ";
C.Show();

return 0;}
