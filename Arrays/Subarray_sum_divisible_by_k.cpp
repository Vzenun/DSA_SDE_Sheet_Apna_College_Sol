//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
int k1;
bool mycompare(pair<int,int> a,pair<int,int> b){
    if((a.first%k1+k1)%k1<(b.first%k1+k1)%k1){
        return true;
    }
    else if((a.first%k1+k1)%k1==(b.first%k1+k1)%k1){
        return a.second<b.second;
    }
    else if((a.first%k1+k1)%k1>(b.first%k1+k1)%k1){
        return false;
    }
}
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            if(i!=0){
                arr[i]+=arr[i-1];
                a.emplace_back(arr[i],i);
            }
        }
        a.emplace_back(0,-1);
        a.emplace_back(arr[0],0);
        k1=k;
        sort(a.begin(),a.end(),mycompare);
        int modvalue=-1;
        int preind=-2;
        int answer=0;
        for(int i=0;i<=n;i++){
            if((a[i].first%k1+k1)%k1==modvalue){
                if((a[i].first%k1+k1)%k1==0){
                    answer=max(a[i].second+1,answer);
                }
                answer=max(a[i].second-preind,answer);
            }
            else{
                if((a[i].first%k1+k1)%k1==0){
                    answer=max(a[i].second+1,answer);
                    preind=a[i].second;
                    modvalue=(a[i].first%k1+k1)%k1;
                }
                else{
                    preind=a[i].second;
                    modvalue=(a[i].first%k1+k1)%k1;
                }
            }
        }
        return answer;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends