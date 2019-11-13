#include <iostream>
#include <utility>
#define INF 100000
#define N 6
using namespace std;

int opt[N][N], record[N][N]; //opt�����Ž����record�����ڼ�¼����λ��
pair<int, int> p0[N]; //��¼ÿ������Ĵ�С
int p[N+1]; //�洢�����С����

void opt_generate(int p[N+1], int opt[N][N], int record[N][N]){
	for(int i=0;i<N;i++){
		opt[i][i]=0; //�Խ��߿�����0 
	}
	for(int i=0;i<N;i++){
		record[i][i]=i; //ÿ��Ԫ�ؿ�ʼʱ����Ϊ�Լ� 
	} 
	/*��б�߷���������Ž����*/
	for(int i=1;i<N;i++){  //i������б�Խ��ߵľ��� 
		for(int j=0;j<N-i;j++){ //j����ǰ�����ο�ʼ��������� 
			int z=j+i; //z������Ϊiʱ�������ν��������� 
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
void print(int record[N][N], int i,int j){
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
	for(int i=0;i<N;i++){
		cin>>p0[i].first;
		cin>>p0[i].second;
	}
	
	//������벻�Ϸ����㱨���� 
	for(int i=1;i<N;i++){
		if(p0[i].first!=p0[i-1].second){
			cout<<"This matrix can not multiplication."<<endl;
			return 0;
		}
	} 
	
	//���ɾ����С���� 
	for(int i=0;i<N;i++){
		p[i]=p0[i].first; 
	}
	p[N]=p0[N-1].second;
	
	opt_generate(p,opt,record);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<opt[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;j++){
			cout<<record[i][j]<<" "; 
		}
		cout<<endl; 
	}
	cout<<endl;
	print(record,0,N-1);
	return 0;
} 

