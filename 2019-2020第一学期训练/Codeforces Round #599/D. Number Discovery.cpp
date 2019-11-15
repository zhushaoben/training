/*
Let's make some definitions:
x is non-self number if x is appended into s by summation form.
 For example, if k==2, then 3,9,13,18,¡­are non-self numbers.
 
the there while exactly one non-self number among 
(k*k+1)*w+1,(k*k+1)*w+2,¡­¡­  (k*k+1)*w+k*k+1
Peoof:obviously the situation w=0 is established 
and for the w+1 round,we set l=w*k+(w/k)+1,r=l+k-1;
then the sum will in [(l+r)*k/2,(l+r+2)*k/2]=[w*(k*k+1)+k*(k+1)/2-w%k,w*(k*k+1)+k*(k+1)/2-w%k+2k] 
obviously sum in [w*(k*k+1)+1,(w+1)*(k*k+1)]
*/
#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL calc(LL w,LL k){//calculate the non-self number of (w+1) round
	if(!w)return k*(k+1)/2;
	LL x=calc(w/k,k),l=w*k+(w/k)+1,r=l+k-1,sum=(l+r)*k/2;
	return sum+max(0ll,min(r-x+1,k));
}
LL solve(LL n,LL k){
	LL w=(n-1)/(k*k+1),x=calc(w,k);
	if(x==n)return (w+1)*(k+1);
	LL sum=w+(x<n);//the number of non-self numbers
	return n+(n-sum-1)/k-sum;
}
void work(){
	LL n,k;scanf("%lld%lld",&n,&k);
	printf("%lld\n",solve(n,k));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
