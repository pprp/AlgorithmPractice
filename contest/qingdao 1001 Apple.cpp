#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
const double eps = 1e-8;
double x1,y11,x2,y2,x3,y3;
double x00,y00;
double px,py;

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int cas;
    cin >> cas;
    while(cas--)
    {
        cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3 >> px >> py;

        double a = x1 - x2;
        double b = y11 - y2;
        double c = x1 - x3;
        double d = y11 - y3;
        double e = ((x1 * x1 - x2 * x2) - (y2*y2-y11*y11))/2.0;
        double f = ((x1*x1-x3*x3)*(y3*y3-y11*y11))/2.0;
        double det = b * c - a * d;

        x00 = -(d * e - b * f) / det;
        y00 = -(a * f - c * e) / det;

        double radius = sqrt((x1-x00)*(x1-x00)+(y11-y00)*(y11-y00));
        double dis = sqrt((px-x00)*(px-x00)+(py-y00)*(py-y00));

        if(dis - radius <= eps)
            cout << "Rejected" << endl;
        else
            cout <<"Accepted" << endl;
    }
    return 0;
}
