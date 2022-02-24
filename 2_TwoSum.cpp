#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }

vector<int> twoSumEff(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap{std::make_pair(nums[0], 0)};
        
        for (size_t i = 1; i < nums.size(); ++i){
            auto it = hashmap.find(target - nums[i]);
            if (it != hashmap.end() && it->second != i){
                return {it->second, i};
            }
            hashmap[nums[i]] = i;
        }
        
        return {};
    }

int main() 
{
  vector<int> nums={1,2,3,4};
  vector<int> res= twoSumEff(nums,6);
  
  cout<<"[";
  
  for(int i=0;i<res.size()-1;i++) cout<<res[i]<<",";
  
  cout<<res.back()<<"]"<<endl;
  return 0; 
}