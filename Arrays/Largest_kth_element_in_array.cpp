#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest2(vector<int>& nums, int k,int i1,int j1) {
        if(j1-i1+1==1){
            cout<<-1<<2<<endl;
            cout<<i1<<endl;
            return nums[i1];
        }
        else{
            int p=nums[(i1+j1)/2];
            //cout<<p<<endl;
            int i2=-1+i1;
            int ak=(i1+j1)/2;
            for(int i=i1;i<=j1;i++){
                if(nums[i]<p){
                    i2++;
                    cout<<546<<endl;
                    swap(nums[i2],nums[i]);
                }
                if(nums[i]==p){
                    ak=i;
                }
            }
            i2++;
            cout<<i2<<endl;
            swap(nums[ak],nums[i2]);
            cout<<nums[i2]<<endl;
            if(i2-i1+1==k){
                return p;
            }
            else if(i2-i1+1<k){
                return findKthLargest2(nums,k-i2+i1-1,i2+1,j1);
            }
            else{
                cout<<5<<endl;
                return findKthLargest2(nums,k,i1,i2-1);
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest2(nums,nums.size()-k+1,0,nums.size()-1);
    }
};