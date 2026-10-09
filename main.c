
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    time_t Time = 0;
    struct tm *pTime = NULL;
    bool isRunning = true;
    bool firstRun = true;

    printf("========================================\n");
    printf("             DIGITAL CLOCK              \n");
    printf("========================================\n");

    while (isRunning){
        time(&Time);
        pTime = localtime(&Time);
        if (pTime == NULL)
        {printf("Unable to get current date and time.\n");
            return 1;}

        if (!firstRun)//prevents the cursor from moving up during the first iteration
        {
            printf("\033[2A");
        }

        printf("\033[2K");
        printf("CURRENT DATE: %04d-%02d-%02d\n",
               pTime->tm_year + 1900,
               pTime->tm_mon + 1,
               pTime->tm_mday);

        printf("\033[2K");
        printf("CURRENT TIME: %02d:%02d:%02d\n",
               pTime->tm_hour,
               pTime->tm_min,
               pTime->tm_sec);

        fflush(stdout);

        firstRun = false;
        sleep(1);
    }
    return 0;
}