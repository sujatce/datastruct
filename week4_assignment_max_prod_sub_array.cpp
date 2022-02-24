#include <iostream>
#include <vector>

using namespace std;

int maxProdSubarray(int nums[], int n)
{
    int max = nums[0];

    //Base case
    if(n==1)
        return max;

    // Loop through all elements of the array
    for(int i = 0; i < n; i++)
    {
        int prod = nums[i];
        //Loop through the current subarray
        for(int j=i+1; j<n; j++)
        {
            if(max < prod)
                max = prod;
            // WRITE CODE HERE...
            // ... to update max

            prod = prod * nums[j];
            //WRITE CODE HERE...
            // ... to update prod
        }
        if(max < prod)
            max = prod;
        // WRITE CODE HERE ...
        // ... to update max
    }
    return max;
}

int main(){
    
    int nums[] = {-3, 10, 2, 10, -1, -6, 6, 6, 0, 6};
    cout<<*(nums+2)<<endl;
    cout<< maxProdSubarray(nums,10) << endl;

}