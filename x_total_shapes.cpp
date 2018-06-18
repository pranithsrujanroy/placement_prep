#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void DFS(char s[51][51],int n,int m,bool visited[][50],int i,int j){
    visited[i][j]=true;
    if(i+1<n&&s[i+1][j]=='X'&&visited[i+1][j]==false)
        DFS(s,n,m,visited,i+1,j);
    if(j+1<m&&s[i][j+1]=='X'&&visited[i][j+1]==false)
        DFS(s,n,m,visited,i,j+1);
    if(i-1>=0&&s[i-1][j]=='X'&&visited[i-1][j]==false)
        DFS(s,n,m,visited,i-1,j);
    if(j-1>=0&&s[i][j-1]=='X'&&visited[i][j-1]==false)
        DFS(s,n,m,visited,i,j-1);
}
void BFS(char s[51][51],int n,int m,bool visited[][50],int i,int j){
    visited[i][j]=true;
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    while(!q.empty()){
        pair<int,int>p = q.front();
        i = p.first;
        j = p.second;
        q.pop();
        if(i+1<n&&s[i+1][j]=='X'&&visited[i+1][j]==false){
            visited[i+1][j]=true;
            q.push(make_pair(i+1,j));
        }
        if(j+1<m&&s[i][j+1]=='X'&&visited[i][j+1]==false){
            visited[i][j+1]=true;
            q.push(make_pair(i,j+1));
        }
        if(i-1>=0&&s[i-1][j]=='X'&&visited[i-1][j]==false){
          visited[i-1][j]=true;
          q.push(make_pair(i-1,j));
        }
        if(j-1>=0&&s[i][j-1]=='X'&&visited[i][j-1]==false){
            visited[i][j-1]=true;
            q.push(make_pair(i,j-1));
        }
    }
}
int x_total_shapes(char s[51][51],int n,int m){
    bool visited[n][50]={false};
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='X'&&visited[i][j]==false){
                count++;
                DFS(s,n,m,visited,i,j);
                //BFS(s,n,m,visited,i,j);
            }
        }
    }
    return count;
}
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
	  cin>>n>>m;
      char s[51][51];
      for(int i=0;i<n;i++){
        cin.ignore();
        for(int j=0;j<m;j++){
          cin>>s[i][j];
        }
      }
	    cout<<x_total_shapes(s,n,m)<<endl;
	}
	return 0;
}
