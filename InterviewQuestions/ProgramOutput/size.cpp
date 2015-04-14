#include <stdint.h>
#include <stdio.h>

/*
 * 下面代码在64位Linux系统编译执行，输出结果是
 */
void print_size(int32_t array[10])
{
    printf("%d\n", sizeof(array));
}

int main()
{
    int32_t myArray[10];
    printf("%d ", sizeof(myArray));
    print_size(myArray);
}
