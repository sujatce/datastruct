#include <iostream>
#include <unordered_map>

using namespace std;
int global = 1;

int doSomething(int n, int m)
{
    global++;
    if(n<=1)
        return 1;
    return (n%m) + doSomething(n/m,m);    
}

int main()
{
    //for(int i=1;i<21;i++)
        //cout<< doSomething(i,7)<<endl;
    cout<<doSomething(3,10000)<<endl;
    cout<<global<<endl;
    return EXIT_SUCCESS;
}