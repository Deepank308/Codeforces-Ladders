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

    int temp = n, size = 0;
    while(temp)
    {
        size++;
        temp = temp/10;
    }

    v(int) digits(size, -1);
    temp = n;
    while(temp)
    {
        digits[size - 1] = temp%10;
        temp = temp / 10;
        size--;
    }

    ll ans = pow(2, digits.size()) - 1, remove = 0;

    if(digits[0] == 1)
    {
        loop(i, 0, digits.size())
        {
            if(digits[i] > 1) break;
            if(digits[i] == 0)
            {
                remove += pow(2, digits.size() - i - 1);
            }
        }
    }

    cout << ans - remove << nl;
    return 0;
}