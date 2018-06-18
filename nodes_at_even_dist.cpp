//nodes at even distance in a graph gfg
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n,s,d;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int> g[n+1];
	    for(int i=0;i<n-1;i++){
	        cin>>s>>d;
	        g[s].push_back(d);
	        g[d].push_back(s);
	    }
	    int count=0;
	    stack<int> s;
	    s.push(1);
	    vector<int>::iterator it;
	    bool visited[n+1]={false};
	    visited[1]=true;
	    int dist[n+1];
	    dist[1]=0;
	    while(!s.empty()){
	        int v=s.top();
	        s.pop();
	        for(it=g[v].begin();it!=g[v].end();it++){
	            if(!visited[*it]){
	                s.push(*it);
    	            visited[*it]=true;
    	            dist[*it]=dist[v]+1;
	            }
	        }
	    }
	    int even_count = 0,odd_count=0;
	    for(int i=1;i<n+1;i++){
	        if(dist[i]%2==0)
	            even_count++;
	    }
	    odd_count=n-even_count;
	    cout<<even_count*(even_count-1)/2+odd_count*(odd_count-1)/2<<endl;
	}
	return 0;
}
