class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int ,int> , int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                  q.push({{i,j} , 0});
                  visited[i][j]=1;
                }
            }
        }
        vector<pair<int , int>>arr={{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size() > 0){
            pair<int , int>node=q.front().first;
            int level=q.front().second;
            grid[node.first][node.second]=level;
            q.pop();
            for(auto it:arr){
               int newnodei=node.first + it.first;
               int newnodej=node.second + it.second;
               if(newnodei < 0 || newnodei >= n || newnodej < 0 || newnodej >= m)continue;
               if(visited[newnodei][newnodej]==0 && grid[newnodei][newnodej]!=-1){
                q.push({{newnodei , newnodej} , level+1});
                visited[newnodei][newnodej]=1;
               }
            }
        }
    }
};
