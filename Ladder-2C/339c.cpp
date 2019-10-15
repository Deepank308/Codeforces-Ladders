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

int dfs_state(v(int) &final_w, v(int) &weights, int m, int balance, int prev, int num)
{
    if(num > m)
    {
        cout << "YES\n";
        return 1;
    }

    if(abs(balance) > 9)
    {
        return 0;
    }

    int mult = 1, flag = 0;
    loop(i, 0, weights.size())
    {
        if(weights[i] == prev) continue;

        if(balance <= 0) mult = 1;
        else mult = -1;

        if(abs(balance) < weights[i])
        {
            int balance_new = mult*(weights[i] - abs(balance));
            int prev_new = weights[i];

            flag = dfs_state(final_w, weights, m, balance_new, prev_new, num + 1);
            prev = flag ? prev_new:prev;
        }

        if(flag) break;
    }

    if(flag)
    {
        // cout << prev << " ";
        final_w.push_back(prev);
        return 1;
    }
    return 0;
}


int main()
{
    boost;
    string s;
    cin >> s;

    int m;
    cin >> m;

    v(int) weights;
    loop(i, 0, s.size()) if(s[i] == '1') weights.push_back(i + 1);

    if((weights.size() == 1 && m > 1) || weights.size() == 0)
    {
        cout << "NO\n";
        return 0;
    }
    else if(weights.size() == 1 && m == 1)
    {
        cout << "YES\n";
        cout << weights[0] << nl;
        return 0;
    }

    v(int) final_w;
    int ans = dfs_state(final_w, weights, m, 0, 0, 1);

    if(ans == 0) cout << "NO";
    else for(int i = final_w.size() - 1; i >= 0; i--) cout << final_w[i] << " ";
    cout << nl;

    return 0;
}