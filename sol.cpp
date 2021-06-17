#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<vector<char>> a(n, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		// create a 'visited' bool vector to mark the invalid elements
		vector<vector<bool>> visited(n, vector<bool>(n, true));
		for (int i = 0; i < n; i++) {
			// 'row_pos' contains the index of the hash sign ('#') (latest) in the row
			int row_pos = -1;
			for (int j = 0; j < n; j++) {
				if (a[i][j] == '#') {
					row_pos = j;
				}
			}
			// 'col_pos' contains the index of the hash sign ('#') (latest) in the column
			int col_pos = -1;
			for (int j = 0; j < n; j++) {
				if (a[j][i] == '#') {
					col_pos = j;
				}
			}
			// set all the elements that appeared before the current 'row_pos' to false 
			// (because these elements will be blocked by the hash sign)
			for (int j = 0; j <= row_pos; j++) {
				visited[i][j] = false;
			}
			// set all the elements that appeared before the current 'col_pos' to false 
			// (because these elements will be blocked by the hash sign)
			for (int j = 0; j <= col_pos; j++) {
				visited[j][i] = false;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) {
					// if the current element is still true, then increment 'cnt'
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
