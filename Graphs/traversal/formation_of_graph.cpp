#include<bits/stdc++.h> 
using namespace std  ; 
//formation through vector . 
//space complexity is O(2*e);

int main(){
    int n; 
    vector<int>adj[n+1]; 
    for(int i =0;i<n ;i++){
        int u,v; 
        cin>>u>>v  ; 
        adj[u].push_back(v); 
        adj[v].push_back(v);
    }
    return  0 ; 

}
