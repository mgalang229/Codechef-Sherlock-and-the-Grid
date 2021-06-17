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
		vector<vector<char>> inp(n, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> inp[i][j];
			}
		}
		vector<vector<int>> RayX(n, vector<int>(n));
		vector<vector<int>> RayY(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			// start the loop from the last element (work backwards)
			for (int j = n - 1; j >= 0; j--) {
				// check if the current character is a dot symbol (for row)
				if (inp[i][j] == '.') {
					// if yes, then start checking from the last element in this row if
					// there is a clear path that exists by setting every element equal to
					// the value of the previous adjacent element
					RayX[i][j] = (j != n - 1) ? RayX[i][j + 1] : 1;
				} else {
					// otherwise, set the element to 0
					RayX[i][j] = 0;
				}
				// check if the current character is a dot symbol (for column)
				if (inp[j][i] == '.') {
					// if yes, then start checking from the last element in this column if
					// there is a clear path that exists by setting every element equal to
					// the value of the previous adjacent element
					RayY[j][i] = (j != n - 1) ? RayY[j + 1][i] : 1; 
				} else {
					// otherwise, set the element to 0 
					RayY[j][i] = 0;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (RayX[i][j] == 1 && RayY[i][j] == 1) {
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
