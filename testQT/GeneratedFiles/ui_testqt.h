/********************************************************************************
** Form generated from reading UI file 'testqt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQT_H
#define UI_TESTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testQTClass
{
public:
    QWidget *centralWidget;
    QPushButton *b1;
    QLabel *camera;
    QLabel *label_res;
    QLabel *label;
    QLabel *label_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testQTClass)
    {
        if (testQTClass->objectName().isEmpty())
            testQTClass->setObjectName(QStringLiteral("testQTClass"));
        testQTClass->resize(1265, 638);
        centralWidget = new QWidget(testQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        b1 = new QPushButton(centralWidget);
        b1->setObjectName(QStringLiteral("b1"));
        b1->setGeometry(QRect(780, 40, 251, 28));
        camera = new QLabel(centralWidget);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(660, 90, 591, 481));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        camera->setFont(font);
        camera->setFrameShape(QFrame::Box);
        camera->setMargin(0);
        label_res = new QLabel(centralWidget);
        label_res->setObjectName(QStringLiteral("label_res"));
        label_res->setGeometry(QRect(10, 80, 541, 471));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 441, 20));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 40, 441, 20));
        label_2->setFont(font1);
        testQTClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(testQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testQTClass->setStatusBar(statusBar);

        retranslateUi(testQTClass);

        QMetaObject::connectSlotsByName(testQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *testQTClass)
    {
        testQTClass->setWindowTitle(QApplication::translate("testQTClass", "Projet Vision", Q_NULLPTR));
        b1->setText(QApplication::translate("testQTClass", "Lancer la cam\303\251ra", Q_NULLPTR));
        camera->setText(QString());
        label_res->setText(QString());
        label->setText(QApplication::translate("testQTClass", "Veuillez appuiyez sur \"R\" pour utiliser le crayon et dessiner.", Q_NULLPTR));
        label_2->setText(QApplication::translate("testQTClass", "Veuillez appuiyez sur \"H\" pour utiliser la gomme et effacer.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testQTClass: public Ui_testQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQT_H
