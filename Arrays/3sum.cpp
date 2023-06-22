#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        sort(nums.begin(),nums.end());
        int prev=-1000000;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]!=prev){
                prev=nums[i];
                int i1=i+1;
                int j1=nums.size()-1;
                while(i1<j1){
                    if(nums[i1]+nums[j1]==-nums[i]){
                        a.emplace_back(nums[i]);
                        a.emplace_back(nums[i1]);
                        a.emplace_back(nums[j1]);
                        ans.emplace_back(a);
                        a.clear();
                        int a1=nums[i1];
                        int a2=nums[j1];
                        while(i1<j1 && a1==nums[i1] && a2==nums[j1]){
                            i1++;
                            j1--;
                        }
                    }
                    else if(nums[i1]+nums[j1]>-nums[i]){
                        j1--;
                    }
                    else{
                        i1++;
                    }
                }
            }
        }
        return ans;
    }
};