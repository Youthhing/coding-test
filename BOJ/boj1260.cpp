#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> adj[1010];

bool pBfs[1010]={0,};
bool pDfs[1001]={0,};

void bfs(int start){
    pBfs[start]=1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<" ";
        int qsize = adj[cur].size();
        for(int i=0;i<qsize;i++){
            int nx = adj[cur][i];
            if(pBfs[nx]==0){//아직 방문하지 않았다면
                q.push(nx);
                pBfs[nx]=1;
            }
        }
    }
    cout<<"\n";

}

void dfs1(int start){
    pDfs[start]=1;
    int cursize = adj[start].size();
    cout<<start<<" ";
    for(int i=0;i<cursize;i++){
        int nx = adj[start][i];
        if(pDfs[nx]==0){
            
            dfs1(nx);
        }

    }
    
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    int v;cin>>v;

    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }

    dfs1(v);
    cout<<"\n";
    bfs(v);


    return 0;
}