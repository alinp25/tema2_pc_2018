#include "TimeManipulator.h"

// Obtinerea timpului curent
char *getCurrentTime() {
    time_t timeNow;
    struct tm *currentTime;
    time(&timeNow);
    currentTime = localtime(&timeNow);
    return asctime(currentTime);
}