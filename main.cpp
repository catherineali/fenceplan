#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x[100000], y[100000], mark[100000], ans = 1e9;
int a = 100000001, b = 0, c = 100000001, d = 0;
vector <int> adj[100000];

void visit(int i) {
	mark[i] = 1;
	a = min(a, x[i]);
	b = max(b, x[i]);
	c = min(c, y[i]);
	d = max(d, y[i]);
	for (int j : adj[i]) {
		if (!mark[j]) {
			visit(j);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!mark[i]) {
			a = 100000001, b = 0, c = 100000001, d = 0;
			visit(i);
			ans = min(ans, 2 * (b - a + d - c));
		}
		cout << ans << endl;
	}
}