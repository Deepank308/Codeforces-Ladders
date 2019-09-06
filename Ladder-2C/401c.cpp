#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	string seq(n + m, '1');
	if(n == m || n == m + 1)
	{
		for(int i = 0; i < n + m; i += 2)
			seq[i] = '0';
	}
	else if(n > m + 1 || m > 2*n + 2)
	{
		cout << "-1\n";
		return 0;
	}
	else if(2*(n - 1) == m|| 2*n == m)
	{
		for(int i = 0; i < n; i++)
			seq[3*i] = '0';
	}
	else if(2*(n + 1) == m || 2*(n + 1) - 1 == m)
	{
		for(int i = 1; i < n + 1; i++)
			seq[3*i - 1] = '0';
	}
	else
	{
		int i = 0;
		while(1)
		{
			if(i >= n)
				break;
			seq[3*i] = '0';
			if(m - 2*(i + 1) == n - (i + 1) || m - 2*(i + 1) + 1 == n - (i + 1))
				break;
			i++;
		}
		int j = 0 ;
		for(j = 3*(i + 1); i < n; j += 2, i++)
			seq[j] = '0';
		if(j < n + m - 3)
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << seq << "\n";
	return 0;
}