const int maxn=5e5;
int prim[maxn/5],prime_n; 
bool nt_pr[maxn]={1,1};
void prime(){
    for(int i=2;i<=maxn;i++){
        if(!nt_pr[i])prim[prime_n++]=i;//没有筛掉的为素数
        for(int j=0;j<prime_n&&i*prim[j]<=maxn;j++){
            nt_pr[prim[j]*i]=1;//筛掉
            if(i%prim[j]==0)break;//后面的数最小因数一定小于等于prim[j]
        }
    }
}

//筛出最小质因数 
const int N=5e5;
int prim[N/5],prime_n,midiv[N+5]; 
void prime(){
    for(int i=2;i<=N;i++){
        if(!midiv[i])prim[prime_n++]=i,midiv[i]=i;//没有筛掉的为素数
        for(int j=0;j<prime_n&&i*prim[j]<=N;j++){
            midiv[prim[j]*i]=prim[j];//筛掉
            if(i%prim[j]==0)break;//后面的数最小因数一定小于等于prim[j]
        }
    }
}
