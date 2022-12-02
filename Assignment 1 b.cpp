#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){
return a>b?a:b;
}
void knapsack(int cap,int wt[],int pr[],int n){
	int i, j;
	int K[n + 1][cap+ 1];
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= cap; j++) {
			if (i == 0 || j == 0)
				K[i][j] = 0;
			else if (wt[i] <= j)
				K[i][j] = max(pr[i] + K[i - 1][j - wt[i]], K[i - 1][j]);
			else
				K[i][j] = K[i - 1][j];
		}
	}
	cout<<"======================================="<<endl;
	int res = K[n][cap];
	cout<< "Maximum Profit : "<<res << endl;
	j = cap;
	i = n;
	cout<<"Product Selected are : ";
	for (i = n; i > 0 && res > 0; i--) {
		if (res == K[i - 1][j])
			continue;
		else {
			cout<<wt[i - 1]<<" " ;
			res = res - pr[i];
			j = j - wt[i];
		}
	}
	cout<<endl;
	cout<<"======================================="<<endl;
}
int main(){
	int n;
	cout<<"ENTER THE NUMBER OF PRODUCT : ";
	cin>>n;
	int cap;
	cout<<"ENTER THE CAPACITY OF PRODUCT : ";
	cin>>cap;
		int wt[n];
	for(int i=0;i<n;i++){
		cout<<"Enter Weight "<<i+1<<":";
		cin>>wt[i];
	}
	int pr[n];
	for(int i=0;i<n;i++){
		cout<<"Enter Profit "<<i+1<<": ";
		cin>>pr[i];
	}
	cout<<endl;
	cout<<"========================================";
	cout<<endl;
	cout<<"WEIGHT OF PRODUCT : ";
	for(int i=0;i<n;i++)
		cout<<wt[i]<<" ";
	cout<<endl;
	cout<<"PROFIT OF PRODUCT : ";
	for(int i=0;i<n;i++)
		cout<<pr[i]<<" ";
	cout<<endl;
	cout<<"========================================";
	cout<<endl;
	cout<<endl;
	knapsack(cap,wt,pr,n);
	return 0;
}
/*
ENTER THE NUMBER OF PRODUCT : 3
ENTER THE CAPACITY OF PRODUCT : 50
Enter Weight 1:10
Enter Weight 2:20
Enter Weight 3:30
Enter Profit 1: 60
Enter Profit 2: 100
Enter Profit 3: 120

========================================
WEIGHT OF PRODUCT : 10 20 30
PROFIT OF PRODUCT : 60 100 120
========================================

Maximum Profit : 220
Product Selected are : 20 10
*/
