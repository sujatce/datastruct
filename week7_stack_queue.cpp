#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    stack<string> operations;
    operations.push("WRITE");
    operations.push("COPY");
    operations.push("PASTE");

    while(!operations.empty())
    {
        cout<<"Undo "<<operations.top() <<endl;
        operations.pop();
    }

    queue<string> cars;
    cars.push("Red Car");
    cars.push("Blue Car");
    cars.push("Green Car");
    while(!cars.empty())
    {
        cout<< "Serving " << cars.front() <<endl;
        cars.pop();
    }

    return EXIT_SUCCESS;
}