#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=300005;
const ll mod=1e9+7;
const double eps=1e-7;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	else if(x<0) return -1;
	else return 1;
}
#define Vector Point
#define Seg Line
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
	Point operator - (const Point &b)const{
		return Point(x-b.x, y-b.y);
	}
	double operator * (const Point &b)const{
		return x*b.x+y*b.y;
	}
	double operator ^ (const Point &b)const{
		return x*b.y-y*b.x;
	}
	double Dis(Point b){
		return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
	}
	void input(){
		scanf("%lf%lf",&x,&y);
	}
};

Point ps,p[15];
double res[15];
int n;
bool check(int aa,int bb,int cc)
{
	Point a=p[aa],b=p[bb],c=p[cc];
	if(sgn((ps-a)^(a-b))!=0 && sgn((ps-a)^(a-b))!=sgn((c-a)^(a-b))) return 0;
	if(sgn((ps-b)^(b-c))!=0 && sgn((ps-b)^(b-c))!=sgn((a-b)^(b-c))) return 0;
	if(sgn((ps-c)^(c-a))!=0 && sgn((ps-c)^(c-a))!=sgn((b-c)^(c-a))) return 0;
	return 1;
}
void solve(int i1,int i2,int i3){
	double a=p[i1].x-p[i2].x,b=p[i1].x-p[i3].x,c=p[i1].x-ps.x;
	double d=p[i1].y-p[i2].y,e=p[i1].y-p[i3].y,f=p[i1].y-ps.y;
	double ans[3]={0,0,0};
	
	if(sgn(b*d-a*e)==0) ans[2]=0;
	else ans[2]=(c*d-a*f)/(b*d-a*e);
	if(sgn(a*e-b*d)==0) ans[1]=0;
	else ans[1]=(c*e-b*f)/(a*e-b*d);
	
	ans[0]=1.0-ans[1]-ans[2];
	res[i1]=ans[0]; res[i2]=ans[1]; res[i3]=ans[2];
	assert(sgn(p[i1].x*ans[0]+p[i2].x*ans[1]+p[i3].x*ans[2]-ps.x)==0);
	assert(sgn(p[i1].y*ans[0]+p[i2].y*ans[1]+p[i3].y*ans[2]-ps.y)==0);
}
int main(){
	n=read(); ps.input();
	for(int i=0; i<n; i++) p[i].input();
	for(int i=1; i<n; i++){
		for(int j=i+1;j<n;j++){
			if(check(0, i, j)){
				solve(0, i, j);printf("%.10lf\n",res[0]);
				for(int l=1;l<i;l++)puts("0");
				printf("%.10lf\n",res[i]);
				for(int l=i+1;l<j;l++)puts("0");
				printf("%.10lf\n",res[j]);
				for(int l=j+1;l<n;l++)puts("0");
				return 0;
			} 
		}
		
	}
	assert(0);
	return 0;
}


