#include <bits/stdc++.h>
// Final version
// Solution for Falling Balls problem
using namespace std;
// Updated comment for second submission
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long D, n;
    if(!(cin>>D>>n)) return 0;
    // compute leaf index of last ball
    long long idx = 1; // root index in heap (1-based)
    long long cur_n = n;
    for(long long depth=1; depth<D; ++depth){
        long long state_before = (cur_n-1)&1LL; // 0 closed, 1 open
        if(state_before==0){
            // go left
            idx = idx*2;
            cur_n = (cur_n+1)/2; // left arrivals count includes this ball
        }else{
            // go right
            idx = idx*2+1;
            cur_n = cur_n/2; // right arrivals count
        }
    }
    cout<<idx<<"\n";
    // compute leaf states
    long long leafCount = 1LL<<(D-1);
    vector<int> leafState(leafCount);
    function<void(long long,long long,long long)> dfs = [&](long long node, long long depth, long long arrivals){
        if(depth==D){
            long long leafIdx = node - (1LL<<(D-1));
            leafState[leafIdx] = arrivals & 1LL;
            return;
        }
        long long leftArr = (arrivals+1)/2;
        long long rightArr = arrivals/2;
        dfs(node*2, depth+1, leftArr);
        dfs(node*2+1, depth+1, rightArr);
    };
    dfs(1,1,n);
    for(size_t i=0;i<leafState.size();++i){
        if(i) cout<<' ';
        cout<<leafState[i];
    }
    cout<<"\n";
    return 0;
}
// End of file comment
// End of program
