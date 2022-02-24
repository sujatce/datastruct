#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
};

int main(){
    node *n1 = new node();
    n1->val = 10;
    n1->next = nullptr;

    node *n2 = new node();
    n2->val = 20;
    n2->next = nullptr;

    n1->next = n2;

    node *n3 = new node();
    n3->val = 20;
    n3->next = nullptr;

    n2->next = n3;

    cout << "1st node is: " <<n1->val <<endl;
    cout << "2nd node is: " <<n2->val <<endl;
    cout << "2nd node is: " <<n1->next->val <<endl;

    node *iter = n1;
    while (iter !=nullptr)
    {
        cout<< iter->val << "->";
        iter = iter->next;
    }
    cout<<"null"<<endl;
    return EXIT_SUCCESS;
}