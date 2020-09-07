#include<bits/stdc++.h>
using namespace std;

int main(){
	int x[3],y[3];
	for(int i=0;i<3;i++)scanf("%d%d",x+i,y+i);
	for(int i=0;i<3;i++){
		int dis=(x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3])+(y[i]-y[(i+1)%3])*(y[i]-y[(i+1)%3]);
		int dis1=(x[i]-x[(i+2)%3])*(x[i]-x[(i+2)%3])+(y[i]-y[(i+2)%3])*(y[i]-y[(i+2)%3]);
		if(dis==dis1)printf("%d %d",x[(i+1)%3]+x[(i+2)%3]-x[i],y[(i+1)%3]+y[(i+2)%3]-y[i]);
	}
	return 0;
}
