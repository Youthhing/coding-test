#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int red[1010],blue[1010],green[1010];//i번째집을 해당색으로 칠하는 비용

int house[1010][3];//0 red, 1green,2blue

int dp(int n){
    if(n==1){
        int ans = min(red[1],green[1]);
        return min(ans,blue[1]);
    }


    for(int i=2;i<=n;i++){
        house[i][0]=min(house[i-1][1],house[i-1][2])+red[i];
        house[i][1]=min(house[i-1][0],house[i-1][2])+green[i];
        house[i][2]=min(house[i-1][1],house[i-1][0])+blue[i];
    }

    int result = min(house[n][0],house[n][1]);
    return min(result,house[n][2]);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;

    for(int i=1;i<=n;i++){
        cin>>red[i]>>blue[i]>>green[i];
    }


    house[1][0]=red[1];
    house[1][1]=green[1];
    house[1][2]=blue[1];

    cout<<dp(n);
    return 0;
}