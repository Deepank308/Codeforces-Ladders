#include<bits/stdc++.h>

using namespace std;

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define v(d_type) vector<d_type>
#define p(d_type1, d_type2) pair<d_type1, d_type2>
#define F first
#define S second
#define loop(i, s, n) for(int i = s; i < n; i++)
#define print_vec(X) loop(i, 0, X.size()) cout << X[i] << "\n"
#define nl "\n"
#define fat 1000000007


int main()
{
    boost;
    int n, m;
    cin >> n >> m;
    string s;
    
    v(v(int)) distinct(m, v(int)(26, 0));
    v(ll) count(m, 0);

    loop(i, 0, n)
    {
        cin >> s;
        loop(j, 0, m)
        {
            if(distinct[j][s[j] - 'A']) continue;

            distinct[j][s[j] - 'A'] = 1;
            count[j]++;
        }
    }

    ll ans = 1;
    loop(i, 0, m)
        ans = (ans*count[i])%fat;

    cout << ans << nl;

    return 0;
}
