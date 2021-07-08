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
	//子线程要处理的业务逻辑
//void templateMatch(QImage* srcImg, QImage* templateImg, QImage* outputImg, QImage* drawRectangleImg = nullptr);
	void templateMatch(QImage srcImg, QImage templateImg);
signals:
//void begainMatchImg(QImage*, QImage*, QImage*, QImage*);
	void sendResult(QImage outputImg, QImage drawRectangleImg);
};
