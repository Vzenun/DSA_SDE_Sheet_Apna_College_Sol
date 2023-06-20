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
        if(n==2){
            if(nums[0]==target){
                return 0;
            }
            if(nums[1]==target){
                return 1;
            }
            else{
                return -1;
            }
        }
        int flag=0;
        int i=-1;
        int j=n;
        while(i+1<j){
            int m=(i+j)/2;
            if(m>0 && m<n-1){
                if(nums[m]>nums[m-1] && nums[m]<nums[m+1]){
                    if(nums[m]>nums[0]){
                        i=m;
                    }
                    else{
                        j=m;
                    }
                }
                else if(nums[m]<nums[m-1] && nums[m]<nums[m+1]){
                    flag=m;
                    break;
                }
                else if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                    flag=m+1;
                    break;
                }
            }
            else{
                if(m==0){
                    flag=1;
                    cout<<2<<endl;
                }
                else{
                    flag=0;
                }
                break;
            }
        }
        i=-1;
        j=n;
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