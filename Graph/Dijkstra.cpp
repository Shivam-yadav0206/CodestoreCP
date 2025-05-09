priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<int> result(V, INT_MAX);

result[S] = 0;
pq.push({0, S});
//NOTE - You can add a visited vector to avoid revisiting a node again and again. It will reduce the time complexity.
unordered_map<int,vector<pair<int,int>>> adj;
for(auto &edge : edges) adj[edge[0]].push_back({edge[1],edge[2]});
while(!pq.empty()) {

    int d  = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for(auto &vec : adj[node]) {

    int adjNode = vec.first;
    int wt = vec.second;

    if(d + wt < result[adjNode]) {

        result[adjNode] = d + wt;
        pq.push({d+wt, adjNode});

    }

    }

}

return result;