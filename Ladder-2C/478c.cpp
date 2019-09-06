#include<bits/stdc++.h>

using namespace std;

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define v(d_type) vector<d_type>
#define loop(i, s, n) for(int i = s; i < n; i++)
#define min(x, y) (x) > (y) ? (y) : (x)
#define max(x, y) (x) < (y) ? (y) : (x)
#define print_vec(X) loop(i, 0, X.size()) cout << X[i] << "\n"
#define nl "\n"


int main()
{
    boost;
    ll c[3];
    cin >> c[0] >> c[1] >> c[2];
    sort(c, c + 3);
    ll ans = c[0] + c[1];
    if(2*ans >= c[2])
        ans = (ans + c[2]) / 3;
    cout << ans << nl;
    return 0;
}