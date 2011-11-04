#ifndef D2INTERCEPTS_H
#define D2INTERCEPTS_H

#include "D2Structs.h"

void GameDraw_Intercept();
void GameInput_Intercept();
void GamePacketReceived_Intercept();
UnitAny* GetSelectedUnit_Intercept(void);
void Whisper_Intercept();
void GameAttack_Intercept();
void PlayerAssignment_Intercept();
void GameCrashFix_Intercept();
void GameDrawOOG_Intercept(void);
void GameActChange_Intercept(void);
void GameActChange2_Intercept(void);
void GameLeave_Intercept(void);
void ChannelInput_Intercept(void);
void ChannelWhisper_Intercept(void);
void ChannelChat_Intercept(void);
void ChannelEmote_Intercept(void);
void AddUnit_Intercept(UnitAny* lpUnit);
void RemoveUnit_Intercept(UnitAny* lpUnit);

#endif
