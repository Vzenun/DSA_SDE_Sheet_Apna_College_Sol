#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==target){
                return 0;
            }
            else{
                return -1;
            }
        }
        int flag=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag=i+1;
                break;
            }
        }
        int i=-1;
        int j=n;
        while(i+1<j){
            int m=(i+j)/2;
            int m1=(m+flag)%n;
            if(nums[m1]<=target){
                i=m;
            }
            else{
                j=m;
            }
        }
        if(i+flag!=-1 && nums[(i+flag)%n]==target){
            return (flag+i)%n;
        }
        else{
            return -1;
        }
    }
};