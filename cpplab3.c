#include <iostream>
using namespace std;
int allcomb(int *mas, int n, int a, int b, int *sum1, int *sum2,int k) {for (int i=n-1;i>=0;i--,mas--) {if (i>k){
	if (a-b-*mas==0) {*sum1+=a; *sum2+=*mas+b;*mas=0; return 0;} 
	if ((abs(a-(b+*mas))<=abs(a-b))&&(a!=b+*mas)) {*sum2+=*mas; *mas=0;} 
	else {*sum1+=a; *sum2+=b; return 0;}}
	else {*sum1+=a;*sum2+=b;return 0;}}
	return 0;}
int main() {
	int n,sum1=0,sum2=0,tmp,sum=0, ost=0; cin >>n;int mas[n];bool per=true; for (int i=0;i<n;i++) {cin >>mas[i];sum+=mas[i];cout <<mas[i]<<" ";}
	while (per) {per=false; for (int i=0;i<n-1;i++) {if (mas[i]<mas[i+1]) {tmp=mas[i];mas[i]=mas[i+1]; mas[i+1]=tmp;per=true;}}}
	for (int i=0;i<=n-2;i+=2) {if (sum==sum1+sum2) {break;} else {if (mas[i]==mas[i+1]) {sum1+=mas[i];sum2+=mas[i+1];} else {allcomb(&mas[n-1],n,mas[i],mas[i+1],&sum1,&sum2,i+1);mas[i]=0;mas[i+1]=0;}}}
	for (int i=0;i<n;i++) {if (mas[i]!=0) {ost+=mas[i];}}
	cout <<endl<<"Минимальная разница между тарелками = "<<abs(sum1-sum2-ost)<<endl;
}
