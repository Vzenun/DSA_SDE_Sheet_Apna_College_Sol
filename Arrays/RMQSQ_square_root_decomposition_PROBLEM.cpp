#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int len=(int)sqrtl(n)+1;
    vector<int> decomposed(len,INT_MAX);
    for(int i=0;i<n;i++){
        decomposed[i/len]=min(decomposed[i/len],arr[i]);
    }
    int q;
    cin>>q;
    for(int k=0;k<q;k++){
        int l,r;
        cin>>l>>r;
        int i=l;
        int answer=INT_MAX;
        while(i<=r){
            if(i%len==0 && i+len-1<=r){
                answer=min(answer,decomposed[i/len]);
                i+=len;
            }
            else{
                answer=min(answer,arr[i]);
                i++;
            }
        }
        cout<<answer<<endl;
    }
}