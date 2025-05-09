class Solution {
    public:
      bool BFS(vector<vector<int>>& adjList, int u, int par, vector<bool> &vis){
          queue<pair<int,int>> q;
          q.push({u,-1});
          vis[u] = true;
          while(!q.empty()){
              auto top = q.front();
              q.pop();
              for(int node : adjList[top.first]){
                  if(vis[node]){
                     if(node != top.second) return true; 
                  }else q.push({node,top.first}), vis[node] = true;
              }
          }
          return false;
      }
  
      bool isCycle(int V, vector<vector<int>>& edges) {
          vector<vector<int>> adjList(V);
          for(auto& edge : edges){
              int u = edge[0], v = edge[1];
              adjList[u].push_back(v);
              adjList[v].push_back(u);
          }
  
          vector<bool> vis(V, false);
          for(int i = 0; i < V; i++){
              if(!vis[i] && BFS(adjList, i, -1, vis)) return true;
          }
          return false;
      }
  
  };

  





  class Solution {
    public:
      bool DFS(vector<vector<int>>& adjList, int u, int par, vector<bool> &vis){
          vis[u] = true;
          for(int edge : adjList[u]){
              if(!vis[edge]){
                  if(DFS(adjList, edge, u, vis)) return true;
              } else if(edge != par){
                  return true;
              }
          }
          return false;
      }
  
      bool isCycle(int V, vector<vector<int>>& edges) {
          vector<vector<int>> adjList(V);
          for(auto& edge : edges){
              int u = edge[0], v = edge[1];
              adjList[u].push_back(v);
              adjList[v].push_back(u);
          }
  
          vector<bool> vis(V, false);
          for(int i = 0; i < V; i++){
              if(!vis[i] && DFS(adjList, i, -1, vis)) return true;
          }
          return false;
      }
  
  };
  