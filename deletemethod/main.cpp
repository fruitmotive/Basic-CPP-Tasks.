#include <iostream>

using namespace std;

class matrix
{
private:
    int* element;
    int lines;
    int columns;
public:
    void dellin (int a);
    void delcol (int a);
    matrix (int a, int b);
    ~matrix ();
    void show();
    matrix& operator = (const matrix &A);
};


matrix::~matrix()
{
    delete []element;
}


matrix::matrix(int a, int b)
{
    lines = a;
    columns = b;
    element = new int[a*b];
    for (int i = 0;i<a*b;i++)
    {
        element[i] = i;
    }
}


void matrix::show()
{
    for(int i=1;i<=lines*columns;i++)
        {
            if (i%columns==0)
            {
                cout<<element[i-1]<<endl;
            }
            else
            {
                if(element[i-1]>9)
                cout<<element[i-1]<<" ";
                else
                cout<<element[i-1]<<"  ";
            }
        }
}


matrix& matrix::operator = (const matrix &A)
{
    if (this==&A) return *this;
    int* B = new int [A.columns*A.lines];
    for (int i=0;i<A.columns*A.lines;i++)
    {
        B[i] = A.element[i];
    }
    lines=A.lines;
    columns=A.columns;
    delete[]element;
    element = B;
    return *this;
}


void matrix::dellin (int a)
{
    int j=1;
    int* p = new int[(lines-1)*columns];
    for (int i = 1;i<=(a-1)*columns;i++)
        {
            p[j-1]=element[i-1];
            j++;
        }
    for (int i = a*columns+1;i<=columns*lines;i++)
    {
        p[j-1]=element[i-1];
        j++;
    }
    delete[]element;
    element=new int[(lines-1)*columns];
    for(int i=0;i<(lines-1)*columns;i++)
    {
        element[i]=p[i];
    }
    lines=lines-1;
}


void matrix::delcol (int a)
{
    int*p=new int[(columns-1)*lines];
    int j = 1;
    for(int i = 1;i<=columns*lines;i++)
    {
        if(i%columns != a)
        {
            p[j-1]=element[i-1];
            j++;
        }
    }
    delete[]element;
    element=new int[lines*(columns-1)];
    for(int i=0;i<lines*(columns-1);i++)
    {
        element[i] = p[i];
    }
    columns = columns - 1;

}


int main()
{
    int a, b ,c, d;
    cout<<"lin: "; cin>>a; cout<<endl;
    cout<<"col: "; cin>>b; cout<<endl;
    cout<<"line need to delete: "; cin>>c; cout<<endl;
    cout<<"column need to delete: "; cin>>d; cout<<endl;
    matrix A(a,b);
    A.show();
    cout<<endl;
    cout<<endl;
    A.dellin(c);
    A.show();
    cout<<endl;
    cout<<endl;
    A.delcol(d);
    A.show();

return 0;

}
