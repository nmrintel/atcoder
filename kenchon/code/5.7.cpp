#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;

template<class type> void chmax(type& a,type b){
    if(a<b){
        a=b;
    }
}
   
int main() {
    int N;
    ll W;
    vector<ll> value(N);
    vector<ll> weight(N);

    cin >>N>>W;

    for(int i=0;i<N;++i){
        cin >> weight.at(i) >>value.at(i) ;
    }

    vector<vector<ll>> dp(N+1,vector<ll>(W+1,0));

    for(int i=0;i<N;i++){
        for(int w=0;w<=W;w++){
            if(w-weight.at(i)>= 0){
                chmax(dp[i+1][w],dp[i][w-weight[i]]+value[i]);
            }
            chmax(dp[i+1][w],dp[i][w]);
        }
    }

}