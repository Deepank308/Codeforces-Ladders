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

void dfs(v(v(int)) &grid)
{

}

int main()
{
    boost;
    int n, m, k;
    cin >> n >> m >> k;
    v(v(int)) grid(n, v(int)(m));
    
    map<char, int> mp;
    mp['#'] = 0;
    mp['.'] = 1;
    
    map<int, char> ip;
    ip[0] = '#';
    ip[1] = '.';
    ip[2] = 'X';
    
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            char c;
            cin >> c;
            grid[i][j] = mp[c];
        }
    }
    loop(i, 0, n)
    {
        loop(j, 0, m)
            cout << grid[i][j];
        cout << nl;
    }

    dfs(grid);
    loop(i, 0, n)
    {
        loop(j, 0, m)
            cout << ip[grid[i][j]];
        cout << nl;
    }
    
    return 0;
}