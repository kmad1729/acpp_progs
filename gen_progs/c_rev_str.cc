#include <cstdio>
#include <cstring>

//reverse a string
void reverse(char *s)
{
    size_t len = strlen(s);
    size_t mid = len / 2;
    for(size_t i = 0; i < mid; i++) {
        char tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++) {
        printf("reverse of (%s) --> ", argv[i]);
        reverse(argv[i]);
        printf("(%s)\n", argv[i]);
    }
}
