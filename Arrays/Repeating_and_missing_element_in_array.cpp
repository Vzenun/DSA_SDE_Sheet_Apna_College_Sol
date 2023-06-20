#include <bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int num=0;
	int sum=0;
	for(int i=0;i<n;i++){
		num=num^arr[i];
		num=num^(i+1);
		sum+=arr[i];
	}
	int k=1;
	while((int)(k&num)!=k){
		k=k<<1;
	}
	int ans=0;
	int ans2=0;
	for(int i=0;i<n;i++){
		if((int)(k&arr[i])!=k){
			ans=ans^arr[i];
		}
		else{
			ans2=ans2^arr[i];
		}
		if((int)(k&(i+1))!=k){
			ans=ans^(i+1);
		}
		else{
			ans2=ans2^(i+1);
		}
	}
	if(sum>(n*(n+1))/2){
		return make_pair(min(ans,ans2),max(ans,ans2));
	}
	else{
		return make_pair(max(ans,ans2),min(ans,ans2));
	}
}
