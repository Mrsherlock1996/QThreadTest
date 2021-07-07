#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QThreadTest.h"

class QThreadTest : public QMainWindow
{
    Q_OBJECT

public:
    QThreadTest(QWidget *parent = Q_NULLPTR);

private:
    Ui::QThreadTestClass ui;
};
