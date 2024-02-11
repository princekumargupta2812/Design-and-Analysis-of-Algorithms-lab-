// Time Complexity :O(N) Where N is Number of Box in cardboard
// Space Complexity:O(N) Where N is Number of Box in cardboard
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter Last Number of cardboard" << endl;
    cin >> n;
    int m;
    cout << "NO of snakes" << endl;
    cin >> m;
    map<int, int> pa;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        pa[a] = b;
    }
    int m2;
    cout << "NO of leddars" << endl;
    cin >> m2;

    for (int i = 0; i < m2; i++){
        int a, b;
        cin >> a >> b;
        pa[a] = b;
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    int ans = INT_MAX;
    int vis[n + 1] = {0};
    while (q.size() != 0){
        int x = q.front().first;
        int y = q.front().second;
        if (x == n)
        {
            ans = min(ans, y);
        }
        q.pop();
        for (int i = 1; i < 6; i++)
        {
            if (x + i <= n)
            {
                if (vis[x + i] == 0)
                {
                    vis[x + i] = 1;
                    if (pa[x + i] != 0)
                    {
                        int k = pa[x + i];
                        if (vis[k] == 0)
                        {
                            vis[k] = 1;
                            q.push({k, y + 1});
                        }
                    }
                    else
                    {
                        vis[x + i] = 1;
                        q.push({x + i, y + 1});
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}