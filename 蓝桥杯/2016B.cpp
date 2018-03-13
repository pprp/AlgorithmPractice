#include <iostream>
#include <cstring>
#include <string>
 
using namespace std;

int a[9] = {1,2,3,4,5,6,7,8,9}; 

int main()
{
	int sum = 0;
	for(int a = 1; a <= 9 ; a++){
		for(int b = 1; b <= 9 ; b++){
			if(a == b)continue;
			for(int c = 1; c <= 9 ; c++){
				if(c == a || c == b)continue;
				for(int d = 1; c <= 9 ; d++){
					if(d == a || d == b || d == c)continue;
					for(int e = 1; e <= 9 ; e++){
						if(e == a || e == b || e == c || e == d)continue;
						for(int f = 1; f <= 9 ; f++){
							if(f == a||f == b || f == c || f == d || f == e)continue;
							for(int g = 1; g <= 9; g++){
								if(g == a || g == b || g == c || g == d || g == e || g == f)continue;
								for(int h = 1; h <= 9 ;h++){
									if(h == a || h == b || h == c || h == d || h == e || h == f || h == g)continue;
									for(int i = 1; i <= 9 ; i++){
										if(i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h)continue;
										
										int def = f+e*10+d*100;
										int ghi = i+h*10+g*100;
										
										if(a + b/c + def/ghi == 10)
										{
											sum++;
										}
									}
								}			
							}					
						}
					}
				}
			} 
		}		
	}
	cout << sum << endl;
	
	
	return 0;
}
