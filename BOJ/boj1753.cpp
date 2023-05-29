#include<bits/stdc++.h>
#define MAX_V 20002
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
//다익스트라 기본

vector<pii> edge[20002];//시작점, <가중치,끝점>
int dist[20002];


void sp(int s){
    dist[s]=0;
    bool visited[MAX_V]={0,};
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,s});//정점이 작은순..은 말이 안되잖아
    
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur]==1)continue;
        visited[cur]=1;
        int vsize = edge[cur].size();
        for(int i=0;i<vsize;i++){
            int nx = edge[cur][i].second;
            int cost = edge[cur][i].first;
            if(dist[nx]>dist[cur]+cost){
                dist[nx]=dist[cur]+cost;
                pq.push({dist[nx],nx});
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V,E;cin>>V>>E;
    int K;cin>>K;//시작정점
    for(int i=0;i<E;i++){
        int u,v,w;cin>>u>>v>>w;
        edge[u].push_back({w,v});
    }
    fill(dist,dist+MAX_V,INT_MAX);

    sp(K);
    for(int i=1;i<=V;i++){
        if(dist[i]==INT_MAX)cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
    return 0;
}