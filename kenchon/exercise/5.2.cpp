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
  // メルセンヌ・ツイスター法による擬似乱数生成器を、
  // ハードウェア乱数をシードにして初期化
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  vector<vector<bool>> dp(W, vector<bool>(N, false));

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::uniform_int_distribution<int> dist1(0, 10);
  // int random_num = dist(engine);

  for (size_t i = 0; i < N; ++i)
  {
    a.at(i) = dist1(engine);
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (j > a.at(i))
      {
        dp.at(i).at(j) = dp.at(i - 1).at(j) + dp.at(i - 1).at(j - a.at(i));
      }
      else
      {
        dp.at(i).at(j) = dp.at(i - 1).at(j);;
      }
    }
  }
}