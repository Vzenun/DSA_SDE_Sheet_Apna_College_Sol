#include<bits/stdc++.h>
using namespace std;

struct query{
    public:
    int index;
    int start;
    int end;
};

int block_size;

bool mycompare(query q1,query q2){
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

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> mpt(1000001,0);
    int distinct_elements=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(mpt[arr[i]]==k-1){
            mpt[arr[i]]++;
            distinct_elements++;
        }
        else{
            mpt[arr[i]]++;
        }
    }
    block_size=(int)sqrtl(n)+1;
    int q;
    cin>>q;
    vector<query> queries(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        queries[i].index=i;
        queries[i].start=l-1;
        queries[i].end=r-1;
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
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
}