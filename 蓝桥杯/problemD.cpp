#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
 
using namespace std;
typedef long long ll;
const int maxn = 100;

char arra[maxn];
char arrb[maxn];
char arrc[maxn];
char arrd[maxn];

char ans[maxn];

// lena > lenb
void BigAdd(char a[], char b[],char ans[]){
	int lena = strlen(a);
	int lenb = strlen(b);
	
	int i = 0;
	int c = 0;
	
	while(i < min(lena,lenb))
	{
		int tmp = a[i] + b[i] - '0' - '0' + c;
		if(tmp > 9)
		{
			ans[i] = tmp % 10;
			c = tmp / 10;
		}
		else
		{
			ans[i] = tmp;
			c = 0;
		}
		i++;
	}
	
	while(i < lena){
		int tmp = a[i] + c - '0';
		if(tmp > 9)
		{
			ans[i] = tmp % 10;
			c = tmp / 10;
		}
		else
		{
			ans[i] = tmp;
			c = 0;
		}
		i++;
	}
	
	while(i < lenb){
		int tmp = b[i] + c - '0';
		if(tmp > 9){
			a[i] = tmp % 10;
			c = tmp /= 10;
		}
		else
		{
			ans[i] = tmp;
			c = 0;
		}
		i++;
	}
}

//void BigAdd(char* a,char* b,char* c)
//{
//    int i,j,k,lena,lenb,temp;
//    char *s,*plena,*plenb;
//    lena=strlen(a);
//    lenb=strlen(b);
//    
//    if (lena<lenb)
//    {
//        temp=lena;
//        lena=lenb;
//        lenb=temp;
//        plena=b;
//        plenb=a;
//    }
//    else
//    {
//        plena=a;
//        plenb=b;
//    }
//    s=(char*)malloc(sizeof(char)*(lena+1));
//    s[0]='0';
//    for (i=lenb-1,j=lena-1,k=lena;i>=0;i--,j--,k--)
//        s[k]=plenb[i]-'0'+plena[j];
//       for (;j>=0;j--,k--)
//           s[k]=plena[j];
//    for (i=lena;i>=0;i--)
//        if (s[i]>'9')
//        {
//            s[i]-=10;
//            s[i-1]++;
//        }
//    if (s[0]=='0')
//    {
//        for (i=0;i<=lena;i++)
//           c[i-1]=s[i];
//           c[i-1]='\0';
//    }
//    else
//    {
//        for (i=0;i<=lena;i++)
//           c[i]=s[i];
//           c[i]='\0';
//    }
//}

int main(){
	int T;
	cin >> T;
	while(T--){
		scanf("%s",arra);scanf("%s",arrb);
		scanf("%s",arrc);scanf("%s",arrd);
		
		BigAdd(arra,arrb,ans);
		BigAdd(arrc,ans,ans);
		BigAdd(arrd,ans,ans);
		
		cout << ans << endl;
	}
	
	return 0;
}
