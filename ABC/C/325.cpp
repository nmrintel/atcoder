#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
const long long INF = 1LL << 60;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;

int main()
{
    int H, W;
    cin >> H;
    cin >> W;

    char input;
    vector<vector<int>> exsist(H*W,vector<int> (3,-1));
    int point = 0;


    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> input;
            if (input == '#')
            {
                exsist.at(point).at(0) =i;
                exsist.at(point).at(1) =j;
                point++;
            }
        }
    }

    int ans=0;

    for(int i=0;i<point;i++){

        if(exsist.at(i).at(2) == -1){
            exsist.at(i).at(2) = 0;
            cout << i<<endl;
            ans++;
        }

        for(int j=i+1;j<point;j++){
            int dis = max(abs(exsist.at(i).at(0)-exsist.at(j).at(0)),
            abs(exsist.at(i).at(1)-exsist.at(j).at(1)));
            if(dis<=1){
                exsist.at(j).at(2) = 0;
                
            }
        }
    }
    cout << ans << endl;
    return 0;
}