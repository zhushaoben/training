#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
#define inf 1000000005
 
struct node {
    int x, y;
}dot[1005 * 4];
 
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &dot[i].x, &dot[i].y);
        int step = 0;
        int nowx = 0;
        int nowy = 0;
        int turn = 2;
        while (step <= 4*n + 1) {
            int tempx = -inf, tempy = -inf;
            if (turn == 1) {
                for (int i = 1; i <= n; i++) {
                    if (dot[i].x == nowx && dot[i].y > nowy) {
                        tempx = dot[i].x;
                        if (tempy != -inf) tempy = min(tempy, dot[i].y);
                        else tempy = dot[i].y;
                    }
                }
                if (tempx == -inf || tempy == -inf) break;
                step++;
                nowx = tempx;
                nowy = tempy - 1;
                turn = 2;
            }
            else if (turn == 2) {
                for (int i = 1; i <= n; i++) {
                    if (dot[i].x > nowx && dot[i].y == nowy) {
                        tempy = dot[i].y;
                        if (tempx != -inf) tempx = min(tempx, dot[i].x);
                        else tempx = dot[i].x;
                    }
                }
                if (tempx == -inf || tempy == -inf) break;
                step++;
                nowx = tempx - 1;
                nowy = tempy;
                turn = 3;
            }
            else if (turn == 3) {
                for (int i = 1; i <= n; i++) {
                    if (dot[i].x == nowx && dot[i].y < nowy) {
                        tempx = dot[i].x;
                        if (tempy != -inf) tempy = max(tempy, dot[i].y);
                        else tempy = dot[i].y;
                    }
                }
                if (tempx == -inf || tempy == -inf) break;
                step++;
                nowx = tempx;
                nowy = tempy + 1;
                turn = 4;
            }
            else {
                for (int i = 1; i <= n; i++) {
                    if (dot[i].x < nowx && dot[i].y == nowy) {
                        tempy = dot[i].y;
                        if (tempx != -inf) tempx = max(tempx, dot[i].x);
                        else tempx = dot[i].x;
                    }
                }
                if (tempx == -inf || tempy == -inf) break;
                step++;
                nowx = tempx + 1;
                nowy = tempy;
                turn = 1;
            }
        }
        if(step > 4*n + 1) printf("-1\n");
        else printf("%d\n", step);
    }
    return 0;
}
