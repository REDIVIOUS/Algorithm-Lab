#include <iostream>
#include <algorithm>
#define Vmax 1000
#define Emax 500000
using namespace std;

struct edge{
	int u,v,w;  //u:һ���˵㣻v:��һ���˵㣻w:��Ȩ 
}E[Emax];

bool cmp(edge a,edge b){
	return a.w<b.w;  //�߰��մ�С�������� 
}

int m,n; //m:�ߵ�������n:��ĸ��� 
int sum,edgenum; //sum:��Ȩ�ͣ�edgenum:�Ѿ������ıߵ����� 

//���ò��鼯ʵ��findroot����
int root[Vmax];
int findroot(int v){
	if(v==root[v]){  //�ҵ��˸��ڵ� 
		return v;
	}
	//·��ѹ�� 
	else{
		int Root=findroot(root[v]); //Ѱ����һ���ĸ��ڵ� 
		root[v]=Root;  //����·�����нڵ������ڵ� 
		return Root;
	}
}

//ʵ��unionroot����(���ڱ��Ϊi�ı�)
int unionroot(int i){
	int uroot=findroot(E[i].u);
	int vroot=findroot(E[i].v);
	if(uroot!=vroot){
		root[uroot]=vroot;
		sum=sum+E[i].w;
		edgenum=edgenum+1;
	}
} 

int main(){
	//����������������ߵ���Ϣ 
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	
	for(int i=0;i<n;i++){ //��ʼ�����鼯
		root[i]=i;
	}
	
	sort(E,E+m,cmp); //�ߴ�С��������
	
	for(int i=0;i<m;i++){ //�����ߣ����кϲ����� 
		unionroot(i);
		if(edgenum==n-1){  //�ߵ������Ѿ��ﵽn-1 
			break;
		} 
	}
	if(edgenum!=n-1){  //��ͼ����ͨ 
		cout<<"MST does not exist!"<<endl;
	}
	else{
		cout<<"the minimum sum of weights is��"<<sum<<endl;
	}
	return 0;
}

 
