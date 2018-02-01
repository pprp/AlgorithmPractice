#include <iostream>
#include <string>

using namespace std;

const int N = 100000;

struct ipAdd{
    string name;
    string ip;
};

ipAdd ia[N];

string SearchByIp(string ip,int nn){
    for(int i = 0 ; i < nn; i++){
        if(ia[i].ip == ip)
            return ia[i].name;
    }
    return "";
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    string tmpip;
    for(int i = 0 ; i < n ; i++){
        cin >> ia[i].name;
        cin >> ia[i].ip;
    }
    for(int i = 0 ; i < m ; i++){
        string cmd;
        cin >> cmd;
        cin >> tmpip;
//        int len = tmpip.length();
//        tmpip[len] = '\0';
        tmpip.pop_back();
        string ans = SearchByIp(tmpip,n);
        cout << cmd << " " << tmpip << ";" << " #" << ans << endl;
    }


    return 0;
}
