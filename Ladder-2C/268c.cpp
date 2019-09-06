#include<bits/stdc++.h>

using namespace std;

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define v(d_type) vector<d_type>
#define loop(i, s, n) for(int i = s; i < n; i++)
#define print_vec(X) loop(i, 0, X.size()) cout << X[i] << "\n"
#define nl "\n"


int main()
{
    int n, m, c = 0;
    cin >> n >> m;
    
    int min_ = min(n, m) + 1;

    cout << min_<< nl;
    if(min_ == n + 1)
    {
        while(min_)
        {
            min_--;
            int x = min_;
            int y = c++;
            cout << x << " " << y << nl;
        }
    }
    else
    {
        while(min_)
        {
            min_--;
            int y = min_;
            int x = c++;
            cout << x << " " << y << nl;
        }
    }

    return 0;
}