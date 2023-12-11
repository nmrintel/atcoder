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
const ll INF = 1LL << 60;
template<class type> void chmin(type& a,type b){
    if(a > b){
        a = b;
    }
}

int main(void){
    int N;
    cin >> N;
    vector<ll> h(N);
    for(int i=0;i<N;i++){
        cin >> h.at(i);
    }

    vector<ll> dp(N,INF);
    //もらうDPでとく
    dp.at(0) = 0;
    for(int i=1;i<N;i++){
        chmin(dp[i],dp[i-1]+abs(h.at(i)-h.at(i-1)));
        if(i>1){
            chmin(dp[i],dp[i-2]+abs(h.at(i)-h.at(i-2)));
        }
    }

    cout << dp.at(N-1)<<endl;
    return 0;
}