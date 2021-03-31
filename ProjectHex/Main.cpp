#include "Main.h"

uint64_t add[16];

bool k_f5 = 0;
bool k_f6 = 0;
bool k_f7 = 0;
bool k_f8 = 0;

bool IsKeyDown(int vk)
{
	return (GetAsyncKeyState(vk) & 0x8000) != 0;
}

int aim_key = VK_RBUTTON;

int main()
{
    SetupWindow();
    DirectXInit(MyWnd);
  

    m_pid = PIDManager::GetAowProcId();
    Controller = new DriverController(m_pid);
    usermode_pid = GetCurrentProcessId();
    m_base = GetBaseAddress();
    printf("BaseAdress ->%llX GamePid %i\n", m_base, m_pid);

    HANDLE hdl = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(cache), nullptr, NULL, nullptr);

    CloseHandle(hdl);

    while (TRUE) {

        MainLoop();
    }

}