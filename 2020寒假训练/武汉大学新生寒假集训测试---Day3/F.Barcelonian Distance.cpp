#include<bits/stdc++.h>
using namespace std;
#define ll double
struct Node{
	ll x,y;
}A[4],B[4],s,t;
double dis(Node a,Node b){
	return (double)abs(a.x-b.x)+abs(a.y-b.y);
}
double dist(Node a,Node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	int a,b,c,g;ll x,y;scanf("%d%d%d%lf%lf%lf%lf",&a,&b,&c,&s.x,&s.y,&t.x,&t.y);
	if(!a||!b)return printf("%.10lf",dis(s,t)),0;
//	ax+by+c=0;
	A[0].x=s.x;A[1].y=s.y;
	A[0].y=(-a*s.x-c)/b;A[1].x=(-b*s.y-c)/a;
	B[0].x=t.x;B[1].y=t.y;
	B[0].y=(-a*t.x-c)/b;B[1].x=(-b*t.y-c)/a;
	double ans=dis(s,t);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)ans=min(ans,dis(s,A[i])+dist(A[i],B[j])+dis(B[j],t));
	}
	printf("%.10lf",ans);
	return 0;
}
