#include<bits/stdc++.h>
using namespace std;

const int mx = 1e3+123;
int dp[mx][mx];
string a, b;
int n, m;
//return length of longest common subsequence
int longest_common_sub_sequence(int i, int j) {
    if (i >= n || j >= m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int res;
    if (a[i] == b[j]) {
        res = longest_common_sub_sequence(i + 1, j + 1) + 1;
    } else {
        res = max(longest_common_sub_sequence(i, j + 1), longest_common_sub_sequence(i + 1, j));
    }
    return dp[i][j] = res;
}

void solve(){
    cin>>n>>m;
    cin>>a>>b;
    memset(dp, -1, sizeof(dp));
    cout<<longest_common_sub_sequence(0, 0)<<endl;
}

int main()
{
    int _ = 1;
    cin>>_;
    for (int tc = 1; tc<=_; tc++)
    {
        //cout<<"Case "<<tc<<": ";
        solve();
    }
}