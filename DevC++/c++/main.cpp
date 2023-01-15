# include <iostream>

using namespace std;

const int N = 102;

char ch[N][N];
int state[N][N];
char ans[] = " yizhong";
int num;

int dfs(int n, int m, int no){
	if (n > num || m > num || n < 1 || m < 1)	return 0;
	
	if (ans[no] == ch[n][m]){
		if (no == 7){
			state[n][m] = 1;
			return 1;
		}
		else {
			if (dfs(n, m+1, no+1) || dfs(n, m-1, no+1) || dfs(n-1, m, no+1) || dfs(n+1, m, no+1) || dfs(n+1, m+1, no+1) || dfs(n-1, m+1, no+1) || dfs(n-1, m-1, no+1) || dfs(n+1, m-1, no+1)){
				state[n][m] = 1;
				return 1;
			}
			else return 0;
		}
	}
	else {
		return 0;
	}
}

int main(){
	
	cin >> num;
	for (int i = 1; i <= num; i ++)
		for (int j = 1; j <= num; j ++) cin >> ch[i][j];
		
	for (int i = 1; i <= num; i ++)
		for (int j = 1; j <= num; j ++)
			dfs(i, j, 1);
			
	for (int i = 1; i <= num; i ++){
		for (int j = 1; j <= num; j ++){
			if (state[i][j]) cout << ch[i][j];
			else cout << '*';
		}
		cout << endl;
	}
	
	return 0;
}
