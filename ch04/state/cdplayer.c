#include "cdplayer.h"
#include <stdio.h>

static const STATE *pCurrentState;

static const STATE *ignore();
static const STATE *startPlay();
static const STATE *stopPlay();
static const STATE *pausePlay();
static const STATE *resumePlay();

/* state    | state 1   | state 2   |
 * ----------------------------------
 * IDLE     | IDLE      | CD O      |
 * IDLE     | IDEL      | CD    X   |
 * PLAY     | PLAY      | CD O      |
 * N/A      | PLAYE     | CD    X   |
 * PAUSE    | PAUSE     | CD O      |
 * N/A      | PAUSE     | CD    X   |
 */


// 각 STATE 별 event 함수들 할당
// STATE 구조체 바로 생성
// STATE 변수명 = {*함수, *함수};
const STATE IDLE = {ignore, startPlay};
const STATE PLAY = {stopPlay, pausePlay};
const STATE PAUSE = {stopPlay, resumePlay};
const STATE N_A = {ignore, ignore};

void initialize(){
    pCurrentState = &IDLE;
}

void onStop(){
    pCurrentState = pCurrentState->stop(pCurrentState);
}
void onPlayOrPause(){
    pCurrentState = pCurrentState->playOrPause(pCurrentState);
}

static const STATE *ignore(){
    printf("ignore \n");
    return pCurrentState;
}

static const STATE *stopPlay (){
    printf ("stop cd player \n");
    return &IDLE;
}

static const STATE *startPlay (){
    printf("start cd player \n");
    return &PLAY;
}

static const STATE *pausePlay(){
    printf("pause \n");
    return &PAUSE;
}

static const STATE *resumePlay (){
    printf("resume \n");
    return &PLAY;
}
