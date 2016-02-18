#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    int t,l;
    char a[22];
    a[0]='0';
    for(t=1;t<=20;t++)
    {
        l=1;
        //scanf("%s",a+1);
        fgets(a, sizeof(a), stdin);
        printf("(%s)\n", a + 1);

        if(strlen(a)>1)
            l=strlen(a);
        printf("%d\n",l-1);
    }
     return 0;
}
