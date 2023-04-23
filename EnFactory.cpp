#include "EnFactory.h"
#include <QMenu>
#include <QMessageBox>
#include <QFont>

EnFactory::EnFactory() {}

QMenu* EnFactory::createLangMenu() {
    QMenu* menu = new QMenu("&Lang");
    menu->setFont(createFont());
    return menu;
}

QMenu* EnFactory::createAboutLangMenu() {
    QMenu* menu = new QMenu("&Help");
    QMessageBox* msg = new QMessageBox();
    msg->setText("Author: Eugene Chernikov");
    msg->setFont(createFont());
    QAction* act = menu->addAction("&Author");
    connect(act,SIGNAL(triggered()),msg,SLOT(exec()));
    menu->setFont(createFont());
    return menu;
}

QFont EnFactory::createFont() {
    QFont font("Times", 8, QFont::Bold);
    return font;
}

QPalette EnFactory::createPalette() {
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    return pal;
}

QPalette EnFactory::createLabelPalette() {
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::black);
    return pal;
}

QLabel* EnFactory::createLabel(QWidget* parent) {
    QLabel* label = new QLabel("Clicked: ", parent);
    return label;
}

QPushButton* EnFactory::createButton(QWidget *parent) {
    QPushButton* but = new QPushButton(parent);
    but->setText("Press me");
    return but;
}
