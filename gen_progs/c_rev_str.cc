#include <cstdio>

//reverse a string
void reverse(char *s)
{
    char *end =s;
    while(*end != '\0') end++;
    end--;
    while(s < end) {
        char tmp = *s;
        *s++ = *end;
        *end-- = tmp;
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
