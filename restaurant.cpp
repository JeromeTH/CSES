#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int s[6];
    for (int i = 0; i < 5; i++){
        scanf("%d\n", &s[i]);
    }
    int lag[6] = {0};
    int maxlag = 0;
    for(int i = 0; i < 5; i++){
        lag[i] = (10 - (s[i] % 10)) % 10;
        if (maxlag < lag[i]){
            maxlag = lag[i];
        }
    }
    int count = 0;
    for (int i = 0; i < 5 ; i++){
        count += s[i];
        count += lag[i];
    }
    count -= maxlag;
    printf("%d", count);
}