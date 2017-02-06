#ifndef _CDPLAYER_H_
#define _CDPLAYER_H_

#ifdef __cplusplus
extern "C" {
#endif
/*
 * State Pattern -> state가 2개 이상일 때
 * STATE 구조체를 만들고
 * 구조체 내에는 STATE 구조체를 반환하는 가상함수를 정의함.
 * 정의하는 가상함수는 각 상태에서의 이벤트를 뜻함.
 */
typedef struct State {
    const struct State *(* const stop)();
    const struct State *(* const playOrPause)();
} STATE;

void initialize();
void onStop();
void onPlayOrPause();

#ifdef __cplusplus
}
#endif
#endif
