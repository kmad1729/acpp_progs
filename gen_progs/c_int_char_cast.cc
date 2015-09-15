#include <cstdio>

void print_delim()
{
    for(int i = 0; i < 10; putchar('*'),i++);
    printf("\n");
}

void print_ints_into_bytes(int i)
{
    printf("i = %d\n",i);
    printf("i = %x\n",i);
    unsigned char *c = (unsigned char *)&i;
    
    for(unsigned ind = 0; ind < sizeof(int); ind++) {
        printf("c[%u] --> %d\n", ind, c[ind]);
    }
    print_delim();
}


int main()
{
    print_ints_into_bytes(077);
    print_ints_into_bytes(0xfff);
    print_ints_into_bytes(0xff);
    print_ints_into_bytes(0xfff1f);

    printf("printing 127 as char %d\n", 127);
    print_delim();
    printf("printing 127 as u char %u\n", 127);
    print_delim();

    char c = 255;
    printf("printing %d as char %d\n", c, c);
    print_delim();
    printf("printing %d as u char %u\n", c, c);
    print_delim();

}
