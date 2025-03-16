#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <cctype>
bool IsCapsLockOn() {
	return (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
}

void ToggleCapsLock() {
	INPUT input[2] = { 0 };

	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = VK_CAPITAL;

	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = VK_CAPITAL;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(2, input, sizeof(INPUT));
}
void sendinputenter()
{
	INPUT input[2] = { 0 };

	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = VK_RETURN;

	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = VK_RETURN;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(2, input, sizeof(INPUT));
}
void sendinputab()
{
	INPUT input[2] = { 0 };

	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = VK_TAB;

	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = VK_TAB;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(2, input, sizeof(INPUT));
}
void sendinpudown()
{
	INPUT input[2] = { 0 };

	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = VK_DOWN;

	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = VK_DOWN;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(2, input, sizeof(INPUT));
}
void sendinputString(const char* str,int n){
	for (size_t i = 0; i < n; i++)
	{
		if (isdigit(str[i]))
		{
			INPUT input[2] = { 0 };

			input[0].type = INPUT_KEYBOARD;
			input[0].ki.wVk = str[i];

			input[1].type = INPUT_KEYBOARD;
			input[1].ki.wVk = str[i];
			input[1].ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(2, input, sizeof(INPUT));
		}
		else
		{
			if (isupper(str[i]))
			{
				if (!IsCapsLockOn())
				{
					ToggleCapsLock();
				}
				INPUT input[2] = { 0 };

				input[0].type = INPUT_KEYBOARD;
				input[0].ki.wVk = str[i];

				input[1].type = INPUT_KEYBOARD;
				input[1].ki.wVk = str[i];
				input[1].ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(2, input, sizeof(INPUT));
			}
			if (islower(str[i]))
			{
				char upper = toupper(str[i]);
				if (IsCapsLockOn())
				{
					ToggleCapsLock();
				}
				INPUT input[2] = { 0 };

				input[0].type = INPUT_KEYBOARD;
				input[0].ki.wVk = upper;

				input[1].type = INPUT_KEYBOARD;
				input[1].ki.wVk = upper;
				input[1].ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(2, input, sizeof(INPUT));
			}
		}
	}
}

int main() {
		HWND hNotepad = ::FindWindow(_T("Notepad"), NULL);//��ȡ���±����
		if (!hNotepad) {
			//AfxMessageBox(_T("��򿪼��±�"));
			ExitProcess(0);
		}
		::ShowWindow(hNotepad, SW_NORMAL);
		::SetForegroundWindow(hNotepad);//�Ѽ��±���Ϊ�����
	if (!IsCapsLockOn())
	{
		ToggleCapsLock();
	}
	sendinputString("10215530",8);
	sendinputab();
	sendinputString("HHb123456",9);
	sendinputab();
	sendinpudown();
	sendinputenter();
	//std::cout << "��ǰCaps Lock״̬: " << (IsCapsLockOn() ? "����" : "�ر�") << std::endl;

	/*ToggleCapsLock();

	std::cout << "�л���Caps Lock״̬: " << (IsCapsLockOn() ? "����" : "�ر�") << std::endl;*/
	getchar();
	return 0;
}