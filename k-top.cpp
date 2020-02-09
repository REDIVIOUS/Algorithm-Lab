#include <iostream>
#include <algorithm>
using namespace std;

int GetMid(int a[],int start,int end){ //�������a��start��endλ���ϵ���λ�����±� 
	sort(a+start,a+end+1); //start��end����
	int temp=start+end;
	int mid=(temp/2)+(temp%2); //ȡ��λ�����±�
	return mid; 
}

int GetMidPivot(int a[],int start, int end){ //������a���֣������λ������λ�����±� 
	int len=end-start+1;
	int group=len/5+(len%5==0?0:1); //�������������5������5������ 
	int pivot[group]; //�洢ÿһ����λ�����±� 
	for(int k=0;k<group;k++){
		int i=start+k*5,w=i+4,j=min((i+4),end);
		pivot[k]=GetMid(a,i,j); //���ÿһ�����λ���±� 
	}
	int index=GetMid(pivot,0,group-1); //ȡ��λ���±��������λ�����±� 
	return pivot[index];
}

void bfqrt(int a[],int left,int right, int k){ //�������� 
	//�ڿӷ�ʵ�� 
	int i=left,j=right;
	int pivot_index=GetMidPivot(a,left,right); //����λ������λ�����±�
	int pivot=a[pivot_index];
	swap(a[pivot_index],a[right]); //����׼ֵ��������ĩβ 
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
	a[i]=pivot;
	if(i>k-1){
		bfqrt(a,left,i-1,k); //����߼������� 
	}
	else if(i<k-1){
		bfqrt(a,i+1,right,k); //���ұ߼������� 
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
	bfqrt(a,0,n-1,k); //���ú���Ѱ�ҵ�kС����
	return 0;
}
