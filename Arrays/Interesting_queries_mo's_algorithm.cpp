//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int block_size;

    struct query{
        public:
        int index;
        int start;
        int end;
    };
class Solution {
public:
static bool mycompare(query q1,query q2){
        if(q1.start/block_size<q2.start/block_size){
            return true;
        }
        else if(q1.start/block_size==q2.start/block_size){
            return q1.end/block_size>q2.end/block_size;
        }
        else{
            return false;
        }
}
	vector<int>solveQueries(vector<int>nums, vector<vector<int>>Queries, int k){
	    // Code here
        vector<int> arr=nums;
        int n=nums.size();
        int q=Queries.size();
        vector<int> mpt(1001,0);
        int distinct_elements=0;
        for(int i=0;i<n;i++){
            if(mpt[nums[i]]==k-1){
                mpt[nums[i]]++;
                distinct_elements++;
            }
            else{
                mpt[nums[i]]++;
            }
        }
        block_size=(int)sqrt(n)+1;
        vector<query> queries(q);
        for(int i=0;i<q;i++){
            queries[i].index=i;
            queries[i].start=Queries[i][0]-1;
            queries[i].end=Queries[i][1]-1;
        }
        sort(queries.begin(),queries.end(),mycompare);
        int curr_l=0;
        int curr_r=n;
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int l,r;
            l=queries[i].start;
            r=queries[i].end;
            while(curr_l<l){
                if(mpt[arr[curr_l]]==k){
                    distinct_elements--;
                    mpt[arr[curr_l]]--;
                }
                else{
                    mpt[arr[curr_l]]--;
                }
                curr_l++;
            }
            while(curr_l>l){
                curr_l--;
                if(mpt[arr[curr_l]]==k-1){
                    distinct_elements++;
                    mpt[arr[curr_l]]++;
                }
                else{
                    mpt[arr[curr_l]]++;
                }
            }
            while(curr_r<r){
                curr_r++;
                if(mpt[arr[curr_r]]==k-1){
                    distinct_elements++;
                    mpt[arr[curr_r]]++;
                }
                else{
                    mpt[arr[curr_r]]++;
                }
            }
            while(curr_r>r){
                if(mpt[arr[curr_r]]==k){
                    distinct_elements--;
                    mpt[arr[curr_r]]--;
                }
                else{
                    mpt[arr[curr_r]]--;
                }
                curr_r--;
            }
            ans[queries[i].index]=distinct_elements;
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, q, k;
		cin >> n >> q >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		vector<vector<int>>Queries;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Queries.push_back({l,r});
		}
		Solution obj;
		vector<int>ans = obj.solveQueries(nums, Queries, k);
		for(auto i: ans)cout << i << "\n";
	}
	return 0;
}
// } Driver Code Ends