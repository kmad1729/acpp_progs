#include <cstdio>
#include <cctype>
#define MAX_STR_LEN 1000

void transform_string(char *s) {
    int num_spaces = 0;
    char *orig_end = s;
    while(*orig_end != '\0') {
        if(isspace(*orig_end++))
            num_spaces++;
    }
    char *new_end = orig_end + (2 * num_spaces);

    *new_end = '\0';
    new_end--;
    orig_end--;

    while(new_end > s) {
        if(isspace(*orig_end)) {
            *new_end-- = '0';
            *new_end-- = '2';
            *new_end-- = '%';
            orig_end--;
        } else
            *new_end-- = *orig_end--;
    }
}

void print_transform_string(char *test_str1)
{
    printf("str = \"%s\"\n", test_str1);
    transform_string(test_str1);
    printf("tranformed str = \"%s\"\n", test_str1);
    for(int i = 0; i < 10; i++,putchar('*'));
    putchar('\n');
}

int main()
{
    char test_str1[MAX_STR_LEN] = "a  b   c    d";
    print_transform_string(test_str1);
    char test_str2[MAX_STR_LEN] = "   ";
    print_transform_string(test_str2);
    char test_str3[MAX_STR_LEN] = "a   ";
    print_transform_string(test_str3);
    char test_str4[MAX_STR_LEN] = "";
    print_transform_string(test_str4);
    char test_str5[MAX_STR_LEN] = " ";
    print_transform_string(test_str5);
}
