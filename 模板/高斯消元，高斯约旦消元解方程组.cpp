#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;
double a[55][55],ans[55];
int d;
int gauss_jordan(int n){//aΪ������� 
	int r,w=0;
	for(int i=0;i<n&&w<n;w++,i++){//���е���i�У���w�� 
		int r=w;
		for(int j=w+1;j<n;j++)if(fabs(a[j][i])>fabs(a[r][i]))r=j;//�ҵ���ǰ�о���ֵ������ 
		if(fabs(a[r][i])<eps){w--;continue;}//��ǰ��ֵ��Ϊ0,�����ǰ�� 
		if(r!=w)for(int j=0;j<=n;j++)swap(a[r][j],a[w][j]);//������ǰ�о���ֵ�����к�û������ĵ�һ��
		for(int k=0;k<n;k++){//��ȥ��ǰ�У��������⣩
			if(k!=w)
			for(int j=n;j>=w;j--)a[k][j]-=a[k][i]/a[w][i]*a[w][j];
		}
	}
	return w;
}
int gauss(int n){//aΪ�������  
	int r,w;
	for(int i=0;w<n&&i<n;i++,w++){//���е���i�У���w��
		int r=w;
		for(int j=w+1;j<n;j++)if(fabs(a[j][i])>fabs(a[r][i]))r=j;//�ҵ���ǰ�о���ֵ������ 
		if(fabs(a[r][i])<eps){w--;continue;}//��ǰ��ֵ��Ϊ0,�����ǰ�� 
		if(w!=r)for(int j=i;j<=n;j++)swap(a[r][j],a[w][j]);//������ǰ�о���ֵ�����к�û������ĵ�һ�� 
		for(int k=w+1;k<n;k++){//��ȥ��ǰ�У�ֻ�������еģ� 
			double pro=a[k][i]/a[w][i];
			for(int j=i;j<=n;j++)
				a[k][j]-=pro*a[w][j];
		}
	}
	return w;
}
int main(){
	int n;scanf("%d",&n);//��������� 
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			scanf("%lf",a[i]+j);//����������� 
		}
	}
	#if 0 //guass
	d=gauss(n);d--;
	for(int j=d;j<n;j++){
		if(fabs(a[j][n-1])<eps&&fabs(a[j][n])>eps){printf("-1");return 0;}//���һ������δ֪�����٣�����=�ұ߲�Ϊ0=���Ϊ0�����޽�
	}
	if(d<n-1){printf("0");return 0;}//һ�����̽�һ��δ֪������Ч��������n���������� 
	for(int i=d;i>=0;i--){
		for(int k=i+1;k<n;k++)a[i][n]-=a[i][k]*ans[k];
		ans[i]=a[i][n]/a[i][i];
	}
	#endif
	#if 1 //guass_jordan
	d=gauss_jordan(n);d--;
	for(int i=0;i<n;i++){//��һ������=�ұ߲�Ϊ0=���Ϊ0�����޽� 
		bool d=1;
		for(int j=i;j<n;j++)d&=(fabs(a[i][j])<eps);
		if(d&&fabs(a[i][n])>eps){
			printf("-1");return 0;
		}
	}
	for(int i=0;i<n;i++){//��Ԫ���б����ڶ�������г��֣����ж���� 
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
