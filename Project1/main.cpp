#include <graphics.h>
#include <Windows.h>

//����������Ŀ
//1������������ܰ��������Ŀ������Ŀ���Ҽ��˵���ѡ����Ϊ������Ŀ


int main(void) {
	initgraph(600, 400);

	//����ͼƬ
	loadimage(0, _T("bg.jpg"));

	//�����ı�����
	settextstyle(30, 0, _T("΢���ź�"));
	settextcolor(RGB(255, 255, 0));

	//��һ�����ľ��� ���Ͻ�(300,40) ���½�(550,80)
	rectangle(300, 40, 550, 80);
	//�ھ����ڴ�ӡ�ı�
	outtextxy(310, 45, _T("1-��վ404����"));

	rectangle(300, 100, 550, 140);
	outtextxy(310, 105, _T("2-��վ�۸Ĺ���"));
	rectangle(300, 160, 550, 200);
	outtextxy(310, 165, _T("3-��վ�����޸�"));
	rectangle(300, 220, 550, 260);
	outtextxy(310, 225, _T("4-�鿴������¼"));
	rectangle(300, 280, 550, 320);
	outtextxy(310, 285, _T("5-DNS����"));
	rectangle(300, 340, 550, 380);
	outtextxy(310, 345, _T("6-�˳�"));


	//rectangle(102, 222, 209, 333);


	system("pause");
	closegraph();
	return 0;
}



/*
int main(void) {
	//��ʼ��ͼ����� 640*480
	initgraph(640, 480);

	setbkcolor(RGB(64, 128, 128));
	cleardevice();

	//���û��ʵ���ɫ
	//setlinecolor(RED);
	setlinecolor(RGB(255, 0, 0));
	//���û��ʵ���ʽ��PS_SOLID��ʾʵ��, 10��ʾ�ߵĿ��
	setlinestyle(PS_SOLID, 10);

	//������Ҫ��ͼ�� ��һ��Բ
	circle(320, 240, 200);

	//����������ɫ
	settextcolor(RGB(255, 255, 0));
	//��������
	settextstyle(100, 0, _T("΢���ź�"));
	//��ָ��λ�ô�ӡ�ı�
	outtextxy(170, 190, _T("�������"));

	//���� ������(180,380)������(460,100)��һ����
	line(180, 380, 460, 100);


	system("pause");

	//�ر�ͼ�ν���
	closegraph();
	return 0;
}
*/





