#include <iostream>
#include <cmath>
#include <chrono>
using namespace std::chrono;

using namespace std;

void normalalgorithm(int number)
{
    int  bigterm = 0;
    int  bigtermnumber = 0;

    for(int j=1;j<=number;j++)
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
    cout<<"Normal Algorithm - Biggest sequence producing number is "<<bigtermnumber<<". Number of terms is "<<bigterm<<endl;
}

void improvedalgorithm(int number)
{
    int  bigterm = 0;
    int  bigtermnumber = 0;

    int *cache = new int[number+1]; //if we declare a static array, memory exception happens, hence changed it to pointer array
    //initialize cache
    for(int i=0;i<number+1; i++)
        cache[i] = -1;
    cache[1] = 1;

    for(int j=1;j<=number;j++)
    {
        long long  n = j;
        int  terms = 0;

        //cout << j;
        while(n!=1 && n >= j)
        {
            terms++;
            if(n%2==0)
                n = n/2;
            else
                n = (3*n)+1;
            //cout << "->" << n;
        }

        cache[j] = terms + cache[n];        
        //cout << "\t\t Terms = " << terms << endl;
        if(cache[j] > bigterm)
        {
            bigterm = cache[j];
            bigtermnumber = j;
        }
    }
    cout<<"Improved Algorithm - Biggest sequence producing number is "<<bigtermnumber<<". Number of terms is "<<bigterm<<endl;
}

int main() {
    auto start = high_resolution_clock::now();
    normalalgorithm(1000000);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
     cout << "Time taken by Normal Algorithm function: "
         << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    improvedalgorithm(1000000);
    stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop - start);
     cout << "Time taken by Improved Algorithm function: "
         << duration1.count() << " microseconds" << endl;

    cout<< "Algorithm is improved by "<<(duration-duration1)*100/duration1<< "%"<<endl;
    return 0;
}