#include <iostream>
#include <vector>
using namespace std;

int main() {

    // 入力
    int N; 
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // DP テーブル
    int W = 10000;
    vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));
    dp[0][0] = true;

    // ループ
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j <= W; ++j) {
    //         if (!dp[i][j]) continue;
    //         dp[i+1][j] = true;
    //         if (j+a[i] <= W) dp[i+1][j+a[i]] = true;
    //     }
    // }
    for(int i=1;i<=N;i++){
        for(int j=0;j<=W;++j){
            if(dp.at(i-1).at(j)||(a.at(i-1) <= j && dp.at(i-1).at(j-a.at(i-1)))){
                dp.at(i).at(j) = true;
            }
        }
    }

    // 答え
    int res = 0;
    for (int j = 0; j <= W; ++j) {
        if (dp[N][j]) ++res;
    }
    cout << res << endl;
}