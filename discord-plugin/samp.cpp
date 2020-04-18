#include "samp.h"

extern uint32_t dwSAMP_Addr;

bool SampInit()
{
	if (dwSAMP_Addr == NULL)
		dwSAMP_Addr = (DWORD)GetModuleHandle("samp.dll");
	if (dwSAMP_Addr == NULL)
		return false;

	if (SAMP == nullptr)
		SAMP = *(stSAMP**)(dwSAMP_Addr + 0x21A0F8);
	if (SAMP == nullptr)
		return false;

	if (Scoreboard == nullptr)
		Scoreboard = *(stScoreboardInfo**)(dwSAMP_Addr + 0x21A0B4);

	return true;
}

// global samp pointers
stSAMP* SAMP = nullptr;
stScoreboardInfo* Scoreboard = nullptr;