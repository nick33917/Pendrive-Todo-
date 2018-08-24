#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    SYSTEMTIME fecha;
    GetLocalTime(&fecha);
    printf("%d %d %d",fecha.wHour,fecha.wMinute,fecha.wSecond);
   // printf("Hello world!\n");
    return 0;
}
