#include "cdplayer.h"
#include <stdio.h>

static const STATE *pCurrentState;

static const STATE *ignore();
static const STATE *startPlay();
static const STATE *stopPlay();
static const STATE *pausePlay();
static const STATE *resumePlay();

// STATE 구조체 바로 생성
// STATE 변수명 = {*함수, *함수};
const STATE IDLE = {ignore, startPlay};
const STATE PLAY = {stopPlay, pausePlay};
const STATE PAUSE = {stopPlay, resumePlay};

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
