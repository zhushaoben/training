int prim[50000],prime_n; 
bool is_pr[500000]={1,1};
void prime(){
    int m=500000;
    for(int i=2;i<m;i++){
        if(!is_pr[i])prim[prime_n++]=i;//û��ɸ����Ϊ����
        for(int j=0;j<prime_n&&i*prim[j]<m;j++){
            is_pr[prim[j]*i]=1;//ɸ��
            if(i%prim[j]==0)break;//���������С����һ��С�ڵ���prim[j]
        }
    }
}

