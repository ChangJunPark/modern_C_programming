#include <stdio.h>
#include "cdplayer.h"

int main (){
    printf(">> init\n");
    initialize();
    printf(">> play&pause\n");
    onPlayOrPause();
    printf(">> play&pause\n");
    onPlayOrPause();
    printf(">> stop\n");
    onStop();
    printf(">> stop\n");
    onStop();
    printf(">> play&pause\n");
    onPlayOrPause();

    return 0;
}

