#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return;
        }
        int flag=-1;
        int num;
        for(int i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                flag=i;
                num=nums[i-1];
                break;
            }
        }
        if(flag==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int answer=nums[flag];
        for(int i=n-1;i>=flag;i--){
            if(nums[i]>num){
                answer=nums[i];
                nums[i]=num;
                break;
            }
        }
        nums[flag-1]=answer;
        reverse(nums.begin()+flag,nums.end());
    }
};