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
    int len = s.size();
    stack<int> final;
    int count_1 = 0;
    int count_2 = 0;
    loop(i, 0, len)
    {
        if(final.empty())
        {
            final.push(i);
            count_1 = 1;
            count_2 = 0;
        }
        else
        {
            int top = final.top();
            if(s[top] == s[i])
            {
                count_1++;
                // cout << s[top] << ", " << s[i] << " " << count_1 << " " << count_2 << nl;
                if((count_2 == 2 && count_1 == 2) || count_1 == 3)
                    count_1--;
                else
                    final.push(i);
            }
            else
            {
                final.push(i);
                if(count_1 == 2)
                    count_2 = 2;
                else
                    count_2 = 0;
                count_1 = 1;
            }
        }
        // cout << s[i] << ": " << count_1 << " " << count_2 << nl;
    }
    string ans(final.size(), '0');
    int size = final.size();
    loop(i, 0, size)
    {
        // cout << s[final.top()];
        ans[size - i - 1] = s[final.top()];
        final.pop();
    }
    // cout << nl;
    cout << ans << nl;
    return 0;
}