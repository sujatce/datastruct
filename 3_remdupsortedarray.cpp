#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int forward = 1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i-1]==nums[i])
        {
            //Just skip this element
            //Do not move the forward index
        }
        else
        {
            nums[forward] = nums[i];
            forward++;
        }
     }
        return forward;
    }

int main() 
{
  vector<int> nums={1,1,1,1,1,1,1};
 
    int k = removeDuplicates(nums);

  cout<<"After removing duplicates Array - "<<k<<" Elements [";
  
  for(int i=0;i<k;i++) cout<<nums[i]<<",";
  
  cout<<"]"<<endl;
  return 0; 
}