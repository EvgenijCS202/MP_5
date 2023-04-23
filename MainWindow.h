#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Factory.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Factory* fact;
    QMenu* lang;
    QLabel* label;
    QPushButton* but;
    QLabel* counter;
    QAction* ruFact;
    QAction* enFact;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void update();
    void increment();
    void changeEn();
    void changeRu();
};
#endif // MAINWINDOW_H
