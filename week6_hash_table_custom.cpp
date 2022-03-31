#include <iostream>
#include <unordered_map>
using namespace std;

class MyHashMap {
    
public:   
    struct node
    {
        int key = NULL;
        int val = NULL;
        node* next = NULL;
    }; 
    node* nodeArr;
    int hashSize = 10;
        
    MyHashMap() {
        nodeArr = new node[hashSize];
    }
    
    void put(int key, int value) {
        int index = key % hashSize;
        node* head = &nodeArr[index];
        node* temp = new node();
        temp->key = key;
        temp->val = value;
        temp->next = head;
        nodeArr[index] = *temp;
    }
    
    int get(int key) {
        int index = key % hashSize;
        node* ptr = &nodeArr[index];
        while(ptr!=NULL)
        {
            if(ptr->key == key)
                return ptr->val;
            ptr = ptr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % hashSize;
        node* ptr = &nodeArr[index];
        if(ptr->key == key)
        {
            ptr->key = NULL;
            ptr->next = NULL;
            return;
        }
        node* prevPtr = ptr;
        ptr = ptr->next;
        while(ptr!=NULL)
        {
            if(ptr->key == key)
            {
                prevPtr->next = ptr->next;
                return;
            }               
            prevPtr = ptr;
            ptr = ptr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    MyHashMap* obj = new MyHashMap();
    obj->put(1,1);
    cout<<obj->get(1);
    obj->remove(1);
    cout<<obj->get(1);
    obj->put(1,1);
    cout<<obj->get(1);
    //obj->put(key,value);
    //int param_2 = obj->get(key);
    //obj->remove(key);
    return EXIT_SUCCESS;
}