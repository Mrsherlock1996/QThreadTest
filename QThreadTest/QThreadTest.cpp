#include "QThreadTest.h"

QThreadTest::QThreadTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	T = new QThread;		//创建子线程对象
	M = new Mession;		//创建任务类对象
	M->moveToThread(T);		//线程转移
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

	T->start();		//任务类实际上并未启动,需要调用,但不能直接调用
	emit sendStartData(srcImg, tempImg);
	//M->templateMatch(&srcImg, &tempImg, &outputImg, &drawRectImg);  不能直接调用否则会在主线程中
	connect(M, &Mession::sendResult, this, [=](QImage outputImg, QImage drawRectImg)
	{
		ui.src->setPixmap(QPixmap::fromImage(srcImg));
		ui.output->setPixmap(QPixmap::fromImage(outputImg));
		ui.drawRect->setPixmap(QPixmap::fromImage(drawRectImg));
		ui.output->setAlignment(Qt::AlignCenter);
		ui.drawRect->setAlignment(Qt::AlignCenter);
	});


}



