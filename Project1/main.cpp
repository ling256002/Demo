#include <graphics.h>
#include <Windows.h>

//设置启动项目
//1个解决方案里能包含多个项目，在项目名右键菜单里选择设为启动项目


int main(void) {
	initgraph(600, 400);

	//加载图片
	loadimage(0, _T("bg.jpg"));

	//设置文本字体
	settextstyle(30, 0, _T("微软雅黑"));
	settextcolor(RGB(255, 255, 0));

	//画一个空心矩形 左上角(300,40) 右下角(550,80)
	rectangle(300, 40, 550, 80);
	//在矩形内打印文本
	outtextxy(310, 45, _T("1-网站404攻击"));

	rectangle(300, 100, 550, 140);
	outtextxy(310, 105, _T("2-网站篡改攻击"));
	rectangle(300, 160, 550, 200);
	outtextxy(310, 165, _T("3-网站攻击修复"));
	rectangle(300, 220, 550, 260);
	outtextxy(310, 225, _T("4-查看攻击记录"));
	rectangle(300, 280, 550, 320);
	outtextxy(310, 285, _T("5-DNS攻击"));
	rectangle(300, 340, 550, 380);
	outtextxy(310, 345, _T("6-退出"));


	//rectangle(102, 222, 209, 333);


	system("pause");
	closegraph();
	return 0;
}



/*
int main(void) {
	//初始化图像界面 640*480
	initgraph(640, 480);

	setbkcolor(RGB(64, 128, 128));
	cleardevice();

	//设置画笔的颜色
	//setlinecolor(RED);
	setlinecolor(RGB(255, 0, 0));
	//设置画笔的样式，PS_SOLID表示实线, 10表示线的宽度
	setlinestyle(PS_SOLID, 10);

	//构建需要的图形 画一个圆
	circle(320, 240, 200);

	//设置字体颜色
	settextcolor(RGB(255, 255, 0));
	//设置字体
	settextstyle(100, 0, _T("微软雅黑"));
	//在指定位置打印文本
	outtextxy(170, 190, _T("无码高清"));

	//画线 从坐标(180,380)到坐标(460,100)画一条线
	line(180, 380, 460, 100);


	system("pause");

	//关闭图形界面
	closegraph();
	return 0;
}
*/





