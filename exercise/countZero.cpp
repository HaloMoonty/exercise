#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int countZreo(int N)
{
    int count = 0;
    for(int i = 1;i <= N;i++)
    {
        int j = i;
        while(j % 5 == 0)
        {
            count++;
            j /= 5;

        }

    }
    return count;

}
int main()
{
    int n;
    scanf("%d",&n);
    int a = countZreo(n);
    cout<<a<<endl;

}

