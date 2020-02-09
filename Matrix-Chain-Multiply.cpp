#include <iostream>
#include <utility>
#define INF 100000
using namespace std;

int N;
int opt[1000][1000], record[1000][1000]; //opt�����Ž����record�����ڼ�¼����λ��
pair<int, int> p0[1000]; //��¼ÿ������Ĵ�С
int p[1000]; //�洢�����С����

void opt_generate(int p[1000], int opt[1000][1000], int record[1000][1000], int N){
	for(int i=0;i<N;i++){
		opt[i][i]=0; //�Խ��߿�����0 
	}
	for(int i=0;i<N;i++){
		record[i][i]=i; //ÿ��Ԫ�ؿ�ʼʱ����Ϊ�Լ����߽����������Ϊ1������� 
	} 
	/*�������Ž����*/
	for(int i=2;i<=N;i++){  //i����ǰ������ľ������ĳ��� 
		for(int j=0;j<=N-i;j++){ //j����ǰ����ʼ�ĺ����� 
			int z=j+i-1; //z����ǰ�������ĺ����� 
			opt[j][z]=INF; //��ʼֵΪ�����
			for(int k=j;k<z;k++){ //ѡ��ϵ�k��Ѱ�����Ž� 
				int opt_t=opt[j][k]+opt[k+1][z]+p[j]*p[k+1]*p[z+1];
				if(opt_t<opt[j][z]){
					opt[j][z]=opt_t;
					record[j][z]=k;	 //����ϵ�k
				} 
			} 
		} 
	} 
}

//��ӡ���������� 
void print(int record[1000][1000], int i,int j){
	if(i==j){
		cout<<"A"<<i;
	} 
	else{
		cout<<"(";
		print(record,i,record[i][j]); //���Ѱ�� 
		print(record,record[i][j]+1,j); //�ұ�Ѱ�� 
		cout<<")";
	}
}


int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>p0[i].first;
		cin>>p0[i].second;
	}
	
	//������벻�Ϸ����㱨���� 
	for(int i=1;i<N;i++){
		if(p0[i].first!=p0[i-1].second){
			cout<<"This matrix can not multiply."<<endl;
			return 0;
		}
	} 
	
	//���ɾ����С���� 
	for(int i=0;i<N;i++){
		p[i]=p0[i].first; 
	}
	p[N]=p0[N-1].second;
	
	opt_generate(p,opt,record,N);

	cout<<"����Ҫ���еĳ˷�����Ϊ��"<<opt[0][N-1]<<"��"<<endl; 
	print(record,0,N-1);
	return 0;
} 


