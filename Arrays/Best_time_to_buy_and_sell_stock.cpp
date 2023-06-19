#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer=0;
        int sum=0;
        for(int i=0;i<prices.size()-1;i++){
            sum+=prices[i+1]-prices[i];
            if(sum<0){
                sum=0;
            }
            else{
                answer=max(sum,answer);
            }
        }
        return answer;
    }
};