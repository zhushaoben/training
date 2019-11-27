#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 1000
struct Node{
	LL s;int id;
	bool operator < (const Node &b)const{
		return s>b.s;
	}
}a[maxn+5];
struct Ans{
	int a[maxn+5],t;
	void init(int x,int y){a[0]=x,a[1]=y,t=2;}
	void push_back(int x){a[t]=a[t-1],a[(t++)-1]=x;}
	void push_front(int x){for(int i=t-1;i;i--)a[i+1]=a[i];a[1]=x;t++;}
	void Print(){printf("0");for(int i=0;i<t;i++)printf(" %d",a[i]);}
}ans;
int main(){
	int n,mi=2,ma,x;scanf("%d",&n);
	for(int i=3;i<=n;i++){//find the vertex on the left of vertex 1
		printf("2 1 %d %d\n",mi,i);fflush(stdout);
		scanf("%d",&x);
		if(x==1)mi=i;
	}
	for(int i=2;i<=n;i++){//find the distant between vertex i and line of vertex 1 and vertex mi
		if(i==mi)continue;
		printf("1 1 %d %d\n",mi,i);fflush(stdout);
		scanf("%lld",a+i),a[i].id=i;
	}
	sort(a+1,a+n+1);ans.init(1,mi),ans.push_back(ma=a[1].id);
	for(int i,j=2;j<n-1;j++){//sort the vertices
		i=a[j].id;
		if(i==mi||i==ma)continue;
		printf("2 1 %d %d\n",ma,i);fflush(stdout);
		scanf("%d",&x);
		if(x==1)ans.push_back(i);
		else ans.push_front(i);
	}
	ans.Print();
	return 0;
} 
