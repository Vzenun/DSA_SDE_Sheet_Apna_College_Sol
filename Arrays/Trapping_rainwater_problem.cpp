#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int left[height.size()];
        int right[height.size()];
        int a=INT_MIN;
        for(int i=0;i<height.size();i++){
            if(i==0){
                left[i]=height[i];
                a=max(a,height[i]);
            }
            else{
                a=max(a,height[i]);
                left[i]=a;
            }
        }
        a=INT_MIN;
        for(int i=height.size()-1;i>=0;i--){
            if(i==height.size()-1){
                right[i]=height[i];
                a=max(a,height[i]);
            }
            else{
                a=max(a,height[i]);
                right[i]=a;
            }
        }
        int sum=0;
        for(int i=0;i<height.size();i++){
            if(i==0 || i==height.size()-1){
                sum+=0;
            }
            else{
                if(min(left[i],right[i])-height[i]>0){
                    sum+=min(left[i],right[i])-height[i];
                }
            }
        }
        return sum;
    }
};