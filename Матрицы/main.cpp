#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



class Line;
class EmptyMatrix;




class Columnl
{friend EmptyMatrix;
private:
int Dim;
int* c;
public:
Columnl();
Columnl (int a);
~Columnl();
void Show();
Columnl& operator =(const Columnl& A);};

Columnl::Columnl()
{Dim=0;
c=NULL;}

Columnl::Columnl(int a)
{Dim=a;
c=new int[Dim];
for(int i=0;i<Dim;i++)
{c[i]=rand()%3;}}

Columnl::~Columnl()
{delete[]c;}

void Columnl::Show()
{for(int i=0;i<Dim;i++)
{cout<<c[i]<<endl;}}


// Columnl a, b, c, d;
// a = b;  => a.operator=(b);
// a = b = c = d;
// a = a;
// int y (2);  y = y;
Columnl& Columnl::operator=(const Columnl& A)
{
    if (this==&A) return *this;
    int* c1 =new int [A.Dim];
    for (int i=0;i<A.Dim;i++)
    {
        c1[i]=A.c[i];
    }
    Dim=A.Dim;
    delete[]c;
    c = c1;
    return(*this);
}








class EmptyMatrix
{friend Columnl;
friend Line;
private:
int NumOfLine, NumOfCol, NumOfNotNull;
int* Storage;
int* Column;
int* Line;
public:
EmptyMatrix(int a,int b);
~EmptyMatrix();
void show();
Columnl operator*(const Columnl &B) const;};

EmptyMatrix::EmptyMatrix(int a, int b)
{int m = 0;
NumOfLine = a;
NumOfCol = b;
NumOfNotNull = rand()%(a*b+1);
Storage = new int[NumOfNotNull];
Column = new int[NumOfNotNull];
Line = new int[NumOfNotNull];

for(int i=0;i<NumOfNotNull;i++)
{Storage[i]=rand()%2+1;}

for(int j=0;j<NumOfNotNull;j++)
{Line[j]=rand()%NumOfLine;
Column[j]=rand()%NumOfCol;
for(int k=0;k<j;k++)
{if (Line[j]==Line[k]&&Column[j]==Column[k])
{m = 1;}}
if (m==1)
{j--;}
m=0;}}

EmptyMatrix::~EmptyMatrix()
{delete []Column;
delete []Line;
delete []Column;}

void EmptyMatrix::show()
{int m = 0;
{for(int i=0;i<NumOfLine;i++)
{for(int j=0;j<NumOfCol;j++)
{for(int k=0;k<NumOfNotNull;k++)
{if(Line[k]==i && Column[k]==j)
{cout<<Storage[k]<<" ";
m++;}}
if (m==0)
{cout<<"0 ";}
m=0;}
cout<<endl;}}}

Columnl EmptyMatrix::operator*(const Columnl &B) const
{Columnl D(NumOfLine);
for (int i=0;i<NumOfLine;i++)
{D.c[i]=0;}
for (int j=0;j<NumOfNotNull;j++)
{D.c[Line[j]]=D.c[Line[j]]+Storage[j]*B.c[Column[j]];}
return(D);}








class Line
{private:
int Dim;
int* c;
public:
Line();
Line (int a);
~Line();
void Show ();
Line operator*(const EmptyMatrix& B) const;
Line& operator=(const Line& A);};

Line::Line()
{Dim=0;
c=NULL;}

Line::Line(int a)
{Dim=a;
c=new int[Dim];
for(int i=0;i<Dim;i++)
{c[i]=rand()%3;}}

Line::~Line()
{delete[]c;}

void Line::Show()
{for(int i=0;i<Dim;i++)
{cout<<c[i]<<" ";}}

Line Line::operator*(const EmptyMatrix& B) const
{Line C(B.NumOfCol);
for (int i=0;i<B.NumOfCol;i++)
{C.c[i]=0;}
for (int j=0;j<B.NumOfNotNull;j++)
{C.c[B.Column[j]]=C.c[B.Column[j]]+B.Storage[j]*c[B.Line[j]];}
return(C);}

Line& Line::operator=(const Line& A)
{
    if (this==&A) return *this;
    int* c1 =new int [A.Dim];
    for (int i=0;i<A.Dim;i++)
    {
        c1[i]=A.c[i];
    }
    Dim=A.Dim;
    delete[]c;
    c = c1;
    return(*this);
}





int main()
{int a,b;
srand (time(NULL));
cout<<"enter the number of lines ";
cin>>a;
cout<<"enter the number of columns ";
cin>>b;
EmptyMatrix A(a,b);
A.show();

Columnl Q;
Line W;

int c;
cout<<"enter the dimension of line ";
cin>>c;
Line B(c);
B.Show();
cout<<endl;

int d;
cout<<"enter the dimension of column ";
cin>>d;
Columnl C(d);
C.Show();
cout<<endl;

cout<<"mult matrix by column"<<endl;
Q=A*C;
Q.Show();
cout<<endl;

cout<<"mult line by matrix"<<endl;
W=B*A;
W.Show();
cout<<endl;


return 0;}
