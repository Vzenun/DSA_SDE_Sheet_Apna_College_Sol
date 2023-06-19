#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer=-100000;
        int sum=0;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            else{
                answer=max(sum,answer);
            }
            if(nums[i]==0){
                flag=1;
            }
        }
        if(flag==1){
            return answer;
        }
        else{
            if(answer==-100000){
                return *max_element(nums.begin(),nums.end());
            }
            return answer;
        }
    }
};