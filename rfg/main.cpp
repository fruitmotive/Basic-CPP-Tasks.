#include <iostream>

using namespace std;

int main()
{
    double a,b;
    cin>>a;
    cin>>b;
    cout<<a<<endl;
    cout<<b<<endl;
    a=(a+b)/2;
    b=b-2*(b-a);
    a=b+2*(a-b);
    cout<<a<<endl;
    cout<<b<<endl;
}
