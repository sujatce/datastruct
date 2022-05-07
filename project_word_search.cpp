#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sys/time.h>
#include <ctime>
#include<algorithm>

#include <bits/stdc++.h>
using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;
using namespace std;

class WordSearch 
{
    public:
    virtual void insert(string key) = 0;
    virtual int search(string key){
        return 0;
    }
};

class MyVector : public WordSearch {
    public:
    vector<string> allwords;
    MyVector()
    {        
    }
    void insert(string key) 
    {
        allwords.push_back(key);        
    }
    int search(string key)
    {
        if (std::find(allwords.begin(), allwords.end(), key) != allwords.end())
        {
            return 1;
        // Element in vector.
        }
        return -1;
        /*for(double i=0;i<allwords.size();i++)
        {
            if(word.compare(allwords[i])==0)
            {
                cout<<"Word is found"<<endl;
                break;
            }
        }*/        
    }
};

class MyHashMap : public WordSearch {
    
public:   
    struct node
    {
        string key = "";
        node* next = NULL;
    };
    int hashSize = 10;
    node* nodeArr;
    const int p = 31;
    const int m = 1e9 + 7;
        
    MyHashMap(int hSize) {
        hashSize = hSize;
        nodeArr = new node[hashSize];
    }
    
    void insert(string key) 
    {
        int index = hashFunction(key);
        if(nodeArr[index].key=="") //Empty Head
        {
            nodeArr[index].key = key;
            return;
        }
        
        node* temp = new node();
        temp->key = nodeArr[index].key;
        temp->next = nodeArr[index].next;
        nodeArr[index].key = key;
        nodeArr[index].next = temp;
    }
    int hashFunction(string key)
    {
        int hash_so_far = 0;
        long p_pow = 1;
        const int n = key.length();
        for (int i = 0; i < n; ++i) {
            hash_so_far = (hash_so_far + (key[i] - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_so_far%hashSize;
    }
    
    int search(string key) {
        int index = hashFunction(key);
        node* ptr = &nodeArr[index];
        while(ptr!=NULL)
        {
            if(ptr->key.compare(key)==0)
                return 1;
            ptr = ptr->next;
        }
        return -1;
    }

};

int main()
{
    double time_taken;
	string path = "c://files//100000000.txt";
    cout<<"Please enter the file name (full path: ex: c://files/1000.txt) to load : "<<endl;
    cin>>path;
    //string path = "c://files//1000.txt";
	string line;
	string word="zpotat";//"juqhib";
    
    cout<<"Please enter the choice of followind data structure.\n\t Enter 1 for Vector Datastructure,\n\t Enter 2 for HashTable Datastructure with small HashSize of 10,\n\t Enter 3 for HashTable Datastruture with optimal hashsize of 1000"<<endl;
    int option = 1;
    cin>>option;
    WordSearch* wordDS;
    if(option ==1)
    {
        MyVector obj;
        wordDS = &obj;
        cout<<"Vector Datastructure is chosen. "<<endl;
    }
    else if(option == 2 || option ==3)
    {
        int hSize = option ==2 ? 10 : 1000;
        MyHashMap obj(hSize);
        wordDS = &obj;
        cout<<"Hashtable Datastructure is chosen. "<<endl;
    }
    else
    {
        cout<<"Invalid option entered; Default option is selection which is Vector Datastructure (Linear List Structure)"<<endl;
        MyVector obj;
        wordDS = &obj;
    }

	ifstream File(path);
	if(File.is_open())
	{
        cout<<"File is being read and datastructure is being loaded........"<<endl;
        auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		while(getline(File,line))
		{
            wordDS->insert(line);
		}
        File.close();
        auto end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

        time_taken = double(end - start);
        cout<<"Successfully loaded the datastructure with the words from the file"<<endl;
        cout<<"start time : "<<start<<endl;
        cout<<"end time   : "<<end<<endl;
        cout << "Time taken for reading from the file and loading the data structure is : "<<time_taken<<" milliseconds"<<endl;

        while(true)
        {
		    cout<<"\nPlease enter the word you are searching for. TYPE END to quit the program"<<endl;
		    cin>>word;
            if(word.compare("END")==0)
            {
                exit(1);
            }

        start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        if(wordDS->search(word)>0)
        {
            cout<<"Word is found"<<endl;
        }
        else
        {
            cout<<"Word is NOT found"<<endl;
        }
        end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

        time_taken = double(end - start);
        cout<<"start time"<<start<<endl;
        cout<<"end time"<<end<<endl;
        cout << "Time taken by program is : "<<time_taken<<" milliseconds";

        }
		
	}
	else
	{
		cout<<"Error! File not found!";
		exit(1);
	}
}