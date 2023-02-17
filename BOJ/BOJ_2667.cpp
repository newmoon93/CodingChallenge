#include <iostream>
#include "BOJ.h"
#include <vector>
#include <algorithm>
#define MAX 25

using namespace std;

int n;
int cnt;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int nx, ny;
int map[MAX][MAX];
bool visit[MAX][MAX];

vector<int> result;

void dfs(int x, int y) {
    visit[x][y] = true;
    if(map[x][y] == 1) {
        cnt++;
    }
    //cout << "cnt : " << cnt << " [x = " << x << ", y = " << y << "]" << endl;
    
    for(int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        //if ((0 <= nx < n) && (0 <= ny < n)) {                 // wrong
        if ((0 <= nx) && (nx < n) && (0 <= ny) && (ny < n)) {
            if (map[nx][ny] == 1 && !visit[nx][ny]) {
                dfs(nx,ny);
            }
        }
    }

}

int BOJ_10250(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //map[i][j] = x;
            scanf("%1d", &map[i][j]);
        }
    }
/*
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cout << map[i][j];
            }
            cout << endl;
    }
    cout << endl;
*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j] == 1 && !visit[i][j]) {
                cnt = 0;
                dfs(i,j);
                result.push_back(cnt);
/*
                cout << endl;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                            cout << visit[i][j];
                        }
                        cout << endl;
                }
                cout << endl;
*/
            }
        }
    }

    cout << result.size() << endl;
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}