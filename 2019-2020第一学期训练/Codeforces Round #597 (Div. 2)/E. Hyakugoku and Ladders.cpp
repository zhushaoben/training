#include<bits/stdc++.h>
using namespace std;
int a[11][11];
double f[11][11];
int cal(int x,int y){
	return (x-1)*10+((x&1)?y:10-y+1);
}
int recal(int x){
	int y=(x-1)/10+1;
	return y*100+((y&1)?(x-1)%10+1:10-(x-1)%10);
}
double C(int x,int y){
	return min(f[x][y],f[x-a[x][y]][y]);
}
int main(){
	for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)scanf("%d",a[i]+j);
	for(int i=1;i<=10;i++){
		if(i&1)for(int j=1,x;j<=10;j++){
			if(i==7)
			i=7;
			if((x=cal(i,j))<=6){
				if(j!=1)f[i][j]=6;
			}
			else{
//				f[i][j]=1;
				for(int k=1;k<=6;k++){
					int x1=recal(x-k)/100,y1=recal(x-k)%100;
					f[i][j]+=(C(x1,y1)+1)/6;
				}
			}
		}
		else for(int j=10,x;j>=1;j--){
			x=cal(i,j);f[i][j]=1;
			for(int k=1;k<=6;k++){
				int x1=recal(x-k)/100,y1=recal(x-k)%100;
				f[i][j]+=(C(x1,y1))/6;
			}
		}
	}
	printf("%.10lf",f[10][1]);
	return 0;
}
