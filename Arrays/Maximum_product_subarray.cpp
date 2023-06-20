#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
    int answer=-11;
    int fwd=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            fwd=1;
            answer=max(answer,0);
        }
        else{
            fwd*=nums[i];
            answer=max(answer,fwd);
        }
    }
    int bwd=1;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]==0){
            bwd=1;
            answer=max(answer,0);
        }
        else{
            bwd*=nums[i];
            answer=max(answer,bwd);
        }
    }
    return answer;
}