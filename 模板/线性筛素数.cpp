const int maxn=5e5;
int prim[maxn/5],prime_n; 
bool nt_pr[maxn]={1,1};
void prime(){
    for(int i=2;i<=maxn;i++){
        if(!nt_pr[i])prim[prime_n++]=i;//û��ɸ����Ϊ����
        for(int j=0;j<prime_n&&i*prim[j]<=maxn;j++){
            nt_pr[prim[j]*i]=1;//ɸ��
            if(i%prim[j]==0)break;//���������С����һ��С�ڵ���prim[j]
        }
    }
}

//ɸ����С������ 
const int N=5e5;
int prim[N/5],prime_n,midiv[N+5]; 
void prime(){
    for(int i=2;i<=N;i++){
        if(!midiv[i])prim[prime_n++]=i,midiv[i]=i;//û��ɸ����Ϊ����
        for(int j=0;j<prime_n&&i*prim[j]<=N;j++){
            midiv[prim[j]*i]=prim[j];//ɸ��
            if(i%prim[j]==0)break;//���������С����һ��С�ڵ���prim[j]
        }
    }
}
