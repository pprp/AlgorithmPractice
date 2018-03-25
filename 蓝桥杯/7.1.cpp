#include <bits/stdc++.h>

using namespace std;

bool isDigital(char a){
  if(a >= '0' && a<= '9')return true;
  return false;
}

int main(){
  char a[1000];
  char b[1000];
  string tmp;
  cin >> a >> b;
  getline(cin,tmp);

  int lena = strlen(a);
  int lenb = strlen(b);

  bool taga = false;
  bool tagb = false;

  for(int i = 0 ; i < lena ; i++){
    if(!isDigital(a[i])){
      taga = true;
      break;
    }
  }
  if(taga)
  {
    cout << "? + ";
  }
  else
  {
    cout << a << " + ";
  }
  for(int i = 0 ; i < lenb; i++){
    if(!isDigital(b[i])){
      tagb = true;
      break;
    }
  }
  if(tagb){
    cout << "? = ";
  }else
  {
    cout << b << " = ";
  }

  if(!taga && !tagb){
    int numa=0;
    int numb=0;
    for(int i = lena-1 ; i >= 0; i--){
      numa += (int)(a[i]-'0') * pow(10,(lena-i-1));
    }
    for(int i = lenb-1 ; i >= 0; i--){
      numb += (int)(b[i]-'0') * pow(10,(lenb-i-1));
    }
    cout << numa+numb << endl;
    // cout << "test :: a:" << numa << " b:" << numb << endl;
  }else
  {
    cout << "?" << endl;
  }


  return 0;
}
