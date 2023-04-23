#ifndef ENFACTORY_H
#define ENFACTORY_H
#include <QWidget>
#include "Factory.h"

class EnFactory : public Factory
{
    Q_OBJECT
public:
    EnFactory();
    QMenu* createLangMenu();
    QMenu* createAboutLangMenu();
    QFont createFont();
    QPalette createPalette();
    QPalette createLabelPalette();
    QLabel* createLabel(QWidget* parent);
    QPushButton* createButton(QWidget* parent);
};

#endif // ENFACTORY_H
