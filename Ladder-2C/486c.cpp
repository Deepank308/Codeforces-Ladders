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
    int n, p;
    cin >> n >> p;
    p--;
    string s;
    cin >> s;
    int len = s.size();
    if(len == 1)
    {
        cout << "0" << nl;
        return 0;
    }

    ll cost = 0;
    
    if(p > len / 2 && len%2 == 1) p = len - p - 1;
    else if(p >= len / 2 && len%2 == 0) p = len - p - 1;

    loop(i, 0, len / 2)
    {
        int change = abs(s[i] - s[len - i - 1]);
        cost += min(change, 26 - change);
    }

    int min_ = len / 2 - 1, max_ = 0;
    loop(i, 0, len / 2)
    {
        if(s[i] != s[len - i - 1])
        {
            if(min_ > i) min_ = i;
            if(max_ < i) max_ = i;
        }
    }
    if(min_ > max_)
    {
        min_ = p;
        max_ = p;
    }
    min_ = min_ - p;
    max_ = max_ - p;

    if(min_*max_ < 0)
        cost += min(abs(min_), abs(max_)) + abs(max_) + abs(min_);
    else
        cost += max(abs(min_), abs(max_));

    cout << cost << nl;
    return 0;
}