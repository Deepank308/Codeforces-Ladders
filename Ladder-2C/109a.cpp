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

    int count_7 = n/7;
    int rem = n%7, count_4 = 0;

    switch(rem)
    {
        case 0:
            break;
        case 1:
            count_4 = 2;
            count_7 -= 1;
            break;
        case 2:
            count_4 = 4;
            count_7 -= 2;
            break;
        case 3:
            count_4 = 6;
            count_7 -= 3;
            break;
        case 4:
            count_4 = 1;
            break;
        case 5:
            count_4 = 3;
            count_7 -= 1;
            break;
        case 6:
            count_4 = 5;
            count_7 -= 2;
            break;
    }
    if(count_7 < 0 || count_4 < 0) cout << "-1";
    else
    {
        while(count_4--) cout << "4";
        while(count_7--) cout << "7";
    }
    
    cout << nl;
    return 0;
}