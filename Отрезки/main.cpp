#include <iostream>
#include <cmath>

using namespace std;

class empty_set
{
public:
    empty_set(){};
    virtual void show();
};

class point: public empty_set
{
protected:
    double x1,y1;
public:
    point(double a, double b):empty_set(),x1(a),y1(b){};
    void show();
};

class section: public point
{
protected:
    double x2,y2;
public:
    section(double q,double w,double e,double r):point(q,w),x2(e),y2(r){};
    void show();
    empty_set* operator*(section A);
};

void empty_set::show()
{
    cout<<"empty set"<<endl;
}

void point::show()
{
    cout<<"point("<<x1<<","<<y1<<")"<<endl;
}

void section::show()
{
    cout<<"section[("<<x1<<","<<y1<<")->("<<x2<<","<<y2<<")]"<<endl;
}

empty_set* section::operator*(section A)
{
    double SM = fabs((x2-x1)*(A.x2-A.x1)+(y2-y1)*(A.y2-A.y1));
    double L1 = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double L2 = sqrt((A.x2-A.x1)*(A.x2-A.x1)+(A.y2-A.y1)*(A.y2-A.y1));
    double LM = L1*L2;
    double COS = fabs(SM)/LM;
    double SIN = sqrt(1-COS*COS);
    double i,j;
    int k = 0;
    double H1,H2,A1,A2,B1,B2,h,g,q,w;
    double e = 0.01;

    if (fabs(SM-LM) > e)
    {
            if((fabs(A.x2-A.x1) > e)&&(fabs(x2-x1)) > e)
            {
                H1 = (fabs((y1-y2)/(x2-x1)*A.x1 + A.y1 + ((x1*y2-y1*x2)/(x2-x1))))/(sqrt((((y1-y2)/(x2-x1))*((y1-y2)/(x2-x1))+1)));
                H2 = (fabs((y1-y2)/(x2-x1)*A.x2 + A.y2 + ((x1*y2-y1*x2)/(x2-x1))))/(sqrt((((y1-y2)/(x2-x1))*((y1-y2)/(x2-x1))+1)));
                if(fabs((H1+H2)/SIN - L2) < e)
                {
                    A1 = (y1-y2)/(x2-x1);
                    B1 = (x1*y2-y1*x2)/(x2-x1);
                    A2 = (A.y1-A.y2)/(A.x2-A.x1);
                    B2 = (A.x1*A.y2-A.y1*A.x2)/(A.x2-A.x1);
                    i = (B2-B1)/(A1-A2);
                    j = -A1*(B2-B1)/(A1-A2)-B1;
                    k++;
                }
            }

            if(fabs(x2-x1) < e)
            {
                H1 = (fabs((A.y1-A.y2)/(A.x2-A.x1)*x1 + y1 + ((A.x1*A.y2-A.y1*A.x2)/(A.x2-A.x1))))/sqrt((((A.y1-A.y2)/(A.x2-A.x1))*((A.y1-A.y2)/(A.x2-A.x1))+1));
                H2 = (fabs((A.y1-A.y2)/(A.x2-A.x1)*x2 + y2 + ((A.x1*A.y2-A.y1*A.x2)/(A.x2-A.x1))))/sqrt((((A.y1-A.y2)/(A.x2-A.x1))*((A.y1-A.y2)/(A.x2-A.x1))+1));
                if(fabs((H1+H2)/SIN - L1) < e)
                {
                    A2 = (A.y1-A.y2)/(A.x2-A.x1);
                    B2 = (A.x1*A.y2-A.y1*A.x2)/(A.x2-A.x1);
                    i = x1;
                    j = -A2*x1-B2;
                    k++;
                }
            }

            if(fabs(A.x2-A.x1) < e)
            {
                H1 = (fabs((y1-y2)/(x2-x1)*A.x1 + A.y1 + ((x1*y2-y1*x2)/(x2-x1))))/sqrt((((y1-y2)/(x2-x1))*((y1-y2)/(x2-x1))+1));
                H2 = (fabs((y1-y2)/(x2-x1)*A.x2 + A.y2 + ((x1*y2-y1*x2)/(x2-x1))))/sqrt((((y1-y2)/(x2-x1))*((y1-y2)/(x2-x1))+1));
                if(fabs((H1+H2)/SIN) == L2)
                {
                   A1 = (y1-y2)/(x2-x1);
                   B1 = (x1*y2-y1*x2)/(x2-x1);
                   i = A.x1;
                   j = -A1*x1-B1;
                   k++;
                }
            }
    }

if(k!=0)
    {
        empty_set* res = new point(i,j);
        return(res);
    }




        if((fabs(x2-x1)<e)&&(fabs(A.x2-A.x1)<e)&&(x2-A.x2<e)&&(fabs(SM-LM) < e))
           {
               if(y1>y2)
               {
                   double f = y1;
                   y1 = y2;
                   y2 = f;
               }
               if(A.y1>A.y2)
               {
                   g = A.y1;
                   A.y1 = A.y2;
                   A.y2 = g;
               }
               if(A.y1<=y2&&A.y2>=y2)
               {
                   h = A.y1;
                   g = y2;
                   k++;
               }
               if(A.y1<=y1&&A.y2>=y1)
               {
                   h = y1;
                   g = A.y2;
                   k++;
               }

           }

if(k!=0)
    {
        if(fabs(h-g)<e)
        {
            empty_set* res = new point(x1,h);
            return(res);
        }
        else
        {
            empty_set* res = new section(x1,h,x1,g);
            return(res);
        }
    }



B1 = (x1*y2-y1*x2)/(x2-x1);
B2 = (A.x1*A.y2-A.y1*A.x2)/(A.x2-A.x1);

if((fabs(B1-B2)<e)&&(fabs(SM-LM) < e))
           {
               if(x1>x2)
               {
                   double f = x1;
                   x1 = x2;
                   x2 = f;
                   f = y1;
                   y1 = y2;
                   y2 = f;
               }

               if(A.x1>A.x2)
               {
                   double u = A.x1;
                   A.x1 = A.x2;
                   A.x2 = u;
                   u = A.y1;
                   A.y1 = A.y2;
                   A.y2 = u;
               }

               if(A.y1<=y2&&A.y2>=y2&&A.x1<=x2&&A.x2>=x2)
               {
                   h = A.x1;
                   g = A.y1;
                   q = x2;
                   w = y2;
                   k++;
               }

               if(A.y1<=y1&&A.y2>=y1&&A.x1<=x1&&A.x2>=x1)
               {
                   h = x1;
                   g = y1;
                   q = A.x2;
                   w = A.y2;
                   k++;
               }

               if(A.y1>=y2&&A.y2<=y2&&A.x1<=x2&&A.x2>=x2)
               {
                   h = A.x1;
                   g = A.y1;
                   q = x2;
                   w = x1;
                   k++;
               }

               if(A.y1>=y1&&A.y2<=y1&&A.x1<=x1&&A.x2>=x1)
               {
                   h = x1;
                   g = y1;
                   q = A.x2;
                   w = A.y2;
                   k++;
               }

           }
if(k!=0)
    {
        if((fabs(h-q)<e)&&(fabs(g-w)<e))
        {
            empty_set* res = new point(h,g);
            return(res);
        }
        else
        {
            empty_set* res = new section(h,g,q,w);
            return(res);
        }
    }



if(k==0)
    {
        empty_set* res = new empty_set();
        return(res);
    }
}



int main()
{

    double q,w,e,r,t,y,u,i;

    cout<<"the first section: "<<endl;
    cin>>q>>w>>e>>r;
    cout<<"the second section: "<<endl;
    cin>>t>>y>>u>>i;

    section a(q,w,e,r);
    a.show();
    section b(t,y,u,i);
    b.show();


    cout<<"the solution is ";
    empty_set *res;
    res=a*b;
    res->show();
    delete res;

    return(0);
}


