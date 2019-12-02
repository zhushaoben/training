#include<cstdio>
const int fac[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320};//阶乘,不够用可以再加 
int cantor(int a[],int k){//康托展开 
	int ans=0,tmp;
	for(int i=0;i<k;i++){
		tmp=0;//记录有几个比它小的数 
		for(int j=i+1;j<k;j++){
			if(a[j]<a[i])tmp++;
		}
		ans+=tmp*fac[k-i-1];
	}
	return ans;
}
void uncantor(int a[],int k,int num){//逆康托展开
	int b[10];//b表示剩下的数,并且按升序排列 
	for(int i=0;i<k;i++)b[i]=i+1;
	b[k]=0;
	for(int i=0,x;i<k;i++){
		x=num/fac[k-i-1],num%=fac[k-i-1],a[i]=b[x];//x表示当前数是剩下的数中的第几个 
		for(int j=x;b[j];j++){
			b[j]=b[j+1];
		}
	}
}
int main(){
	return 0;
} 
