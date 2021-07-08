#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QThreadTest.h"
#include "Mession.h"
#include "ConvertMatQImage.h"
#include <qthread.h>
#include <qfiledialog.h>

class QThreadTest : public QMainWindow
{
    Q_OBJECT

public:
    QThreadTest(QWidget *parent = Q_NULLPTR);
signals:
	void sendStartData(QImage, QImage);
public slots:
	void matchImg();
private:
    Ui::QThreadTestClass ui;
	QThread* T;
	Mession* M;
};
