#include <iostream>

using namespace std;

const int N = 10000;
int fib[N];


void createFIB(){
    fib[0] = 0;
    fib[1] = fib[2] = 1;
    for(int i = 3; i < N ; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
}

bool isFIB(int nn){
    for(int i = 0 ; i < N ; i++){
        if(nn == fib[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    createFIB();
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        if(isFIB(i))
            cout << 'O';
        else
            cout << 'o';
    }
    cout << endl;
    return 0;
}
