#pragma once

#include <QObject>
#include <opencv.hpp>
#include "ConvertMatQImage.h"

class Mession : public QObject
{
	Q_OBJECT


public:
	//Mession(QObject *parent);
	Mession();
	~Mession();
	//���߳�Ҫ�����ҵ���߼�
//void templateMatch(QImage* srcImg, QImage* templateImg, QImage* outputImg, QImage* drawRectangleImg = nullptr);
	void templateMatch(QImage srcImg, QImage templateImg);
signals:
//void begainMatchImg(QImage*, QImage*, QImage*, QImage*);
	void sendResult(QImage outputImg, QImage drawRectangleImg);
};
