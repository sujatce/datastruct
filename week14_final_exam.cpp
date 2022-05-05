#include <iostream>
#include <unordered_map>
using namespace std;

void swap(int x, int y)
{
    int temp = x;
    x=y;
    y=temp;
}

bool check(string s1, string s2)
{
    int counter = 0;
    for(int i=0; i<s1.size();i++)
    {
        if(s1[i] != s2[i])
        {
            counter++;
            if(counter>1)
            {
                return false;
            }
        }
    }
    return true;
}

bool check2(string s1, string s2)
{
    if(s1.size() - s2.size() > 1)
    {
        return false;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<s1.size())
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            k++;
        }
    }
    return k==1;
}

int main(){
   /* int x = 10;
    int * ptr;
    ptr = &x;
    *ptr = 11;
    int y;
    y = *ptr;
    ptr = &y;
    cout<<x<<endl;
    cout<<y<<endl;*/

    /*int array[6] = {1,500,3,8,6,20};
    int x = *array;
    int y = 0;
    for (int i=1;i<6;i++)
    {
        cout<<"value of *(array+i)="<<*(array+i)<<"\ti="<<i<<"x="<<x<<endl;
        if(*(array+i) > x)
        {
            x = *(array+i);
            y = i;
        }
    }
    cout<<y<<endl;
    */

    /*int a = 1;
    int b = 10;
    swap(a,b);
    cout<<"a is: "<< a << " and b is: " << b <<endl;*/
   
    cout<<check("abc","abc")<<endl;
    cout<<check("abc","cba")<<endl;
    cout<<check2("a","ab")<<endl;
    cout<<check2("abc","ab")<<endl;
    return EXIT_SUCCESS;
}