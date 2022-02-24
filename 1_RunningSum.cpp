#include <bits/stdc++.h>
using namespace std;
vector<int> runningSum(vector<int>& nums) 
{
    vector<int> res(nums.size());
    if(nums.size()==0) return res;
    res[0]=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        res[i]=res[i-1]+ nums[i];
    }
    return res;
}
int main() 
{
  vector<int> nums={1,2,3,4};
  vector<int> res= runningSum(nums);
  
    cout<< "size of the vector is "<<nums.size()<<endl;
    float li = 10;
    auto* ptr = &li;
    auto aut = 7;
    aut = 7.2;
    cout<<aut<<endl;
    cout<<sizeof(ptr)<<endl;
    li=11;
    cout<<"ptr="<<ptr<<"*ptr="<<*ptr<<endl;



  cout<<"[";
  
  for(int i=0;i<res.size()-1;i++) cout<<res[i]<<",";
  
  cout<<res.back()<<"]"<<endl;
  return 0; 
}