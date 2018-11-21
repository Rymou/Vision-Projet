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
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testQTClass)
    {
        if (testQTClass->objectName().isEmpty())
            testQTClass->setObjectName(QStringLiteral("testQTClass"));
        testQTClass->resize(1265, 573);
        centralWidget = new QWidget(testQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        b1 = new QPushButton(centralWidget);
        b1->setObjectName(QStringLiteral("b1"));
        b1->setGeometry(QRect(490, 20, 251, 28));
        camera = new QLabel(centralWidget);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(550, 60, 701, 461));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        camera->setFont(font);
        camera->setFrameShape(QFrame::Box);
        camera->setMargin(0);
        label_res = new QLabel(centralWidget);
        label_res->setObjectName(QStringLiteral("label_res"));
        label_res->setGeometry(QRect(6, 62, 521, 471));
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
        testQTClass->setWindowTitle(QApplication::translate("testQTClass", "testQT", Q_NULLPTR));
        b1->setText(QApplication::translate("testQTClass", "Start", Q_NULLPTR));
        camera->setText(QString());
        label_res->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class testQTClass: public Ui_testQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQT_H
