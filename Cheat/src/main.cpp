#include "Scanner.h"
#include <string>
#include<iostream>

DWORD Entity = 0x2346AA0;

void cons(const char* name)
{
	DWORD b;
	VirtualProtect(&FreeConsole, 1, PAGE_EXECUTE_READWRITE, &b);
	*(BYTE*)FreeConsole = 0xC3;
	VirtualProtect(&FreeConsole, 1, b, &b);
	AllocConsole();
	freopen_s((FILE**)stdin, "conin$", "r", stdin);
	freopen_s((FILE**)stdout, "conout$", "w", stdout);
	SetConsoleTitleA(name);
}
/* Functions */
DWORD GetPlayerHealth()
{
	return *(DWORD*)(Entity + 0x0238);
}
void SetPlayerHealth(int Value)
{
	*(DWORD*)(Entity + 0x54CC) = Value;
}
void setMoneys(int value)
{
	*reinterpret_cast<DWORD*>(Entity + 0x55C8) = value;
}
void setSpeed(int value)
{
	*reinterpret_cast<DWORD*>(Entity + 0x0094) = value;
}

void setAmmo()
{
	*reinterpret_cast<DWORD*>(Entity + 0x03F0) = 420;
	*reinterpret_cast<DWORD*>(Entity + 0x03F4) = 420;
}

int main()
{
	cons("O-o");
	std::printf("Loaded..\n");
	
	
	
	
	std::string input;

	while (true)
	{
		std::getline(std::cin, input);
		
		if (input == "points")
		{
			int points = 100000;
			std::printf("Setting points to: %i\n", points);
			setMoneys(points);
		}
		if (input == "health")
		{
			std::printf("Health is currently: %i\n", GetPlayerHealth());
			
		}
		if (input == "sethealth")
		{
			std::printf("Enter health: ");
			int health = INT_MAX;
			SetPlayerHealth(health);
			std::printf("Health set to: %i\n", GetPlayerHealth());
		}
		if (input == "setammo")
		{
			
				setAmmo();
			
			
			
		}
		if (input == "speed")
		{
			setSpeed(3);
		}
	}

	return 0;
}

BOOL DllMain(HMODULE hm, DWORD reason, LPVOID)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
		break;
	}
	}
	return TRUE;
}