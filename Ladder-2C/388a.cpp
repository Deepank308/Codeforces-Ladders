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
    int n;
    cin >> n;

    v(int) strength(n), visited(n, 0);
    loop(i, 0, n) cin >> strength[i];

    sort(strength.begin(), strength.end());

    ll num_piles = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(visited[i]) continue;
        num_piles++;

        int boxes = 0;
        for(int j = 0; j < i && boxes < strength[i]; j++)
        {
            if(visited[j]) continue;
            if(strength[j] >= boxes)
            {
                boxes++;
                visited[j] = 1;
            }
        }
        visited[i] = 1;
    }

    cout << num_piles << nl;

    return 0;
}