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

bool comp(const p(int, int) &a, const p(int, int) &b)
{
    int dist_a = abs(a.F) + abs(a.S);
    int dist_b = abs(b.F) + abs(b.S); 
    if(dist_a != dist_b) return dist_a < dist_b;
    else return a < b;
}


int main()
{
    boost;
    int n;
    cin >> n;

    v(p(int, int)) points(n);
    loop(i, 0, n)
        cin >> points[i].F >> points[i].S;

    sort(points.begin(), points.end(), comp);

    int num_op = 6*n;
    loop(i, 0, n) if(points[i].F == 0 || points[i].S == 0) num_op -= 2;

    cout << num_op << nl;
    loop(i, 0, n)
    {
        int x = points[i].F;
        int y = points[i].S;

        if(x > 0) cout << "1 " << abs(x) << " R" << nl;
        else if(x < 0) cout << "1 " << abs(x) << " L" << nl;

        if(y > 0) cout << "1 " << abs(y) << " U" << nl;
        else if(y < 0) cout << "1 " << abs(y) << " D" << nl;


        cout << "2" << nl;


        if(x > 0) cout << "1 " << abs(x) << " L" << nl;
        else if(x < 0) cout << "1 " << abs(x) << " R" << nl;

        if(y > 0) cout << "1 " << abs(y) << " D" << nl;
        else if(y < 0) cout << "1 " << abs(y) << " U" << nl;


        cout << "3" << nl;
    }

    return 0;
}