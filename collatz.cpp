#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int  bigterm = 0;
    int  bigtermnumber = 0;
    //Takes each number to from 1 to 1000000 to calculate the sequence 
    for(int j=1;j<=1000000;j++)
    {
        long long  n = j;
        int  terms = 1;
        //cout << j;
        while(n!=1)
        {
            if(n%2==0)
                n = n/2;
            else
                n = (3*n)+1;
            terms++;
            //cout << "->" << n;
        }
        //cout << "\t\t Terms = " << terms << endl;
        if(terms > bigterm)
        {
            bigterm = terms;
            bigtermnumber = j;
        }
    }
    cout<<"biggest sequence producing number is "<<bigtermnumber<<". Number of terms is "<<bigterm;
    return 0;
}