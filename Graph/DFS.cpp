class Solution {
    public:
      // Function to return a list containing the DFS traversal of the graph.
      void dfs(int start,int vis[],vector<int> adj[],vector<int> &ans){
          vis[start]=1;
          ans.push_back(start);
          for(auto it:adj[start]){
              if(!vis[it])
                  dfs(it,vis,adj,ans);
          }
          return;
      }
      vector<int> dfsOfGraph(int V, vector<int> adj[]) {
          // Code here
          int vis[V]={0};
          vector<int> ans;
          dfs(0,vis,adj,ans);
          return ans;
      }
  };