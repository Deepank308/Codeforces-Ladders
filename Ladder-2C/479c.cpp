#include <bits/stdc++.h>

#define ios_sync ios_base::sync_with_stdio(false)
#define c_tie cin.tie(NULL), cout.tie(NULL)
#define v(d_type) vector<d_type>
#define loop(i, n) for(int i = 0; i < n; i++)
#define min(x, y) (x) > (y) ? (y) : (x)
#define max(x, y) (x) < (y) ? (y) : (x)

using namespace std;

bool comparator(v(int) a, v(int) b)
{
	if(a[0] == b[0])
		return a[1] < b[1];
	else
		return a[0] < b[0];
}

int main(int argc, char const *argv[])
{
	int n;
	ios_sync;
	c_tie;

	cin >> n;
	v(v(int)) schedule(n, v(int)(2));

	loop(i, n)
		cin >> schedule[i][0] >> schedule[i][1];
	sort(schedule.begin(), schedule.end(), comparator);

	int glb_min_day = 0;

	loop(i, n)
	{
		int min = min(schedule[i][0], schedule[i][1]);
		int max = max(schedule[i][0], schedule[i][1]);
		if(glb_min_day <= min)
			glb_min_day = min;
		else
			glb_min_day = max;
	}
	cout << glb_min_day << "\n";
	return 0;
}