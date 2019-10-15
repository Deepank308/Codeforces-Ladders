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

    v(int) arr(n);
    loop(i, 0, n) cin >> arr[i];

    if(n == 1)
    {
        cout << "-1" << nl;
        return 0;
    }

    sort(arr.begin(), arr.end());

    map<int, int>::iterator it; 
    map<int, int> diff;
    loop(i, 1, n) diff[arr[i] - arr[i - 1]]++;

    if(diff.size() > 2)
        cout << "0\n";
    else if(diff.size() == 1)
    {
        int count = diff.begin()->F;
        if(diff.find(0) == diff.end()) // array has multiple types of integer
        {
            if(n == 2)
            {
                if((arr[1] - arr[0])%2 == 0)
                {
                    cout << "3" << nl;
                    cout << arr[0] - count << " " << (arr[1] + arr[0]) / 2 << " " << arr.back() + count << nl;
                    return 0;
                }
            }
            cout << "2" << nl;
            cout << arr[0] - count << " " << arr.back() + count << nl;
        }
        else // array has only one integer
        {
            cout << "1" << nl;
            cout << arr[0] << nl;
        }
    }
    else
    {
        int max = 0, max_count = 0;
        for(it = diff.begin(); it != diff.end(); it++)
        {
            max = it->S > max_count ? it->F : max;
            max_count = diff[max];
        }
        if(max_count != n - 2 || max == 0)
        {
            cout << "0" << nl;
        }
        else
        {
            int other;
            for(it = diff.begin(); it != diff.end(); it++) if(max != it->F) other = it->F;
            if(other%2 == 1 || other == 0 || other != 2*max)
            {
                cout << "0" << nl;
            }
            else
            {
                cout << "1" << nl;
                loop(i, 1, n) if(arr[i] - arr[i - 1] == other) cout << (arr[i] + arr[i - 1]) / 2 << nl;
            }
        }
    }

    return 0;
}