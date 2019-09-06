#include<bits/stdc++.h>

using namespace std;

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define v(d_type) vector<d_type>
#define loop(i, s, n) for(int i = s; i < n; i++)
#define print_vec(X) loop(i, 0, X.size()) cout << X[i] << "\n"
#define nl "\n"
#define fat 1000000007

int main()
{
    boost;

    int n, k, d;
    cin >> n >> k >> d;
    int dp[n + 1][d + 1];
    ll count = 0;
    loop(i, 0, d + 1)
        dp[0][i] = 1;

    loop(i, 1, n + 1)
    {
        loop(j, 0, d + 1)
        {
            dp[i][j] = 0;
            if(j == 0 || j > i) continue;
            else
            {
                loop(p, 1, min(i + 1, k + 1))
                {
                    if(p >= d)
                        dp[i][j] = (dp[i][j]%fat + dp[i - p][1]%fat)%fat;
                    else
                        dp[i][j] = (dp[i][j]%fat + dp[i - p][j]%fat)%fat;
                }
            }
        }
    }

    // loop(i, 0, n + 1)
    // {
    //     loop(j, 0, d + 1)
    //         cout << dp[i][j] << " ";
    //     cout << nl;
    // }
    // cout << nl; 
    cout << dp[n][d] << nl;
    return 0;
}