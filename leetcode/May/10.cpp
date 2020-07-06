class Solution {
public:
    int visited[1005][1005]={{0}};
    vector<vector<int>> dfs(vector<vector<int>>& image , int sr , int sc , int color , int prev ){
        
        int n = image.size();
        int m = image[0].size();
        if(sr >= n || sr < 0 || sc >= m || sc< 0) return image;
    ///   cout << sr << " " << sc << "**\n";
        if(image[sr][sc] !=prev || visited[sr][sc] == 1) return image;
        visited[sr][sc]=1;
        image[sr][sc] = color;
        image = dfs(image, sr+1, sc, color , prev);
        image = dfs(image, sr, sc+1, color , prev);
        image  = dfs(image, sr-1, sc, color , prev);
        image = dfs(image, sr, sc-1, color , prev);
        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        return dfs(image,sr,sc,newColor,image[sr][sc]);
    }
};
