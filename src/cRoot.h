#pragma once

#include "ChaoClass.h"

class ChaoClass;

class cRoot
{
public:
	static cRoot * Get() { return s_Root; }

	cRoot();
	~cRoot();

	void Start();
	const HANDLE & GetHandle();

	void WriteChao(ChaoClass & a_Chao);

	ChaoClass * GetChao();

	ChaoClass * GetRandomChao();

private:
	static cRoot * s_Root;
	HANDLE m_Handle;

	const unsigned m_Adress = 0x019F6EC4;
};

