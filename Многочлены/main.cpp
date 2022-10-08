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
    vectorND(int b);
    vectorND();
    ~vectorND();
    void show();
};

class polynomial:public vectorND
{
public:
void show();
polynomial():vectorND(){}
polynomial(int b):vectorND(b){}
polynomial operator+(const polynomial &q) const;
polynomial operator*(const polynomial &w) const;
polynomial& operator=(const polynomial &e);
};

vectorND::vectorND(int b)
{
    dim = b;
    storage = new int[dim];
    for(int i=0;i<dim;i++)
    {storage[i]=rand()%3;}
}

vectorND::vectorND()
{
    dim=0;
    storage = NULL;
}

vectorND::~vectorND()
{
    delete[]storage;
}

void polynomial::show()
{
    if (storage[0]==0&&dim==1)
        cout<<0;
    else
    {
        int i = 0;
    while (storage[i] == 0)
        i++;
    if(storage[i]==1)
        cout<<"x^"<<i;
    else
        cout<<storage[i]<<"x^"<<i;

    for(int j=i+1;j<dim;j++)
    {
        if(storage[j]!=0)
        {
            if(storage[j]==1)
                cout<<" + x^"<<j;
            else
                cout<<" + "<<storage[j]<<"x^"<<j;
        }
    }
    }

}

polynomial polynomial::operator+(const polynomial &q) const
{

    polynomial c;
    if (dim>=q.dim)
    {
        c.dim = dim;
        c.storage = new int(c.dim);
        for (int i=0;i<q.dim;i++)
        {
            c.storage[i]=storage[i]+q.storage[i];
        }
        for(int j=q.dim;j<dim;j++)
        {
            c.storage[j]=storage[j];
        }
    }
    else
    {
        c.dim = q.dim;
        c.storage = new int(c.dim);
        for (int i=0;i<dim;i++)
        {
            c.storage[i]=storage[i]+q.storage[i];
        }
        for(int j=dim;j<q.dim;j++)
        {
            c.storage[j]=q.storage[j];
        }

    }
return(c);
}

polynomial polynomial::operator*(const polynomial &w) const
{
    polynomial c;
    c.dim = w.dim+dim-1;
    c.storage = new int[c.dim];
    for (int i=0;i<c.dim;i++)
    {
        c.storage[i]=0;
    }
    for (int k=0;k<w.dim;k++)
    {
        for (int j=0;j<dim;j++)
        {
            c.storage[j+k]=c.storage[j+k]+w.storage[k]*storage[j];
        }
    }
    return(c);
}

polynomial& polynomial::operator=(const polynomial &e)
{
    if(this==&e)
        return(*this);
    else
    {
        int*a=new int[e.dim];
        for (int i=0;i<e.dim;i++)
            a[i]=e.storage[i];
        dim=e.dim;
        storage=a;
        return(*this);
    }
}

int main()
{
    srand (time(NULL));
    int b;
    cin>>b;
    int c;
    cin>>c;
    polynomial a(b);
    a.show();
    cout<<endl;
    polynomial d(c);
    d.show();
    cout<<endl;
    polynomial z=a+d;
    z.show();
    cout<<endl;
    polynomial x=a*d;
    x.show();
}
