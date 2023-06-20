#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int prod=1;
        int flag=0;
        int f1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                prod*=nums[i];
                f1++;
            }
            if(nums[i]==0){
                flag++;
            }
        }
        if(flag>=2){
            for(int i=0;i<nums.size();i++){
                nums[i]=0;
            }
        }
        else if(flag==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    if(f1==0){
                        nums[i]=0;
                    }
                    else{
                        nums[i]=prod;
                    }
                }
                else{
                    nums[i]=0;
                }
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                nums[i]=int(prod/nums[i]);
            }
        }

        return nums;
    }
};