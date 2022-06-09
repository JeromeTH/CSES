#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    
    int two, five = 0;
    for(int i = 1; i <= n; i++){
        
        while (i % 5 == 0){
            five ++;
            i /= 5;
        }
        while (i % 2 == 0){
            two ++;
            i /= 2;
        }
    }
    printf("%d", max(five, two));
}