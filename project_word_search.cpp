#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include<algorithm>

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int countwords=0;
    time_t start, end;
	string path = "c://files//100000000.txt";
	string line;
	string word="juqhib";
    vector<string> allwords;
	cout<<"Write the path of the file."<<endl;
	//cin>>path;
	ifstream File(path);
	if(File.is_open())
	{
        time(&start);
		while(getline(File,line))
		{
            allwords.push_back(line);
			//cout<<line<<endl;
            if(word.compare(line)==0)
				countwords++;
		}
		time(&end);

        double time_taken = double(end - start);
        cout<<"start time"<<start<<endl;
        cout<<"end time"<<end<<endl;
        cout << "Time taken by program is : "<<time_taken;
        //cout << " sec " << endl;

		cout<<"Write the word you're searching for."<<endl;
		//cin>>word;
        time(&start);
        for(double i=0;i<allwords.size();i++)
        {
            if(word.compare(allwords[i])==0)
            {
                cout<<"Word is found"<<endl;
                break;
            }
        }
        /*if (std::find(allwords.begin(), allwords.end(), word) != allwords.end())
        {
            cout<<"The word has been found through vector search"<<endl;
        // Element in vector.
        }*/
        time(&end);

        time_taken = double(end - start);
        cout<<"start time"<<start<<endl;
        cout<<"end time"<<end<<endl;
        cout << "Time taken by program is : "<<time_taken;
		/*while(!File.eof())
		{
			if(word.compare(line)==0)
				countwords++;
		}*/
		cout<<"The word has been found "<<countwords<<" times."<<endl;
		File.close();
	}
	else
	{
		cout<<"Error! File not found!";
		exit(1);
	}
}