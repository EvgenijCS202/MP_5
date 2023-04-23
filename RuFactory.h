#ifndef RUFACTORY_H
#define RUFACTORY_H
#include "Factory.h"

class RuFactory : public Factory
{
public:
    RuFactory();
    QMenu* createLangMenu();
    QMenu* createAboutLangMenu();
    QFont createFont();
    QPalette createPalette();
    QPalette createLabelPalette();
    QLabel* createLabel(QWidget* parent);
    QPushButton* createButton(QWidget* parent);
};

#endif // RUFACTORY_H
