class Solution {
public:
    vector < int > g[20005];
    int visited[2005];
    int color[20005];
    int ans = 0;
    void dfs(int u,int lvl){
            color[u]=lvl;
            visited[u]=1;
            for(int v : g[u]){
                if(color[v] == color[u]) ans++;
                if(visited[v]) continue;
                dfs(v,lvl^1);
            }
        }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      for(auto i : dislikes){
          g[i[0]].push_back(i[1]);
          g[i[1]].push_back(i[0]);
      }
        
        for(int i = 0 ; i <= N ; i++){
            color[i]=-1;
            visited[i]=0;
        } 
        for(int i = 1 ; i <=N;i++){
            if(!visited[i]) dfs(i,0);
        }
        if(ans) return false;
        else return true;
    }
};
