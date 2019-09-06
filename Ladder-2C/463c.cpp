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

    v(ll) principal_diagonal_sum(2*n + 1, 0), secondary_diagonal_sum(2*n + 1, 0);
    v(v(int)) points(n + 1, v(int)(n + 1));
    
    
    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= n; y++)
        {
            cin >> points[x][y];

            principal_diagonal_sum[x - y + n] += points[x][y];
            secondary_diagonal_sum[x + y] += points[x][y];
        }
    }


    int white_x, white_y; ll white_best = 0;
    int black_x, black_y; ll black_best = 0;

    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= n; y++)
        {
            ll bishop_score = principal_diagonal_sum[x - y + n] + secondary_diagonal_sum[x + y] - points[x][y];

            if((x + y)%2)
            {
                if(bishop_score >= white_best)
                {
                    white_best = bishop_score, white_x = x, white_y = y;
                }
            }
            else if((x + y)%2 == 0)
            {
                if(bishop_score >= black_best)
                {
                    black_best = bishop_score, black_x = x, black_y = y;
                }
            }
        }
    }

    ll best = black_best + white_best;
    cout << best << nl;
    cout << white_x << " " << white_y << " " << black_x << " " << black_y << nl;

    return 0;
}