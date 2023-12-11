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

template <class type>
void chmax(type &a, type b)
{
    if (a < b)
    {
        a = b;
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<ll>> cost(3, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cost.at(i).at(j) = (i * j) % i;
        }
    }

    vector<vector<ll>> dp(3, vector<ll>(0, N));
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                chmax(dp.at(i).at(1), dp.at(i - 1).at(1));
                chmax(dp.at(i).at(1), dp.at(i - 1).at(2));
            }
            if (j == 1)
            {
                chmax(dp.at(i).at(1), dp.at(i - 1).at(0));
                chmax(dp.at(i).at(1), dp.at(i - 1).at(2));
            }
            if (j == 2)
            {
                chmax(dp.at(i).at(1), dp.at(i - 1).at(0));
                chmax(dp.at(i).at(1), dp.at(i - 1).at(1));
            }
        }
    }

    cout << max(dp.at(N).at(0),dp.at(N).at(1),dp.at(N).at(2)) << endl;
}