# include <iostream>

using namespace std;

const int N = 103;
int area[N][N];

int main(){

    int n, m, t;
    int ans = 0;
    cin >> n >> m >> t;
    while(t --){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        for (int i = r1; i <= r2; i ++){
            for (int j = c1; j <= c2; j ++){
                area[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (area[i][j] == 0){
                ans ++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}