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

template <class type> void chmin(type& a,type b){
    if(a > b){
        a = b;
    }
}
   
int main() {
    int N;
    ll W;
    cin >> N;
    vector<ll> values(N);
    vector<ll> weight(N);

    for(int i=0;i<N;i++){
        cin >>values.at(i);
    }
    cout << endl;

    for(const auto& j:values){
        cout << values.at(j) <<endl;
       // cout << values.at(j)<<endl;
    }
    return 0;

}