#include <bits/stdc++.h> 
using namespace std;
int findPairSum(vector<int> arr, int target)
{
    //Write your code here
    int flag=0;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            flag=i+1;
            break;
        }
    }
    int i=0;
    int j=arr.size()-1;
    i=(i+flag)%arr.size();
    j=(j+flag)%arr.size();
    while(i!=j){
        if(arr[i]+arr[j]==target){
            return 1;
        }
        else if(arr[i]+arr[j]>target){
            j=(arr.size()+j-1)%arr.size();
        }
        else{
            i=(i+1)%arr.size();
        }
    }
    return 0;
}