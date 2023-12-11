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

bool num_recognizer(char c){
    if(c >= '0' && c <= '9'){
        return true;
    }
    else return false;
}


int poland(string input){
    
    vector<int> array;

    for(int i=0;i<(int)input.length();i++){
        if(num_recognizer(input.at(i))){//数字入力
            int digit = (int)input.at(i) - '0';
            array.push_back(digit);
        }
        else{//演算子入力
            int b = array.back();
            array.pop_back();
            int a = array.back();
            array.pop_back();

            switch(input.at(i)){
                case '+':
                    array.push_back(a+b);
                    break;
                
                case '-':
                    array.push_back(a-b);
                    break;

                case '*':
                    array.push_back(a*b);
                    break;
                case '/':
                    array.push_back(a/b);
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
        }
    }

    return array.back();
}
   
int main() {
    string s;
    cin >> s;
   cout << poland(s)<<endl;
    return 0;
}