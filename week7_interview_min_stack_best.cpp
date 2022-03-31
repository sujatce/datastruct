#include <iostream>
using namespace std;

class MinStack {
public:
    struct node
    {
        int val;
        int min;
        node* next = NULL;
    }; 
    node* tail = NULL;
    MinStack() {

    }
    
    void push(int val) {
        node* temp = new node();
        temp->val = val;
        temp->next = tail;
        if(tail==NULL || val < tail->min)
            temp->min = val;
        else
            temp->min = tail->min;
        tail = temp;
    }
    
    void pop() {
        tail = tail->next;
    }
    
    int top() {
        return tail->val;
    }
    
    int getMin() {
        return tail->min;
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
        int param_3 = obj->top();
    int param_4 = obj->getMin();
    //obj->pop();

    int param_5 = obj->getMin();
    cout<<"Value of min 1"<<param_4<<endl;
    cout<<"Value of top "<<param_3<<endl;
    cout<<"Value of min 2"<<param_5<<endl;
    return EXIT_SUCCESS;
}