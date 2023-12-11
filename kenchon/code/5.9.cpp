#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL<<60;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;

template<class T> void chmin(T& a,T b){
    if(a>b){
        a=b;
    }
}
   
int main() {
    int N;
    cin >> N;
    vector<vector<ll>> c(N+1,vector<ll>(N+1));
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            cin >>c[i][j];
        }
    }

    vector<ll> dp(N+1,INF);
    dp[0] = 0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<i;j++){
            chmin(dp[i],dp[j]+c[j][i])
        }
    }
}