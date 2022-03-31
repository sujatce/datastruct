#include <iostream>
#include <vector>
using namespace std;

void pprint(vector<int> &s1)
{
    for(int i=0;i<s1.size();i++)
    {
        cout<<s1[i]<<"-->";
    }
    cout<<endl;
}

void sortStack(vector<int> &s1)
{
    vector<int> s2;
    int s1count = s1.size();
    int max = INT_MIN;
    cout<<max<<endl;
    int top = 0;
    while(s1count > 0)
    {
        max = INT_MIN;
        for(int i=0; i<s1count; i++)
        {
            top = s1.back();                                                                    //Question 1 {s2.back() top=s2.back()}
            if(top>max)
            {
                max = top;  //Question 2   top = max
            }
            s1.pop_back();
            s2.push_back(top); //Question 3  s1.push_back(top)
        }        
        cout<<"Maximum element is found - which is "<<max<<endl;
        //Found max push it to the bottom of s1
        s1.push_back(max); //Question 4  s2.push_back(max)
        //next outer loop should go until the element that just got pushed
        s1count--; //Question 5
        //put back elements from s2 to s1
        
        //pprint(s1);
        //pprint(s2);

        while(!s2.empty())
        {
            top = s2.back(); //Question 6
            if(top == max)
            {
                s2.pop_back();  //Question 7
            }
            else
            {
                s1.push_back(top);  //Question 8
                s2.pop_back();
            }
        }
    }
}



int main()
{
    vector<int> age = {1,7,8,2,3};
    sortStack(age);
    for(int i=0;i<age.size();i++)
    {
        cout<<age[i]<<"-->";
    }
    cout<<endl;
}