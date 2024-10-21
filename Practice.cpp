#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void runtime(int *hour, int *minute, int *second)
{
    while (1)
    {
        (*second)++;

        if(*second == 60)
        {
            (*minute) ++;
            *second = 0;
        }

        if(*minute == 60)
        {
            (*hour) ++;
            *minute = 0;
        }

        if(*hour == 24)
        {
            *hour = 0;
        }

        if(char *stop == "stop")
        {
            break;
        }

        // 현재 시간 출력 (줄바꿈 추가)
        printf("%02d시 : %02d분 : %02d초\n", *hour, *minute, *second);

        // 1초 대기
        sleep(1);
    }
}

int main()
{
    // 시간, 분, 초 변수 선언
    int hour = 0, minute = 0, second = 0;

    // 포인터로 시간, 분, 초를 runtime 함수에 전달
    runtime(&hour, &minute, &second);
    return 0;
}
