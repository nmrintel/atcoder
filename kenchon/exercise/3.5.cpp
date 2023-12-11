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
   
int main() {
    int N;
    vector<int> data;
    rep(i,N){
        cin >> data.at(i);
    }

    int cnt=0;
    bool check;

    while(check){
        check = true;
        rep(i,N){
            if(data.at(i)%2 == 0){
                data.at(i) /= 2;
            }
            else{
                check = false;
            }
        }
        cnt++;
    }
    cout << check<< endl;
    
}