#include<cstdio>
void Inverse(int p,int a[],int n){//������<=n����%p�����µ���Ԫ 
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int main(){
	return 0;
} 
