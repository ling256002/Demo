#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <mmsystem.h> //播放音乐需要的头文件
#pragma comment(lib,"winmm.lib") //告诉编译器，加载winmm.lib库文件
#include <string>
#define COUNT 148
using namespace std;

int main(void) {
	initgraph(800, 450);
	loadimage(0, _T("jile.jpg"));
	//重复播放"极乐净土.mp3"
	mciSendString(_T("play 极乐净土.mp3 repeat"), 0, 0, 0);

	/*char fileName[128] = { 0 };
	while (1)
	{
		for (int i = 1; i <= 148; i++)
		{
			sprintf_s(fileName, ".\\images2\\_%04d_图层-%d.jpg", 148 - i, i);
			loadimage(0, fileName);
			Sleep(50);
		}
	}*/

	IMAGE images[COUNT];
	char fileName[COUNT];
	cout << "正在加载..." << endl;
	//预先加载资源
	for (int i = 1; i <= COUNT; i++)
	{
		sprintf_s(fileName, ".\\images2\\_%04d_图层-%d.jpg", COUNT - i, i);
		loadimage(&images[i-1], fileName);
	}

	while (1)
	{
		for (int i = 0; i < COUNT; i++)
		{
			putimage(0, 0, &images[i]);
			Sleep(50);
		}
	}

	system("pause");
	closegraph();
	return 0;
}