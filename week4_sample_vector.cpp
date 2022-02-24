#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> age = {1,2,3};
    cout<<"The number of elements in the vector is: "<<age.size()<<endl;
    cout<<"The capacity of the vector is: "<<age.capacity()<<endl;
    age.push_back(10);
    cout<<"The number of elements in the vector is: "<<age.size()<<endl;
    cout<<"The capacity of the vector is: "<<age.capacity()<<endl;
    age.push_back(20);
    cout<<"The number of elements in the vector is: "<<age.size()<<endl;
    cout<<"The capacity of the vector is: "<<age.capacity()<<endl;
    age.push_back(30);
    cout<<"The number of elements in the vector is: "<<age.size()<<endl;
    cout<<"The capacity of the vector is: "<<age.capacity()<<endl;
    age.push_back(40);
    cout<<"The number of elements in the vector is: "<<age.size()<<endl;
    cout<<"The capacity of the vector is: "<<age.capacity()<<endl;
    age.pop_back();age.pop_back();age.pop_back();age.pop_back();age.pop_back();age.pop_back();
    cout<<"The number of elements in the vector is: "<<age.size()<<endl;
    cout<<"The capacity of the vector is: "<<age.capacity()<<endl;
    age.push_back(40);
    cout<<"The number of elements in the vector is: "<<age.size()<<endl;
    cout<<"The capacity of the vector is: "<<age.capacity()<<endl;
    return EXIT_SUCCESS;
}