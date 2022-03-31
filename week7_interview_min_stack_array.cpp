#include <iostream>
using namespace std;

class MinStack {
public:
    int *arr = new int[10000];
    int tos = -1;
    MinStack() {
    }
    
    void push(int val) {
        if(tos<=-1)
        {
            tos = 0;
            arr[tos] = val;
        }
        else
        {
            arr[++tos] = val;
        }
    }
    
    void pop() {
        tos--;
    }
    
    int top() {
        if(tos>=0)
            return arr[tos];
        return NULL;
    }
    
    int getMin() {
        if(tos<=-1)
        {
            return NULL;
        }
        int min = arr[0];
        for(int i=1;i<=tos;i++)
        {
            if(arr[i] < min)
                min = arr[i];
        }
        return min;
    }
    void print()
    {
        for(int i=tos;i>=0;i--)
        {
            cout<< arr[i] << "->" ;
        }
        cout<< "NULL"<<endl;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack* obj = new MinStack();    
    obj->push(-1);
    obj->print();
        int param_3 = obj->top();
    int param_4 = obj->getMin();
    //obj->pop();

    int param_5 = obj->getMin();
    cout<<"Value of min 1"<<param_4<<endl;
    cout<<"Value of top "<<param_3<<endl;
    cout<<"Value of min 2"<<param_5<<endl;
    return EXIT_SUCCESS;
}