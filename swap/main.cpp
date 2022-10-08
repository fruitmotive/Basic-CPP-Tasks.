#include <iostream>

using namespace std;



int main()
{
    double a, b;


    cin>>a;
    cin>>b;
cout<<a<<" "<<b<<endl;
    a=(a+b)/2;
    b=b-2*(b-a);
    a=a+(b-a);


    cout<<a<<" "<<b;



    return 0;
}
