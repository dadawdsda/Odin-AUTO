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
	system("title 黑板自动调整程序 ver2.0");
	cout << "黑板自动调整程序(黑板白笔) v2.0" << endl;
	cout << "Author: 2020级4班 Jian Hengtao" << endl;
	cout << "等待黑板启动中，请不要操作" << endl;
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
			cout << "检测到黑板已启动" << endl;
			Sleep(1000);
			move(800, 1030);
			move(690, 930);
			move(1115, 1035);
			move(920, 955);
			move(1005, 780);
			move(1115, 1035);
			move(159, 1024);
			move(960, 540);
			cout << "调整完成，程序结束" << endl;
			Sleep(3000);
			break;
		}
		Sleep(1000);
		if (i == 59)
		{
			cout << "黑板未能成功启动，程序即将退出" << endl;
			Sleep(3000);
		}
	}
	return 0;
}
