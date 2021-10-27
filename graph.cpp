#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<int>adj[],int startNode,vector<int>&vis){
    queue<int>q;
    vis[startNode]=1;
    q.push(startNode);
    while(!q.empty()){
        int temp=q.front();
        cout<<temp;
        q.pop();
        vector<int>::iterator adjNode;
        for(adjNode = adj[startNode].begin();adjNode!=adj[startNode].end();adjNode++){
            if(!vis[*adjNode]){
                vis[*adjNode]=1;
                q.push(*adjNode);
            }
        }
    }

}

void dfs(vector<int>adj[],int startNode,vector<int>&vis){
    
    vis[startNode]=1;
    cout<<startNode;
    vector<int>::iterator adjNode;
    for(adjNode=adj[startNode].begin();adjNode!=adj[startNode].end();adjNode++){
        if(!vis[*adjNode]){
            vis[*adjNode]=1;
            dfs(adj,*adjNode,vis);
        }
    }
}
void deleteEdge(vector<int>adj[],int u,int v){
    adj[u].erase(find(adj[u].begin(),adj[u].end(),v));
    adj[v].erase(find(adj[v].begin(),adj[v].end(),u));
}

void display(vector<int>adj[],int V){
    cout<<"The adjacency list of the matrix"<<endl;
    for(int i=0;i<V;i++){
        cout<<i;
        for(int x=0;x<adj[i].size();x++){
            cout<<"->"<<adj[i][x];
        }
        cout<<"\n";
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    display(adj,v);
    
    vector<int>vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i])
            bfs(adj,i,vis);
    }
    cout<<"\n\n";
    vector<int>visdfs(v,0);
    for(int i=0;i<v;i++){
        if(!visdfs[i])
            dfs(adj,i,visdfs);
    }
    return 0;

}
