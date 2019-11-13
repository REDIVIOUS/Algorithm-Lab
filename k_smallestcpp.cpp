#include <iostream>
using namespace std;

void k_smallest(int a[], int left, int right, int k){ //left��right�ֱ�Ϊ��ǰ��ѯ������½���Ͻ磬��ѯ��kС��Ԫ�� 
	//�ڿӷ�ʵ�� 
	int i=left,j=right;
	int pivot=a[j]; //��һ��������Ϊ���һ��Ԫ�� 
	while(i<j){
		while(i<j&&a[i]<=pivot){ //��߿�ʼѰ�ұ�pivot��������н��� 
			i++; 
		}
		a[j]=a[i];
		while(i<j&&a[j]>=pivot){ //�ұ߿�ʼѰ�ұ�pivotС�������н��� 
			j--;
		}
		a[i]=a[j];
	}
	a[i]=pivot; //pivot���� 
	if(i>k-1){
		k_smallest(a,left,i-1,k); //����߼������� 
	}
	else if(i<k-1){
		k_smallest(a,i+1,right,k); //���ұ߼�������  
	}
	else{
		cout<<"The k-smallest number is: "<<a[i]<<endl;
		return ;
	}
}

int main(){
	int k,n;  //ҪѰ�ҵ����k,���鳤��n
	cin>>k>>n;  //�������k������n 
	int a[n]; //Ҫ���ҵ�����a
	for(int i=0;i<n;i++){ //��������a[]
		cin>>a[i]; 
	}
	if(k>n){ //��ҪѰ�ҵ���Ҫ���������С������ 
		cout<<"the k-smallest number does not exist!"<<endl;
		return 0;
	}
	k_smallest(a,0,n-1,k); //���ú���Ѱ�ҵ�kС����
	return 0;
} 
