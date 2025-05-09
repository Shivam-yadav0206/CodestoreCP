class Solution {
    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          // code here
          vector<int> in(V,0);
          for(auto edge : edges) in[edge[1]]++;
          unordered_map<int,vector<int>> adjList;
          for(auto edge : edges){
              adjList[edge[0]].push_back(edge[1]);
          }
          queue<int> q;
          for(int i = 0;i<V;i++) if(in[i] == 0) q.push(i);
          vector<int> ans;
          while(!q.empty()){
              int top = q.front();
              q.pop();
              ans.push_back(top);
              for(int node : adjList[top]){
                  in[node]--;
                  if(in[node] == 0) q.push(node);
              }
          }
          return ans;
      }
      void DFS(unordered_map<int,vector<int>> &adjList, vector<bool> &vis,  stack<int> &st,int u){
          vis[u] = true;
          
          for(int node: adjList[u]){
              if(!vis[node]){
                  vis[node] = true;
                  DFS(adjList,vis,st,node);
              }
          }
          st.push(u);
      }
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          // code here
          unordered_map<int,vector<int>> adjList;
          for(auto edge : edges){
              adjList[edge[0]].push_back(edge[1]);
          }
          vector<bool> vis(V,false);
          stack<int> st;
          for(int i = 0;i<V;i++){
              if(!vis[i]) DFS(adjList,vis,st,i);
          }
          vector<int> ans;
          while(!st.empty()) ans.push_back(st.top()), st.pop();
          return ans;
      }
  };