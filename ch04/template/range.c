#include "range.h"

int range(const char *pFname)
{
    FILE *fp = fopen(pFname, "r");
    if (fp == NULL) return -1;

    int min = INT_MAX;  // 최소값을 찾기 위해 먼저 최대값을 설정
    int max = INT_MIN;  // for searching MAX value, searching MAX value
    char buf[256];

    while((fgets(buf, sizeof(buf), fp)) != NULL) {
        int value = atoi(buf);
        min = min > value ? value : min;
        max = max < value ? value : max;
    }

    fclose(fp);
    return max-min;
}
