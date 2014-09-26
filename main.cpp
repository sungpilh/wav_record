/*********************************************************************************/
/*                                WAVE格式录音器                                  */
/*                                         made by hqwsky , 2014/9/26             */
/* note: you must add  Winmm.lib to your peojiect and complier                   */
/*usage: record 10s wave audio                                                    */  
/* refrence:billxia' blog                                                        */
/*********************************************************************************/
#include <stdio.h>
#include <Windows.h>
#include "SpeechRecord.h"

#pragma comment(lib,"Winmm.lib")

int main()
{
	// Set wave format when sampling the audio
	WAVEFORMATEX wf;
	SetWaveFormat(&wf,1,1,12000,1,8,0);
	
	// Open wave input channel
	HWAVEIN hWaveIn;
	OpenWaveIn(&hWaveIn,&wf);

	// Prepare Wave In Header and allocate memory
	WAVEHDR waveHdr;
	DWORD dataSize = 240000L;
	PrepareWaveIn(&hWaveIn, &waveHdr, dataSize);

	// Start recording
	StartRecord(&hWaveIn);
	
	Sleep(10000);

	// Stop recording
	MMTIME mmt;
	StopRecord(&hWaveIn, &mmt);

	SaveRecordtoFile(".//my.wav",&wf,&hWaveIn,&waveHdr,&mmt);

	ReleaseWaveIn(&hWaveIn, &waveHdr);
	CloseWaveIn(&hWaveIn);

	system("pause");
	return 0;
}
