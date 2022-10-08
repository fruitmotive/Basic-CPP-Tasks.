#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;


class vectorND
{
protected:
    int* storage;
    int dim;
public:
    vectorND(int);
    vectorND();
    vectorND(const vectorND&);
    ~vectorND();
    vectorND& operator =(const vectorND&);
    friend ostream& operator << (ostream&,const vectorND&);
};


vectorND::vectorND(int b)
{
    dim = b;
    storage = new int[dim];
    for(int i=0;i<dim;i++)
    {storage[i]=rand()%10;}
}


vectorND::vectorND()
{
    dim = 0;
    storage = NULL;
}


vectorND::vectorND(const vectorND &A)
{
    int* B = new int [A.dim];
    for (int i=0;i<A.dim;i++)
    {
        B[i] = A.storage[i];
    }
    dim = A.dim;
    storage = B;
}


vectorND::~vectorND()
{
    delete[]storage;
}


vectorND& vectorND::operator = (const vectorND &A)
{
    if (this==&A) return *this;
    int* B = new int [A.dim];
    for (int i=0;i<A.dim;i++)
    {
        B[i] = A.storage[i];
    }
    dim = A.dim;
    delete[]storage;
    storage = B;
    return *this;
}


ostream& operator << (ostream &s,const vectorND &v)
{
    int i = 0;
    s<<"(";
    for (int i;i<v.dim-1;i++)
    {
        cout<<v.storage[i]<<",";
    }
    cout<<v.storage[i]<<") ";
    return s;
}


template<class T>
void My_Swap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}


int main()
{
    srand (time(NULL));

    int a,b,c,d;
    double e,f;
    cout<<"dimension 1: "; cin>>a;
    cout<<"dimension 2: "; cin>>b;
    cout<<"int number 1: "; cin>>c;
    cout<<"int number 2: "; cin>>d;
    cout<<"double number 1: "; cin>>e;
    cout<<"double number 2: "; cin>>f;

    vectorND V(a);
    vectorND W(b);
    cout<<V<<W<<endl;
    My_Swap(V,W);
    cout<<V<<W<<endl;

    cout<<c<<" "<<d<<endl;
    My_Swap(c,d);
    cout<<c<<" "<<d<<endl;

    cout<<e<<" "<<f<<endl;
    My_Swap(e,f);
    cout<<e<<" "<<f<<endl;

    vectorND Q(W);
    cout<<Q<<W<<endl;

    return 0;
}



