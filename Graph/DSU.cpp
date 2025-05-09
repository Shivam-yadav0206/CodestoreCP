vector<int> parent;
vector<int> rank;
int find(int x){
    if(x == parent[x]) return x;
    
    return parent[x] = find(parent[x]);
}
void unions(int x, int y){
    int xpar = find(x);
    int ypar = find(y);
    
    if(xpar == ypar) return;
    
    if(rank[xpar] > rank[ypar]){
        parent[ypar] = xpar;
    }else if(rank[xpar] < rank[ypar]){
        parent[xpar] = ypar;
    }else{
        parent[xpar] = ypar;
        rank[ypar]++;
    }
    return;
}

parent.resize(V);
rank.resize(V, 0);

for(int i = 0; i<V; i++) parent[i] = i;