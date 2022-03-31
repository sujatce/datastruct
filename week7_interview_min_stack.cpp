#include <iostream>
using namespace std;

class MinStack {
public:
    struct node
    {
        int val;
        node* next = NULL;
    }; 
    node* tail = NULL;
    MinStack() {

    }
    
    void push(int val) {
        node* temp = new node();
        temp->val = val;
        temp->next = tail;
        tail = temp;
    }
    
    void pop() {
        if(tail!=NULL)
        {
            cout<<"This is popped "<<tail->val<<endl;
            tail = tail->next;
        }        
    }
    
    int top() {
        if(tail!=NULL)
            return tail->val;
        return NULL;
    }
    
    int getMin() {
        node* temp = tail;
        int min;
        if(tail!=NULL)
            min = tail->val;
        else
            return NULL;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            if(temp->val < min)
                min = temp->val;
        }
        return min;
    }
    void print()
    {
        node* temp = tail;
        while (temp!=NULL)
        {
            cout<< temp->val << "->" ;
            temp = temp->next;
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
    obj->push(1);
    obj->push(10);
    obj->push(120);
    obj->push(110);
    obj->push(-310);
    obj->print();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->print();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout<<"Value of min "<<param_4;
    return EXIT_SUCCESS;
}