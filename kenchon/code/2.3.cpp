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

double calc_dist(double x1,double x2,double y1,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
   
int main() {
    int N;
    cin >> N;
    vector<double> x(N),y(N);
    for(int i=0;i<N;i++){
        cin >> x.at(i) >> y.at(i);
    }

    ll max= 0;
    ll cash = 0;

    vector<vector<int>> graph(N,vector<int>(N,0));

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            cash = graph.at(i).at(j) = calc_dist(x.at(i),x.at(j),y.at(i),y.at(j));
            if(cash > max){
                max = cash;
            }
        }
    }

    cout << max << endl;

}