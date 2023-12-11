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

int calc(int time,int N,vector<ll>& w,vector<ll>& x){//time開始時刻
    int ans = 0;
    for(int i=0;i<N;i++){
        if(9 <= (time+x.at(i))%24 && 18 >= (time+x.at(i))%24&& 
        9 <= (time+x.at(i))%24+1 && 18 >=1+ (time+x.at(i))%24){
            ans +=w.at(i);
        }
    }
    return ans;
}
   
int main() {
    int N;
    cin >> N;
    vector<ll> w(N);
    vector<ll> x(N);

    for(int i=0;i<N;i++){
        cin >>w.at(i);
        cin >>x.at(i);
    }

    int max = 0;

    for(int i=0;i<24;i++){
        int num = calc(i,N,w,x);
       // cout << num<<endl;
        if(max < num){
            max = num;
        }
    }

    cout << max <<endl;

}