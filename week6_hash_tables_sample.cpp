#include <iostream>
#include <unordered_map>
using namespace std;

int f0(int i)
{
    return (i*i) % INT_MAX;
}

bool f1(string s)
{
    unordered_map<char,bool> ht;
    for(int i=0; i<s.size();i++)
    {
        if(ht[s[i]])
        {
            return false;
        }
        ht[s[i]]= true;
    }
    return true;
}

bool f2(string s1, string s2)
{
    if(s1.size() != s2.size())
        return false;
    unordered_map<char,int> hm;
    for(int i=0; i<s1.size();i++)
    {
        hm[s1[i]]++;
    }
    for(int i=0; i<s2.size();i++)
    {
        hm[s2[i]]--;
        if(hm[s2[i]]<0)
            return false;
    }
    return true;
}


int main()
{
    /*unordered_map<char,double> grades;
    grades['W'] = 4.0;
    grades['X'] = 3.9;
    grades['Y'] = 3.9;
    grades['Z'] = 4.0;
    for (auto i = grades.begin();i!=grades.end();i++)
    {
        cout<<i->first << "'s grades is: "<<i->second <<endl;
    }
    cout<<grades.load_factor()<<endl;
    cout<<"hello"<<endl;
    cout<<f0(128)<<endl;
    cout<<f0(12345)<<endl;
    cout<<f1("abcd")<<endl;
    cout<<f1("ab")<<endl;
    cout<<f1("a")<<endl;*/
    cout<<f2("abc","abc")<<endl;
    cout<<f2("abc","bca")<<endl;
    cout<<f2("abc","d")<<endl;
    return EXIT_SUCCESS;
}