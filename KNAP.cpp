#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int M; //����������
	int n; //��Ʒ�ļ���
	cin>>n>>M;
	
	int w[n+5],p[n+5]; //ÿ����Ʒ������w[i],��ֵp[i]
	int KNAP[n+5][M+5]; //ǰi����Ʒװ��j����������ֵ 
	
	for(int i=1;i<=n;i++){ //������Ʒ���� 
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){ //������Ʒ��ֵ 
		cin>>p[i];
	}
	
	for(int j=0;j<=M;j++){ //��ʼ���߽�������ǰ0����Ʒ����ֵΪ0 
		KNAP[0][j]=0; 
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=M;j++){
			if(w[i]>j){ //�����������������i����Ʒ����һ����װ�� 
				KNAP[i][j]=KNAP[i-1][j]; 
			}
			else{  //����ѡ���Ƿ�װ��i����Ʒ  
			KNAP[i][j]=max(KNAP[i-1][j],KNAP[i-1][j-w[i]]+p[i]); 
			} 
		} 
	} 

	cout<<"������װ�������ֵΪ��"<<KNAP[n][M]; 
	return 0; 
}
