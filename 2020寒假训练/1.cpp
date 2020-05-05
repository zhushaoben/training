#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int dir1[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int dir2[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
int dir3[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dp[12][12][5][205][105];
 
struct node
{
    int x,y,z,t,k;
    node(int _x,int _y,int _z,int _t,int _k)
    {
        x=_x,y=_y,z=_z,t=_t,k=_k;
    }
};
 
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,sx,sy,ex,ey;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
            {
                sx=i,sy=j;
            }
 
            if(a[i][j]==n*n)
            {
                ex=i,ey=j;
            }
        }
    }
 
    queue <node> q;
    q.push(node{sx,sy,1,0,1});
    q.push(node{sx,sy,2,0,1});
    q.push(node{sx,sy,3,0,1});
    dp[sx][sy][1][0][1]=dp[sx][sy][2][0][1]=dp[sx][sy][3][0][1]=0;
 
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        //cout<<u.x<<" "<<u.y<<" "<<u.z<<" "<<u.t<<" "<<u.k<<endl;
        int x=u.x,y=u.y,z=u.z,t=u.t,k=u.k;
        for(int i=1;i<=3;i++)  //原地不动，改方向
        {
            if(i==z) continue;
            if(dp[x][y][i][t+1][k]!=-1) continue;
            dp[x][y][i][t+1][k]=dp[x][y][z][t][k]+1;
            q.push(node{x,y,i,t+1,k});
        }
 
        if(z==1) //一个方向走
        {
            for(int i=0;i<8;i++)
            {
                int kk=k;
                int xx=x+dir1[i][0],yy=y+dir1[i][1];
                if(xx<1||xx>n||yy<1||yy>n) continue;
                if(a[xx][yy]==k+1) kk++;
                if(dp[xx][yy][z][t][kk]!=-1) continue;
                dp[xx][yy][z][t][kk]=dp[x][y][z][t][k]+1;
                q.push(node{xx,yy,z,t,kk});
            }
        }
 
        else if(z==2)
        {
            for(int j=1;j<=n;j++)
            {
                for(int i=0;i<4;i++)
                {
                    int kk=k;
                    int xx=x+j*dir2[i][0],yy=y+j*dir2[i][1];
                    if(xx<1||xx>n||yy<1||yy>n) continue;
                    if(a[xx][yy]==k+1) kk++;
                    if(dp[xx][yy][z][t][kk]!=-1) continue;
                    dp[xx][yy][z][t][kk]=dp[x][y][z][t][k]+1;
                    q.push(node{xx,yy,z,t,kk});
                }
            }
        }
 
        else if(z==3)
        {
            for(int j=1;j<=n;j++)
            {
                for(int i=0;i<4;i++)
                {
                    int kk=k;
                    int xx=x+j*dir3[i][0],yy=y+j*dir3[i][1];
                    if(xx<1||xx>n||yy<1||yy>n) continue;
                    if(a[xx][yy]==k+1) kk++;
                    if(dp[xx][yy][z][t][kk]!=-1) continue;
                    dp[xx][yy][z][t][kk]=dp[x][y][z][t][k]+1;
                    q.push(node{xx,yy,z,t,kk});
                }
            }
        }
    }
 	int n1=n*n-20;
    int minn=1e9;
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<=200;j++)
        {
            if(dp[ex][ey][i][j][n1]!=-1)
            {
                minn=min(minn,dp[ex][ey][i][j][n1]);
            }
        }
    }
    int flag=n*n;
    for(int i=1;i<=3;i++)
    {
        for(int j=200;j>=0;j--)
        {
            if(dp[ex][ey][i][j][n1]==minn)
            {
                if(flag>j) flag=j;
            }
        }
    }
 
    cout<<minn<<" "<<flag<<endl;
 
    return 0;
}
