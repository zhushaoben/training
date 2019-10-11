#include<cstdio>
using namespace std;
#define maxn 1005
#define LL long long
int a[maxn],n;LL m;
LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}
LL lcm(LL a,LL b){
    return a*b/gcd(a,b);
}
void work(){
    LL g=1,sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        g=lcm(g,a[i]);
    }
    for(int i=0;i<n;i++){
        sum+=g/a[i];
    }
    if(m%sum)puts("No");
    else{
        g*=m/sum;
        puts("Yes");
        for(int i=0;i<n-1;i++)printf("%lld ",g/a[i]);
        printf("%lld\n",g/a[n-1]);
    }
    
}
int main(){
    while(~scanf("%d%lld",&n,&m))work();
    return 0;
}
