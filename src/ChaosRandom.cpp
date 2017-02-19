#include <iostream>
#include <limits>
#include <windows.h>
#include "Sonic.h"
#include <string>
#include <ctime>
#include "chao.h"
#include "ChaoClass.h"
#include "cRoot.h"

using namespace std;

int main()
{
	cRoot root;

	root.Start();

		if (root.GetHandle())
		{
		cout << "Found game.\n";

		Chao testChao;

		char chaoBuffer[0x800];



		
		FILE* fp;

		

		while(1)
		{ 
			int timeToWait = 0;
			
			ChaoClass * tempChao = nullptr;

			printf("Randomize\n");

			if ( ((rand() % 101) <= 20) && (GetSonicState() < 20)) // 20 percent probability to get a prebuilt chao, avoid crash when holding chao
			{
				tempChao = root.GetRandomChao();
				tempChao->RandomizeStats();
				tempChao->RandomizePersonality();
				tempChao->RandomizeHealth();
				tempChao->GetChao()->garden = CHAO;
			}				
			else
			{ 
				tempChao = root.GetChao();
				tempChao->RandomizeColor();
				tempChao->RandomizeStats();
				tempChao->RandomizePersonality();
				tempChao->RandomizeHealth();
				tempChao->RandomizeAppearance();
				tempChao->RandomizeType();		
				tempChao->RandomizeName();
			}

			root.WriteChao(*tempChao);
			delete tempChao;

			timeToWait = (rand() % 30000) + 10000; //At least 10 second max 40 seconds

			Sleep(timeToWait);
		}
	


		}
		else
		{
			cout << "Couldn't find game.";
		}
	//}


	cin.clear();
	cin.ignore();
	cin.get();
}

