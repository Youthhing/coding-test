#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string dp[101][101];

string calculateSum(string a, string b){
    int sum = 0;
    string answer = "";

    while (!a.empty()||!b.empty()||sum!=0){
        if(!a.empty()){
            sum += a.back()-'0';
            a.pop_back();
        }
        if(!b.empty()){
            sum += b.back()-'0';
            b.pop_back();
        }

        answer.push_back((sum%10)+'0');
        sum/=10;
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}


string getCombination(int n, int m){
    if(n < m) return "ERROR";
    if(n==m||m==0) return "1";
    if(dp[n][m] != "") return dp[n][m];
    dp[n][m] = calculateSum(getCombination(n-1 , m), getCombination(n-1,m-1));
    return dp[n][m];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    cout<<getCombination(n,m);

    return 0;
}