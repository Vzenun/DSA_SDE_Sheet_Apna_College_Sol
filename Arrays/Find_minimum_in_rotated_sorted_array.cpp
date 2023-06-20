#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return min(nums[0],nums[1]);
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
        return nums[flag];
    }
};