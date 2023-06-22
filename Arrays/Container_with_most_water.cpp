#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        vector<int> lh(n);
        vector<int> rh(n);
        int lheight=0;
        int rheight=0;
        int j=n-1;
        int i=0;
        int answer=0;
        while(i<j){
            if(height[i]<=height[j]){
                if(height[i]>=lheight){
                    lheight=height[i];
                    answer=max(min(lheight,height[j])*(j-i),answer);
                }
                i++;
            }
            else{
                if(height[j]>=rheight){
                    rheight=height[j];
                    answer=max(min(rheight,height[i])*(j-i),answer);
                }
                j--;
            }
        }
        return answer;
    }
};