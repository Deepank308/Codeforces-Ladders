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

    string s;
    cin >> s;

    ll a, b;
    cin >> a >> b;

    vector<int> prefix_a(s.size() + 1, 0), sufix_b(s.size() + 1, 0);

    ll a_mod, b_mod;
    loop(i, 0, s.size())
    {
        a_mod = (prefix_a[i]*10)%a + s[i] - '0';
        prefix_a[i + 1] = a_mod%a;
    }
    int pow = 1;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        pow = pow%b;
        b_mod = sufix_b[s.size() - i - 1] + ((s[i] - '0')*pow)%b;
        sufix_b[s.size() - i] = b_mod%b;
        pow = pow*10;
    }

    int partition_idx = 0, flag = 0;

    loop(i, 1, s.size())
    {
        if(sufix_b[i] == 0 && s[s.size() - i] != '0')
        {
            if(prefix_a[s.size() - i] == 0)
            {
                flag = 1;
                partition_idx = s.size() - i;
                break;
            }
        }
    }
    if(flag == 1)
    {
        cout << "YES\n";
        cout << s.substr(0, partition_idx) << nl << s.substr(partition_idx, s.size() - partition_idx) << nl;
    }
    else cout << "NO\n";

    return 0;
}