inline int maxbit(int data[], int n){//����data�������������ĳ��� 
    int d=1,p(10); //d��������λ��
    for(int i=0;i<n;i++){
        while(data[i]>=p||-data[i]>=p){
            p=(p+(p<<2))<<1,d++;
        }
    }
    return d;
}
inline void radixsort(int data[], int n){//dataΪԭʼ����Ҳ�ǽ�����飬nΪ���鳤�� 
    int d=maxbit(data,n),tmp[n];//dΪ�������������ĳ���
    int count[20]; //������    ��Ϊ�и��������Կ���20�� 
    int radix = 1;
    for(int i=0;i<d;i++){ //����d������
        for(int j=1;j<20;j++)
            count[j]=0; //ÿ�η���ǰ��ռ�����
        for(int j=0,k;j<n;j++){//ͳ��ÿ��Ͱ�еļ�¼��
            k=(data[j]/radix) % 10+10;//��Ϊ�и�������+10 
            count[k]++;
        }
        for(int j=2;j<20;j++)
            count[j]=count[j-1]+count[j]; //��tmp�е�λ�����η����ÿ��Ͱ,count[j]Ϊ��j��Ͱ�Ľ���λ�� 
        for(int j=n-1,k;j>=0; j--){ //������Ͱ�м�¼�����ռ���tmp��
			k = (data[j] / radix) % 10+10; //ͳ��ÿ��Ͱ�еļ�¼��
            tmp[count[k]-1]=data[j];
            count[k]--;
        }
        memcpy(data,tmp,n*4);//����ʱ��������ݸ��Ƶ�data��
        radix=(radix+(radix<<2))<<1;
    }
}
int a[] = {1, 1, 10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
inline int getdigit(int x,int d){//����int����λ 
    return ((x/a[d])%10)+10;//����Ͱ��
}
void msd_radixsort(int arr[],int begin,int end,int d){//�ֱ�ΪҪ��������飬��ʼ�ͽ���λ�ã�������ݳ��� 
	const int radix = 21;//��Ϊ������Ͱʱ��Ҫ��һ��Ͱ�ı߽����������Զ࿪һ��Ͱ 
	int count[radix], i, j; 
	//��ʼ�� 
	memset(count,0,sizeof(count));
	//����Ͱ�洢�ռ�
	int *bucket = (int *) malloc((end-begin+1) * sizeof(int));
	//ͳ�Ƹ�Ͱ��Ҫװ��Ԫ�صĸ���  
	for(i = begin;i <= end; ++i){
		count[getdigit(arr[i], d)]++;
	}
	//���Ͱ�ı߽�������count[i]ֵΪ��i��Ͱ���ұ߽�����+1
	for(i = 1; i < radix; ++i)   {
		count[i] = count[i] + count[i-1];    
	}
	//����Ҫ��������ɨ�裬��֤�����ȶ��� 
	for(i = end;i >= begin; --i){
		j = getdigit(arr[i], d);		//����ؼ���ĵ�dλ�����֣� ���磺576�ĵ�3λ��5   
		bucket[count[j]-1] = arr[i];	//�����Ӧ��Ͱ�У�count[j]-1�ǵ�j��Ͱ���ұ߽�����   
		--count[j];						//��j��Ͱ����һ��Ԫ�ص�λ��(�ұ߽�����+1)   
	}
	//ע�⣺��ʱcount[i]Ϊ��i��Ͱ��߽�
	//�Ӹ���Ͱ���ռ�����  
	for(i = begin, j = 0;i <= end; ++i, ++j){
		arr[i] = bucket[j];
	}    
	//�ͷŴ洢�ռ�
	free(bucket);   
	//�Ը�����Ͱ�����ݽ���������
	for(i = 1;i < radix-1; i++){
		int p1 = begin + count[i];			//��i��Ͱ����߽�
		int p2 = begin + count[i+1]-1;		//��i��Ͱ���ұ߽�   
		if(p1 < p2 && d > 1){
			msd_radixsort(arr, p1, p2, d-1);//�Ե�i��Ͱ�ݹ���ã����л���������λ�� 1    
		}
	}
}
