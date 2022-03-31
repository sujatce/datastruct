#include <iostream>
#include <unordered_map>
using namespace std;

struct node
{
    int val;
    node* next;
};

int size(node *head)
{
    int size = 0;
    while(head!= NULL)
    {
        size++;
        head = head->next;
    }
    return size;
}

node * insert(node * head, int val)
{
    node * newHead;
    newHead = new node();
    newHead->val = val;
    if(head != NULL)
        head->next = head;
    return newHead;
}

void concat(node* head1, node* head2)
{
    if(head1==NULL)
    {
        head1 = head2;
        return;
    }
    if(head2 == NULL)
    {
        return;
    }
    while(head1->next !=NULL)
    {
        head1 = head1->next;
    }
    head1->next = head2;
}

void remove(node* head, int val)
{
    if(head == NULL)
        return;
    while(head->next != NULL)
    {
        if(head->next->val == val)
        {
            head->next = head->next;
        }
        else
        {
            head = head->next;
        }
    }
}

node* doThis(node* head)
{
    if(head == nullptr)
    return nullptr;

    node* newhead = new node();
    newhead->val = head->val;

    node* current = head->next;
    while(current != nullptr)
    {
        node* n = new node();
        n->val = current->val;
        n->next = newhead;
        newhead = n;
        current = current->next;
    }
    return newhead;
}

void delMiddleNode(node* node){
    node->val = node->next->val;
    node->next = node->next->next;
}

void removeDups(node* head)
{
    if(head == nullptr)
        return;

    if(head->next == nullptr)
        return;
    
    node* current = head;
    unordered_map<int, bool> hm;
    hm[current->val] = true;
    while(current->next != nullptr)
    {
        if(hm[current->next->val])
        {
            //remove duplicate
            current->next = current->next->next;
        }
        else{
            hm[current->next->val] = true;
            current = current->next;
        }
    }
}

int main(){
    node *n1 = new node();
    n1->val = 10;
    n1->next = nullptr;

    node *n2 = new node();
    n2->val = 20;
    n2->next = nullptr;

    n1->next = n2;

    node *n3 = new node();
    n3->val = 30;
    n3->next = nullptr;

    n2->next = n3;

    cout << "1st node is: " <<n1->val <<endl;
    cout << "2nd node is: " <<n2->val <<endl;
    cout << "2nd node is: " <<n1->next->val <<endl;

    /*
    //n1=insert(n1,5);
    remove(n1,20);
    cout<<size(n1)<<endl;
    node *n5 = NULL;

    node *n4 = new node();
    n4->val = 40;
    n4->next = nullptr;

    //concat(n5,n1);
    */
   delMiddleNode(n2);
   //removeDups(n1);
    node *iter = n1;



    while (iter !=nullptr)
    {
        cout<< iter->val << "->";
        iter = iter->next;
    }
    cout<<"null"<<endl;

node *iter1 = n1;



    while (iter1 !=nullptr)
    {
        cout<< iter1->val << "->";
        iter1 = iter1->next;
    }
    cout<<"null"<<endl;

    double arr[10];

    cout<<&arr<<endl;
    cout<<&arr[0]<<endl;
    cout<<&arr[1]<<endl;
    cout<<sizeof( double );

    return EXIT_SUCCESS;
}