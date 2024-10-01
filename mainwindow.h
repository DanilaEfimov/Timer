#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "counter.h"
#include <QMainWindow>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    const QPalette palette = QPalette({100, 40, 40}, {40, 60, 40});

    static Counter* timer;
};
#endif // MAINWINDOW_H
