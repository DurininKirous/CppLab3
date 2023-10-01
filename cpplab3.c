#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string sochet(int mas[], int n, int a, int k) {
	int kolel=1;int minras=10000000; string minrasind; for (int i=0;i<n;i++) {kolel*=(i+1);}
	int masnew[kolel], *ptr=&masnew[1]; string masnewind[kolel]; string *ptr1=&masnewind[1]; masnew[0]=mas[0]; masnewind[0]={to_string(mas[0])};
	for (int j=n-1;j>=k;j--) {
		if (mas[j]>a) {break;}
		else if (mas[j]==a) {return to_string(mas[j]);}	
		else {for (int i=1;i<kolel;i++) {
			if (masnew[i]!=0) {*ptr=masnew[j]+mas[i]; *ptr1={to_string(*ptr)+" "+to_string(mas[i])};
				if (*ptr==a) {return *ptr1;} 
				if (abs(a-*ptr)<minras) {minras=abs(a-*ptr);minrasind={*ptr1};} ptr+=1;ptr1+=1;} 
				*ptr=mas[i]; *ptr1={to_string(mas[i])};
				if (*ptr==a) {return *ptr1;}  
				if (abs(a-*ptr)<minras) {minras=abs(a-*ptr); minrasind={*ptr1};}  ptr+=1;ptr1+=1;}}} 
	return minrasind ;}
int main() {
	int n,sum1=0,sum2=0,sum=0,tmp; cin >>n;int mas[n];bool per=true; for (int i=0;i<n;i++) {cin >>mas[i];sum+=mas[i];cout <<mas[i]<<" ";}
	while (per) {
		per=false; 
		for (int i=0;i<n-1;i++) {
			if (mas[i]<mas[i+1]) {tmp=mas[i];mas[i]=mas[i+1]; mas[i+1]=tmp;per=true;}}}
	for (int i=0;i<=n-2;i+=2) {
		if (sum==sum1+sum2) {break;} 
		else {
			if (mas[i]==mas[i+1]) {sum1+=mas[i];sum2+=mas[i+1];} 
			else {
				string comb={sochet(mas,n,mas[i]-mas[i+1],i+1)};
		       		char *token; *token=*strtok((char) *comb, " "));
				sum2+=*token;
				mas[*(find(mas,mas+n,*token))]=0;
				while (*token!=NULL) {
					token=(strtok(NULL," "));
					sum2+=*token;
					mas[*(find(mas,mas+n,*token))]=0;
					}
				sum2+=mas[i];}}}
	cout <<endl<<"Минимальная разница между тарелками = "<<abs(sum1-sum2)<<endl;
}
