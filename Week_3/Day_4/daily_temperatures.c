#include <stdlib.h>

int* dailyTemperatures(int* temperatures,
                       int temperaturesSize,
                       int* returnSize) {
    int* daysToWarmer = calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    int waitingDays[temperaturesSize];
    int topWaitingDay = -1;

    for (int today = 0; today < temperaturesSize; today++) {
        while (topWaitingDay != -1 &&
               temperatures[waitingDays[topWaitingDay]] <
                   temperatures[today]) {
            int colderDay = waitingDays[topWaitingDay--];
            daysToWarmer[colderDay] = today - colderDay;
        }
        waitingDays[++topWaitingDay] = today;
    }

    return daysToWarmer;
}
