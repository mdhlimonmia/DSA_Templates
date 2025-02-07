///   ***   ---   |||    In the name of ALLAH    |||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define endl '\n'

/* LPS = LPS is the Longest Proper Prefix which is also a Suffix. */
void genLPSArray(vi &lps, string &s, int m){
    int i = 1, j = 0, len = 0;
    while(i<m){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

/* Find number of time B occrs as a subsequence of A. */
ll KMPSearch(string &a, ll n, string &b, ll m){
    vi lps(m);
    genLPSArray(lps, b, m);
    ll i = 0, j = 0;
    ll total = 0;
    // vl foundIndex;
    while(i<n){
        if(a[i] == b[j]){
            i++, j++;
        }
        if(j == m){//Found 
            // foundIndex.push_back(i-j+1);
            total++;
            j = lps[j-1];
        }else if(a[i] != b[j]){
            if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    return total;
}

void solve(int tc){
    string a, b; cin>>a>>b;
    ll n = a.size(), m = b.size();
    cout<<"Case "<<tc<<": "<<KMPSearch(a,n,b,m)<<endl;
    /*
        input:
            aaaaaa
            aa
        Output:
            Case 4: 5
    */
}

int main()
{
    int _ = 1;
    cin>>_;
    for (int tc = 1; tc<=_; tc++)
    {
        solve(tc);
    }
}

/*
/// Some problem link
https://www.spoj.com/problems/NHAY/
https://acm.timus.ru/problem.aspx?space=1&num=1423&locale=en
https://lightoj.com/problem/substring-frequency
https://lightoj.com/problem/making-huge-palindromes

*/