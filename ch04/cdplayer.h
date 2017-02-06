#ifndef _CDPLAYER_H_
#define _CDPLAYER_H_

#ifdef __cplusplus
extern "C" {
#endif

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
