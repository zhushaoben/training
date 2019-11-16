#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define LD  long double
#define eps 1e-8
int n;LD x,y,x1,y001,A,B,C,x3,y3,x4,y4;
bool le(int x1,int y001,int x2,int y2,int x3,int y3)
{
    double tmpx = (x2 - x3) / (y2 - y3) * (y001 - y3) + x3;
    if (tmpx > x1)
        return true;
    return false;
}
bool check(LD x2,LD y2){
	return !(le(x2,y2,x,y,x3,y3)^le(x2,y2,x1,y001,x4,y4));
}
LD dis(LD x2,LD y2){
	return fabs((A*x2+B*y2+C)/sqrt(A*A+B*B));
}
void work(){
	scanf("%d%Lf%Lf%Lf%Lf",&n,&x,&y,&x1,&y001);
	LD ans=sqrt((x1-x)*(x1-x)+(y001-y)*(y001-y));
	A=y001-y,B=x-x1;C=-1*(A*x+B*y);LD C1;
	if(A)x3=x+1,C1=A*y-B*x,y3=(C1+B*x3)/A;
	else y3=y+1,C1=A*y-B*x,x3=(A*y3-C1)/B;
	x4=x1+(x3-x) ,y4=y001+(y3-y);
	for(int i=0;i<n;i++){
		LD x2,y2,r;LD w;
		scanf("%Lf%Lf%Lf",&x2,&y2,&r);
		if(check(x2,y2)||(w=dis(x2,y2))>r-eps)continue;
		ans+=r*acos(w/r)*2-sqrt(r*r-w*w)*2;
	}
	printf("%.3Lf\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
