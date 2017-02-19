#pragma once

#include "chao.h"
#include "Sonic.h"

class ChaoClass
{
public:
	ChaoClass();
	~ChaoClass();

	void SetColor(SA2BColour::Type a_Colour);
	Chao * GetChao() { return &m_Chao; }

	void RandomizeStats();
	void RandomizeHealth();
	void RandomizeColor();
	void RandomizePersonality();

	void RandomizeType();
	void RandomizeAppearance();

	void RandomizeName();

private:
	Chao m_Chao;
};

