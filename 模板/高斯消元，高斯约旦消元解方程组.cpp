#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;
double a[55][55],ans[55];
int d;
int gauss_jordan(int n){//a为增广矩阵 
	int r,w=0;
	for(int i=0;i<n&&w<n;w++,i++){//进行到第i列，第w行 
		int r=w;
		for(int j=w+1;j<n;j++)if(fabs(a[j][i])>fabs(a[r][i]))r=j;//找到当前列绝对值最大的行 
		if(fabs(a[r][i])<eps){w--;continue;}//当前列值都为0,跨过当前步 
		if(r!=w)for(int j=0;j<=n;j++)swap(a[r][j],a[w][j]);//交换当前列绝对值最大的行和没计算过的第一行
		for(int k=0;k<n;k++){//消去当前列（除本行外）
			if(k!=w)
			for(int j=n;j>=w;j--)a[k][j]-=a[k][i]/a[w][i]*a[w][j];
		}
	}
	return w;
}
int gauss(int n){//a为增广矩阵  
	int r,w;
	for(int i=0;w<n&&i<n;i++,w++){//进行到第i列，第w行
		int r=w;
		for(int j=w+1;j<n;j++)if(fabs(a[j][i])>fabs(a[r][i]))r=j;//找到当前列绝对值最大的行 
		if(fabs(a[r][i])<eps){w--;continue;}//当前列值都为0,跨过当前步 
		if(w!=r)for(int j=i;j<=n;j++)swap(a[r][j],a[w][j]);//交换当前列绝对值最大的行和没计算过的第一行 
		for(int k=w+1;k<n;k++){//消去当前列（只消下面行的） 
			double pro=a[k][i]/a[w][i];
			for(int j=i;j<=n;j++)
				a[k][j]-=pro*a[w][j];
		}
	}
	return w;
}
int main(){
	int n;scanf("%d",&n);//方程组个数 
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			scanf("%lf",a[i]+j);//输入增广矩阵 
		}
	}
	#if 0 //guass
	d=gauss(n);d--;
	for(int j=d;j<n;j++){
		if(fabs(a[j][n-1])<eps&&fabs(a[j][n])>eps){printf("-1");return 0;}//最后一个方程未知数最少，方程=右边不为0=左边为0，则无解
	}
	if(d<n-1){printf("0");return 0;}//一个方程解一个未知数，有效方程少于n个，则多个解 
	for(int i=d;i>=0;i--){
		for(int k=i+1;k<n;k++)a[i][n]-=a[i][k]*ans[k];
		ans[i]=a[i][n]/a[i][i];
	}
	#endif
	#if 1 //guass_jordan
	d=gauss_jordan(n);d--;
	for(int i=0;i<n;i++){//有一个方程=右边不为0=左边为0，则无解 
		bool d=1;
		for(int j=i;j<n;j++)d&=(fabs(a[i][j])<eps);
		if(d&&fabs(a[i][n])>eps){
			printf("-1");return 0;
		}
	}
	for(int i=0;i<n;i++){//消元后有变量在多个方程中出现，则有多个解 
		int max1=0;
		for(int j=i;j<n;j++)if(fabs(a[i][j])>eps)max1++;
		if(max1>1){printf("0");return 0;}
	}
	for(int i=0;i<n;i++){
		ans[i]=a[i][n]/a[i][i];
	}
	#endif
	for(int i=0;i<n;i++){
		if(fabs(ans[i])<eps)printf("x%d=0\n",i+1);
		else printf("x%d=%.2lf\n",i+1,ans[i]);
	}
	return 0;
}
