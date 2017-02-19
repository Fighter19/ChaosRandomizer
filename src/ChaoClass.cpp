#include "ChaoClass.h"
#include <string>
#include <stdlib.h>
#include "cRoot.h"


ChaoClass::ChaoClass()
{
	memcpy(m_Chao.buffer, chao, chao_size);
}


ChaoClass::~ChaoClass()
{

}

void ChaoClass::SetColor(SA2BColour::Type a_Colour)
{
	m_Chao.buffer[0xD8] = a_Colour;
}

void ChaoClass::RandomizeStats()
{
	// Game doesn't like more than 1 whole level up.
	//if((GetSonicState() != HOLD) && (GetSonicState() != PUTDOWN)) // If currently nothing is being hold to avoid crashes
	if(GetSonicState() < 20) // If current Animation is not a holding animation
	{ 
		int start = 0x20;
		int end = 0x46;
		for (int i = start; i < end; i++)
		{
			m_Chao.buffer[i] = rand() % 256;
		}
		m_Chao.buffer[0x30] = rand() % 100;
		m_Chao.buffer[0x31] = rand() % 100;
		m_Chao.buffer[0x32] = rand() % 100;
		m_Chao.buffer[0x33] = rand() % 100;
		m_Chao.buffer[0x34] = rand() % 100;
		m_Chao.buffer[0x35] = rand() % 100;
		m_Chao.buffer[0x36] = rand() % 100;
	}
	else
	{
		/*
		int start = 0x20;
		int end = 0x46;
		for (int i = start; i < end; i++)
		{
			m_Chao.buffer[i] = rand() % 256;
		}
		*/

		// Swim stat
		m_Chao.buffer[0x38] = rand() % 0x0D; // max 0C
		m_Chao.buffer[0x39] = rand() % 0xC3; // max C2
		// This is to limit it to 3266 in case the chao is being held
		// Yes, I know that this avoid the lower byte being C3 or higher, but who cares?
		//m_Chao.buffer[0x30] = rand() % 100;

		// Fly stat
		m_Chao.buffer[0x3A] = rand() % 0x0D; // max 0C
		m_Chao.buffer[0x3B] = rand() % 0xC3; // max C2
		//m_Chao.buffer[0x31] = rand() % 100;

		// Run stat											 // Fly stat
		m_Chao.buffer[0x3B] = rand() % 0x0D; // max 0C
		m_Chao.buffer[0x3C] = rand() % 0xC3; // max C2
		//m_Chao.buffer[0x32] = rand() % 100;

		// Power stat
		m_Chao.buffer[0x3E] = rand() % 0x0D; // max 0C
		m_Chao.buffer[0x3F] = rand() % 0xC3; // max C2
		//m_Chao.buffer[0x33] = rand() % 100;

		// Stamina stat
		m_Chao.buffer[0x40] = rand() % 0x0D; // max 0C
		m_Chao.buffer[0x41] = rand() % 0xC3; // max C2
		//m_Chao.buffer[0x34] = rand() % 100;

		// Luck stat
		m_Chao.buffer[0x42] = rand() % 0x0D; // max 0C
		m_Chao.buffer[0x43] = rand() % 0xC3; // max C2
		//m_Chao.buffer[0x35] = rand() % 100;

		// Int stat
		m_Chao.buffer[0x44] = rand() % 0x0D; // max 0C
		m_Chao.buffer[0x45] = rand() % 0xC3; // max C2
		//m_Chao.buffer[0x36] = rand() % 100;

	}
}

void ChaoClass::RandomizeHealth()
{
	int start = 0x15A;
	int end = 0x160;
	for (int i = start; i < end; i++)
	{
		m_Chao.buffer[i] = rand() % 256;
	}
}

void ChaoClass::RandomizeColor()
{
	SA2BColour::Type color;
	auto test = sizeof(SA2BColour::All) / sizeof(int);
	auto randomNum = rand() % (test + 1);
	color = SA2BColour::All[randomNum];
	SetColor(color);
}

void ChaoClass::RandomizePersonality()
{
	int start = 0x14A;
	int end = 0x15A; // 0x14E
	for (int i = start; i < end; i++)
	{
		m_Chao.buffer[i] = rand() % 256;
	}

//	m_Chao[0x150] = rand() % 256; // Big Eater
//	m_Chao[0x155] = rand() % 256; // Carefree
//	m_Chao[0x157] = rand() % 256; // Carefree
}

void ChaoClass::RandomizeType()
{
	m_Chao.type = rand() % 26;
}

void ChaoClass::RandomizeAppearance()
{
	m_Chao.buffer[0xD1] = rand() % 14; // Eyes
	m_Chao.buffer[0xD2] = rand() % 16; // Mouth
	m_Chao.buffer[0xD3] = rand() % 3; // Emotiball
	m_Chao.buffer[0xD6] = rand() % 2; // Feet hidden?
	m_Chao.buffer[0xDE] = rand() % 26;
	if (m_Chao.buffer[0xDE] == 25)
		m_Chao.buffer[0xDE] = 0xFF;

	int randomNum = rand() % 101;
	if (randomNum <= 5) // 5 percent
		m_Chao.type = OMOCHAO;
	else if (randomNum <= 5 + 10) // 10 percent
		m_Chao.type = ANIMAL;
	else if (randomNum <= 5 + 10 + 20) // 20 percent
		m_Chao.type = EGGCHAO;
	else
		m_Chao.type = NORMALCHAO; // 65 percent

	if (m_Chao.buffer[0xDD] == 4 || m_Chao.buffer[0xDD] == 5) // Not really necessairy
		m_Chao.buffer[0xDD] = 0;

}

const char *presetNames[] = { "4RUMP", "\x2F""BAMA", "\x14\x14\x14\x14", "\x23\x25\x2E\x21", "\x2E\x25\x2F", "\x2B\x25\x25\x2D" };

void ChaoClass::RandomizeName()
{

	int randomNumber = rand() % 101;
	if(randomNumber <= 20)
	{ 
		int index = randomNumber % 6;
		strcpy_s(m_Chao.name, 6, presetNames[index]);
	}
	else
	{
		int start = 0x12;
		int end = 0x19; // 0x14E
		for (int i = start; i < end; i++)
		{
			m_Chao.buffer[i] = rand() % 256;
		}
		m_Chao.buffer[end] = '\00';
	}




}