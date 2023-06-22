//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



bool mycompare(vector<int> p1,vector<int> p2){
    if(p1[0]<p2[0]){
        return true;
    }
    else if(p1[0]==p2[0]){
        return p1[1]>p2[1];
    }
    else{
        return false;
    }
}
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
        sort(intervals.begin(),intervals.end(),mycompare);
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.size()==0){
                ans.emplace_back(intervals[i]);
            }
            else{
                if(ans[ans.size()-1][0]<=intervals[i][0] && ans[ans.size()-1][1]<=intervals[i][1]){
                    if(intervals[i][0] <=ans[ans.size()-1][1]){
                        ans[ans.size()-1][1]=intervals[i][1];
                    }
                    else{
                        ans.emplace_back(intervals[i]);
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends