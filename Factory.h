#ifndef FACTORY_H
#define FACTORY_H

#include <QMenu>
#include <QLabel>
#include <QPushButton>

class Factory: public QWidget
{
public:
    virtual QMenu* createLangMenu() = 0;
    virtual QMenu* createAboutLangMenu() = 0;
    virtual QFont createFont() = 0;
    virtual QPalette createPalette() = 0;
    virtual QPalette createLabelPalette() = 0;
    virtual QLabel* createLabel(QWidget* parent) = 0;
    virtual QPushButton* createButton(QWidget* parent) = 0;
};

#endif // FACTORY_H
