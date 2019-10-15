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
    int n;
    cin >> n;

    v(int) arr(n), a(n);
    loop(i, 0, n) cin >> arr[i], a[i] = arr[i];
    
    sort(a.begin(), a.end());

    int count = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] != a[i]) count++;

    if(count > 2) cout << "NO" << nl;
    else cout << "Yes" << nl;

    return 0;
}