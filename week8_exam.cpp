


#include <iostream>
#include <unordered_map>

using namespace std;

class MyQueue{
    public:
        vector<int> s1;
        vector<int> s2;

        void enqueue(int val)        {
            s1.push_back(val);
        }

        void dequeue()        {

            if(s1.empty())            {
                cout<<"Warning! Queue is empty!!" <<endl;
                return;
            }

            while(!s1.empty())            {
                s2.push_back(s1.back());
                s1.pop_back();
            }
            s2.pop_back();

            while(!s2.empty()){
                s1.push_back(s2.back());
                s2.pop_back();
            }
        }

        int size()        {
            return s1.size();
        }

        friend ostream & operator << (ostream &out, MyQueue *q);

        void print()
        {
            for(int i=0;i<s1.size();i++)
            {
                cout<<s1[i]<<"-->";
            }
            cout<<endl;
        }
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->enqueue(1);
    obj->enqueue(2);
    obj->enqueue(3);
    obj->enqueue(4);
    obj->print();
    obj->dequeue();
    obj->dequeue();
    obj->dequeue();
    obj->dequeue();
    obj->dequeue();
    obj->dequeue();
    obj->enqueue(5);
    obj->print();
    return EXIT_SUCCESS;
}