#include<bits/stdc++.h>
using namespace std;
#define maxn 55
struct Point{
	double x,y;
}p[maxn],r[maxn];
Point midpoint(Point a,Point b){return Point{(a.x+b.x)/2,(a.y+b.y)/2};}
double dist(Point a,Point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
struct Cir{
	Point o;double r;
}D;
bool incir(Cir a,Point b){return dist(a.o,b)<=a.r;}
Cir cocir(Point x,Point y,Point z){
	double a=x.x-y.x,b=x.y-y.y,c=x.x-z.x,d=x.y-z.y,
	e=-((x.x*x.x-y.x*y.x)-(y.y*y.y-x.y*x.y))/2,f=-((x.x*x.x-z.x*z.x)-(z.y*z.y-x.y*x.y))/2;
	Point o=Point{(f*b-e*d)/(a*d-b*c),(f*a-e*c)/(b*c-d*a)};
	return Cir{o,dist(x,o)};
}
Cir welzl(int s1,int s2){
	if(!s1||s2>=3){
		if(!s2)return Cir{p[0],-1};
		if(s2==1)return Cir{r[0],0};
		if(s2==2)return Cir{midpoint(r[0],r[1]),dist(r[0],r[1])/2};
		return cocir(r[0],r[1],r[2]);
	}
	int x=rand()%s1;swap(p[x],p[s1-1]);
	D=welzl(s1-1,s2);
	if(incir(D,p[s1-1]))return D;
	r[s2++]=p[s1-1];return welzl(s1-1,s2);
}
int main(){
	int n;scanf("%d",&n);srand(0);
	for(int i=0;i<n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
	printf("%.10lf",welzl(n,0).r);
	return 0;
} 
