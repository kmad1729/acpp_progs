#include <cstdio>
#include <cassert>
#include <climits>
#include <cstring>

int atoi (const char* str)
{
    size_t len = strlen(str);
    assert(len > 0);

    int result = 0, new_result = 0;
    int multiplier = str[0] == '-'? -1 : 1;
    int counter_limit = multiplier == -1? 1:0;
    
    for(int counter = counter_limit; counter < len; counter++) {
        new_result = (result * 10) + (str[counter] - '0');

        if(multiplier == 1) {
            if(new_result < result) {
                printf("cannot fit int!!\n");
                assert(0);
            }
        } else {
            if(multiplier * new_result > multiplier * result) {
                printf("cannot fit int!!\n");
                assert(0);
            }
        }
        result = new_result;
    }

    return multiplier * result;
}

int main()
{
    /*
    printf("%s + 1 = %d\n", "1111", atoi("1111") + 1);
    printf("%s + 1 = %d\n", "-1111", atoi("-1111") + 1);
    printf("INT_MAX = %d INT_MIN = %d\n", INT_MAX, INT_MIN);
    printf("%s + 1 = %d\n", "-11111111", atoi("-11111111") + 1);
    printf("%s + 1 = %d\n", "1111", atoi("1111") + 1);
    */
    printf("atoi(\"147483647\") = %d\n", atoi("147483647"));
    printf("atoi(\"-147483647\") = %d\n", atoi("-147483647"));
    printf("atoi(\"2147483647\" = %d\n", atoi("2147483647"));
    printf("atoi(\"-2147483648\" = %d\n", atoi("-2147483648"));
    printf("atoi(\"-2147483649\" = %d\n", atoi("-2147483649"));
}
