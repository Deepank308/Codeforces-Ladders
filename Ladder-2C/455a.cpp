#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define v(d_type) vector<d_type>
#define loop(i, s, n) for(int i = s; i < n; i++)
#define min(x, y) (x) > (y) ? (y) : (x)
#define max(x, y) (x) < (y) ? (y) : (x)
#define print_vec(X) loop(i, 0, X.size()) cout << X[i] << "\n"

using namespace std;

int main(int argc, char const *argv[])
{
	boost;
	int n;
	cin >> n;
	v(int) a(n);
	v(ll) count(100001, 0);

	loop(i, 0, n)
	{
		cin >> a[i];
		count[a[i]]++;
	}

	v(ll) f(100001, 0);
	f[1] = count[1];

	loop(i, 2, 100001)
	{
		if(count[i] == 0)
			f[i] = f[i - 1];
		else
			f[i] = max(f[i - 1], f[i - 2] + count[i]*i);
	}
	cout << f[100000] << "\n";

	return 0;
}