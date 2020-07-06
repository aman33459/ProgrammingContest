class Solution {
public:
    int ans=0;
    int color[123456]={0};
    int visited[123456]={0};
    vector <int > g[123456];
    void dfs(int v){
        visited[v] =1;
        color[v]=1;
        for(auto u : g[v]){
            if(color[u] == 1) ans++;
            if(visited[u]) continue;
            dfs(u);
        }
        color[v]=2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i : prerequisites){
            g[i[0]].push_back(i[1]);
           // g[i[1]].push_back(i[0]);
        }
        for(int i = 0 ; i < numCourses ; i++){
            if(visited[i] == 0) dfs(i);
        }
        if(ans) return false;
        else return true;
    }
    
};
