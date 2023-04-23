#include "RuFactory.h"
#include <QMessageBox>

RuFactory::RuFactory() {}

QMenu* RuFactory::createLangMenu() {
    QMenu* menu = new QMenu("&Язык");
    menu->setFont(createFont());
    return menu;
}

QMenu* RuFactory::createAboutLangMenu() {
    QMenu* menu = new QMenu("&Помощь");
    QMessageBox* msg = new QMessageBox();
    msg->setText("Автор: Евгений Черников");
    msg->setFont(createFont());
    QAction* act = menu->addAction("&Автор");
    connect(act,SIGNAL(triggered()),msg,SLOT(exec()));
    menu->setFont(createFont());
    return menu;
}

QFont RuFactory::createFont() {
    QFont font("Times", 10);
    font.setItalic(true);
    return font;
}

QPalette RuFactory::createPalette() {
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    return pal;
}

QPalette RuFactory::createLabelPalette() {
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::white);
    return pal;
}

QLabel* RuFactory::createLabel(QWidget* parent) {
    QLabel* label = new QLabel("Нажатий: ", parent);
    return label;
}

QPushButton* RuFactory::createButton(QWidget *parent) {
    QPushButton* but = new QPushButton(parent);
    but->setText("Нажми меня");
    return but;
}
