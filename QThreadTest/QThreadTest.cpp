#include "QThreadTest.h"

QThreadTest::QThreadTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	T = new QThread;		//�������̶߳���
	M = new Mession;		//�������������
	M->moveToThread(T);		//�߳�ת��
	connect(this, &QThreadTest::sendStartData, M, &Mession::templateMatch);

}

void QThreadTest::matchImg()
{
	QImage srcImg, tempImg;// drawRectImg;

	QString srcImgPath, tempImgPath;

	QFileDialog fileDlg;

	srcImgPath = fileDlg.getOpenFileName(
		nullptr, "srcImgPath", QDir::currentPath(), "all(*.*)");
	tempImgPath = fileDlg.getOpenFileName(
		nullptr, "tempImgPath", QDir::currentPath(), "all(*.*)");

	srcImg = QImage(srcImgPath);
	tempImg = QImage(tempImgPath);

	T->start();		//������ʵ���ϲ�δ����,��Ҫ����,������ֱ�ӵ���
	emit sendStartData(srcImg, tempImg);
	//M->templateMatch(&srcImg, &tempImg, &outputImg, &drawRectImg);  ����ֱ�ӵ��÷���������߳���
	connect(M, &Mession::sendResult, this, [=](QImage outputImg, QImage drawRectImg)
	{
		ui.src->setPixmap(QPixmap::fromImage(srcImg));
		ui.output->setPixmap(QPixmap::fromImage(outputImg));
		ui.drawRect->setPixmap(QPixmap::fromImage(drawRectImg));
		ui.output->setAlignment(Qt::AlignCenter);
		ui.drawRect->setAlignment(Qt::AlignCenter);
	});


}



