#include <iostream>
#include <cstdint>
using namespace std;
int minras(int mas[],int n, int sum1,int sum2, int i) {
	if (i==n) {return abs(sum1-sum2);}
	else {
		int mash=minras(mas,n,sum1+mas[i],sum2,i+1);
		int pet=minras(mas,n,sum1,sum2+mas[i],i+1);
		return mash>pet?pet:mash;}}
int main() {
	int n,beg; 
	cout <<"Введите количество чашек:"; cin >>n;  
	if ((n>0)&&(n<=32)) {
		cout <<"Введите начальное число для рандомайзера:"; cin >>beg; 
        	srand(beg); int mas[n];
		for (int i=0;i<n;i++) {mas[i]=rand()%1000;cout <<mas[i]<<" ";}
		cout <<endl<<"Минимальная разница:"<<minras(mas,n,0,0,0)<<endl;}
	else {cout <<"Ошибка! Введите другое число."<<endl;}
	return 0;
	}
