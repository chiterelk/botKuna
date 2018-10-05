#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "JKuna/jkuna.h"
#include "JKuna/jorderofdepth.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
    QString apiKey = "";
    QString secretKey = "";

private:
	Ui::MainWindow *ui;
	JKuna *Kuna;

    void gotDepth(QList <QList<JOrderOfDepth>> _depth);
};

#endif // MAINWINDOW_H
