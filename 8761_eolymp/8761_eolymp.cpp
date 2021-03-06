#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector <pair <int, int>> v;
vector<bool> used;
vector<int> d;
vector<int> f;
int my_time = 1;

void dfs(const int &vertex_v) {
	used[vertex_v - 1] = true;
	d[vertex_v - 1] = my_time ++;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first == vertex_v && !used[v[i].second - 1]) dfs(v[i].second);
		else if (v[i].second == vertex_v && !used[v[i].first - 1]) dfs(v[i].first);
	}
	f[vertex_v - 1] = my_time ++;
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	v.resize(edges);
	used.resize(vertices, false); 
	d.resize(vertices);
	f.resize(vertices);
	for (int i = 0; i < edges; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}
	int vertex_v;
	cin >> vertex_v;
	dfs(vertex_v);
	for (int i = 0; i < used.size(); ++i) {
		cout << d[i] << ' ' << f[i] << endl;
	}
    return 0;
}

