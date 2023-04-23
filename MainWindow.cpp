#include "MainWindow.h"
#include <QSizePolicy>
#include <QAction>
#include <QMenuBar>
#include <QPalette>
#include <QMessageBox>
#include <QDebug>
#include "EnFactory.h"
#include "RuFactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(300, 150);
    fact = new RuFactory();
    ruFact= new QAction("&Ru");
    connect(ruFact,SIGNAL(triggered()),this,SLOT(changeRu()));
    enFact= new QAction("&En");
    connect(enFact,SIGNAL(triggered()),this,SLOT(changeEn()));
    counter = new QLabel(QString::number(0)+" ", this);
    counter->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    counter->setGeometry(0, 20, 300, 80);
    counter->setMargin(50);
    this->update();
}

MainWindow::~MainWindow() {}

void MainWindow::update() {
    lang = fact->createLangMenu();
    QPalette pal = fact->createPalette();
    QPalette labelPal = fact->createLabelPalette();
    this->setPalette(pal);
    menuBar()->addMenu(lang);
    menuBar()->setAutoFillBackground(true);
    menuBar()->setPalette(pal);
    menuBar()->update();
    lang->addAction(ruFact);
    lang->addAction(enFact);
    menuBar()->addMenu(fact->createAboutLangMenu());
    QFont font = fact->createFont();
    menuBar()->setFont(font);
    label = fact->createLabel(this);
    label->setGeometry(0, 20, 300, 80);
    label->setMargin(50);
    label->setFont(font);
    label->setPalette(labelPal);
    label->show();
    counter->setFont(font);
    counter->setPalette(labelPal);
    but = fact->createButton(this);
    QAction* act3 = new QAction();
    connect(but, SIGNAL(clicked()), this, SLOT(increment()));
    but->addAction(act3);
    but->setGeometry(0, 100, 300, 50);
    but->setFont(font);
    but->show();
    QMainWindow::update();
}

void MainWindow::increment() {
    int num = counter->text().toInt();
    counter->setText(QString::number(++num)+" ");
}

void MainWindow::changeRu() {
    delete fact;
    delete but;
    delete label;
    menuBar()->clear();
    fact = new RuFactory();
    this->update();
}

void MainWindow::changeEn() {
    delete fact;
    delete but;
    delete label;
    menuBar()->clear();
    fact = new EnFactory();
    this->update();
}
