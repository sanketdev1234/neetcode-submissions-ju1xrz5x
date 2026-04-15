class Solution {
public:
bool dfs(vector<int>&visited ,vector<vector<int>>&adj , int node , int parent ){
    if(visited[node]==1)return true;
    visited[node]=1;
    bool check=true;
    for(auto it : adj[node]){
      if(visited[it]==0){
        check=check && dfs(visited , adj , it , node);
      }
      else {
        if(it!=parent)return false;
      }
    }
    return check;
}
    bool validTree(int n, vector<vector<int>>& edges) {
      int m=edges.size();
      int connected_component=0;
      vector<int>visited(n,0);
      vector<vector<int>>adj(n);
      for(int i=0;i<m;i++){
       int u=edges[i][0];
       int v=edges[i][1];
       adj[u].push_back(v);
       adj[v].push_back(u);
      }

      for(int i=0;i < n;i++){
        if(visited[i]==0){
            bool cycle=dfs(visited , adj , 0,-1);
            if(!cycle)return false;
            connected_component++;
        }
      }
    if(connected_component > 1)return false;
    return true;
    }
};
