#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int ans;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    ans = 0;

    map<int,int> list;
    for(int i=0;i<N;i++){
        int num, status;
        cin>>num>>status;
        //있는지 찾아
        if(list.find(num)!=list.end()){
            //있으면 마지막 상태랑 달라야해 같으면 누락
            if(list.find(num)->second==status){
                ans++;
            } 
            list[num]=status;
            
        }
        else if(status == 0){
            ans++;
        }
        else{
            list.insert({num,status});
        }
    }
    cout<<ans<<"\n";
    for(auto iter = list.begin();iter!=list.end();iter++){
        if(iter->second==1)ans++;
        // cout<<iter->first<<" "<<iter->second<<"\n";
    }

    cout<<ans;
    return 0;
}