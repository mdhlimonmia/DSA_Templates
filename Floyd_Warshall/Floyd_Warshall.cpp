///   ***   ---   |||    In the name of ALLAH    |||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 2000000000;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e3+123;
ll adj[mx][mx];

//Find shortest path in all pair
void floydWarshall(int n){

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(adj[i][k]+adj[k][j]<adj[i][j]){
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }
}

void solve(){
    ll n, m;cin>>n>>m;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            if(i!=j) adj[i][j] = inf;
        }
    }

    for(int i = 1; i<=m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w); // Bidirectional
    }
    floydWarshall(n);

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            
            if(adj[i][j]!=inf) cout<<adj[i][j]<<" ";
            else cout<<"inf ";
        }
        cout<<endl;
    }
}

int main()
{
    optimize();

    int _ = 1;
    cin>>_;
    for (int tc = 1; tc<=_; tc++)
    {
        //cout<<"Case "<<tc<<": ";
        solve();
    }
}
/*
    Input: 
    4 3
    1 2 5
    1 3 9
    2 3 3
    Output:
    0   5   8  inf 
    5   0   3  inf 
    8   3   0  inf 
    inf inf inf 0 
*/

/*
    Some problem list:
    https://cses.fi/problemset/task/1672/
    https://lightoj.com/problem/brush-5
    https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
    https://codeforces.com/contest/25/problem/C

*/
