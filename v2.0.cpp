#include <iostream>
#include <Afxwin.h>
#pragma comment (lib, "User32.lib")
using namespace std;
int red, green, blue;
void move(int x, int y)
{
	SetCursorPos(x, y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(1000);
}
int main()
{
	system("title �ڰ��Զ��������� ver2.0");
	cout << "�ڰ��Զ���������(�ڰ�ױ�) v2.0" << endl;
	cout << "Author: 2020��4�� Jian Hengtao" << endl;
	cout << "�ȴ��ڰ������У��벻Ҫ����" << endl;
	for (int i = 0; i <= 60; i++)
	{

		HWND hWnd = ::GetDesktopWindow();
		HDC hdc = ::GetDC(hWnd);
		int x1 = 1680, y1 = 40;
		COLORREF pixel = ::GetPixel(hdc, x1, y1);
		red = GetRValue(pixel);
		green = GetGValue(pixel);
		blue = GetBValue(pixel);
		if (red == 7 && green == 106 && blue == 75)
		{
			cout << "��⵽�ڰ�������" << endl;
			Sleep(1000);
			move(800, 1030);
			move(690, 930);
			move(1115, 1035);
			move(920, 955);
			move(1005, 780);
			move(1115, 1035);
			move(159, 1024);
			move(960, 540);
			cout << "������ɣ��������" << endl;
			Sleep(3000);
			break;
		}
		Sleep(1000);
		if (i == 59)
		{
			cout << "�ڰ�δ�ܳɹ����������򼴽��˳�" << endl;
			Sleep(3000);
		}
	}
	return 0;
}
