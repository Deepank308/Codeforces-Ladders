#include<bits/stdc++.h>

using namespace std;

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define v(d_type) vector<d_type>
#define p(d_type1, d_type2) pair<d_type1, d_type2>
#define F first
#define S second
#define loop(i, s, n) for(int i = s; i < n; i++)
#define nl "\n"
#define fat 1000000007

int main()
{
    boost;
    int n, k, d;
    cin >> n >> k >> d;

    int exp = d, b = 1;
    while(b <= 1000 && exp > 0)
    {
        b = b*k;
        exp--;
    }
    if(n <= b)
    {
        // print first n d-digits numbers in base k
        v(v(int)) ans(n, v(int)(d, 0));

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < d; j++) ans[i][j] = ans[i - 1][j];
            for(int j = d - 1; j >= 0; j--)
            {
                ans[i][j] = (ans[i][j] + 1)%k;
                if(ans[i][j]) break;
            }
        }
        for(int j = 0; j < d; j++)
        {
            for(int i = 0; i < n ; i++)
            {
                cout << ans[i][j] + 1 << " ";
            }
            cout << nl;
        }
    }
    else
    {
        cout << -1 << nl;
    }
    return 0;
}