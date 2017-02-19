#include "Sonic.h"
#include "cRoot.h"
#include <iostream>

SA2BSonicState GetSonicState()
{
	unsigned int adress = 0x019EFE74;
	SA2BSonicState state;
	HANDLE test = cRoot::Get()->GetHandle();
	auto result = ReadProcessMemory(cRoot::Get()->GetHandle(), (LPCVOID)adress, &state, sizeof(state), NULL);
	if (result)
		std::cout << "Ok" << std::endl;
	else
		std::cout << "Error: " << GetLastError(); //299 is partial copy (probably not allocated memory)

	return state;
}
