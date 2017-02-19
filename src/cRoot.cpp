#include "cRoot.h"
#include <stdio.h>
#include <ctime>
#include <windows.h>
#include <iostream>
#include "Chaos/spooky.h"
#include "Chaos/magic.h"
#include "Chaos/rainbow.h"
#include "Chaos/skull.h"
#include "Chaos/tin.h"
#include "Chaos/wacky.h"

cRoot * cRoot::s_Root = nullptr;



cRoot::cRoot()
{
	s_Root = this;
}

cRoot::~cRoot()
{
	s_Root = nullptr;
	CloseHandle(m_Handle);
}

void cRoot::Start()
{
	printf("Starting up randomizer...\n");
	srand(time(NULL));


	HWND hwnd;
	LPCWSTR windowname = L"SONIC ADVENTURE 2";
	hwnd = FindWindow(0, windowname);
	DWORD id;
	int value;
	


	if (!hwnd)
	{
		std::cout << "Couldn't find game.";
	}

	//else
	//{


	GetWindowThreadProcessId(hwnd, &id);

	m_Handle = OpenProcess(PROCESS_ALL_ACCESS, false, id);

	//if (ReadProcessMemory(root.GetHandle(), (LPCVOID)adress, &testChao, sizeof(testChao), NULL))
		//cout << "Name:" << testChao.name << "\nGarden:" << testChao.garden << "\n" << "Remaining life: " << to_string(testChao.happiness) << std::endl;
		//printf("Name: %s\n Garden:%i\n", testChao.name, testChao.garden);
	//else
	//	cout << "Error: " << GetLastError(); //299 is partial copy (probably not allocated memory)

	//Chao* chao = (Chao*)buffer;
	//strcpy_s(chao->name, sizeof(chao->name) , "TESTCH");
	//chao->garden = NORMAL;

	//		chao2[0xDD] = 0;
	//		chao2[0xDB] = 0;

	/*
	for (int i = 0; i < 21; i++)
	{
	chao2[0xD8] = rand() % 256;

	WriteProcessMemory(processhandle, (char*)adress + i*chao_size, (LPCVOID)chao2, chao_size, NULL);
	}
	*/

}

const HANDLE & cRoot::GetHandle()
{
	return m_Handle;
}

void cRoot::WriteChao(ChaoClass & a_Chao)
{
	WriteProcessMemory(m_Handle, (char*)m_Adress, (LPCVOID)a_Chao.GetChao(), 2047, NULL);
}

ChaoClass* cRoot::GetChao()
{
	ChaoClass *tempChao = new ChaoClass;
	if (!ReadProcessMemory(m_Handle, (LPCVOID)m_Adress, tempChao->GetChao(), 2047, NULL))
		std::cout << "Error: " << GetLastError(); //299 is partial copy (probably not allocated memory)

	return tempChao;
}

ChaoClass* cRoot::GetRandomChao()
{
	ChaoClass *tempChao = new ChaoClass;

	int randomNumber = rand() % 7;
	char * randomChao = (char*)spooky_chao;

	switch (randomNumber)
	{
		case 1: randomChao = (char*)spooky_chao; break;
		case 2: randomChao = (char*)magic_chao; break;
		case 3: randomChao = (char*)rainbow_chao; break;
		case 4: randomChao = (char*)skull_chao; break;
		case 5: randomChao = (char*)tin_chao; break;
		case 6: randomChao = (char*)wacky_chao; break;
	}

	memcpy(tempChao->GetChao(), randomChao, 2047);

	return tempChao;
}