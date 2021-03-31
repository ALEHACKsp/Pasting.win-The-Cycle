DWORD64 m_pid;
DWORD64 usermode_pid;
DWORD64 m_base;
DWORD64 m_game_manager;
DWORD64 isin_game;
DWORD64 m_gdi32base;

#include "DriverController.h"

DriverController* Controller = nullptr;

DWORD64 GetBaseAddress()
{
	return Controller->GetProcessBase();
}


template<typename T>
T read(uint64_t address)
{
	T buffer{ };

	bool result = Controller->ReadProcessMemory(address, &buffer, sizeof(T));

	return buffer;
}
template<typename T>
bool write(uint64_t address, T buffer)
{
	if (address > 0x7FFFFFFFFFFF || address < 1) return 0;

	return Controller->WriteProcessMemory(address, &buffer, sizeof(T));

	return true;
}
std::string readwtf(uintptr_t Address, void* Buffer, SIZE_T Size)
{
	Controller->ReadProcessMemory(Address, Buffer, Size);

	char name[255] = { 0 };
	memcpy(&name, Buffer, Size);

	return std::string(name);
}