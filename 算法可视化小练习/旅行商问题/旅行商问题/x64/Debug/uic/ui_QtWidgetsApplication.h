/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION_H
#define UI_QTWIDGETSAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplicationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplicationClass)
    {
        if (QtWidgetsApplicationClass->objectName().isEmpty())
            QtWidgetsApplicationClass->setObjectName("QtWidgetsApplicationClass");
        QtWidgetsApplicationClass->resize(600, 400);
        menuBar = new QMenuBar(QtWidgetsApplicationClass);
        menuBar->setObjectName("menuBar");
        QtWidgetsApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplicationClass);
        mainToolBar->setObjectName("mainToolBar");
        QtWidgetsApplicationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtWidgetsApplicationClass);
        centralWidget->setObjectName("centralWidget");
        QtWidgetsApplicationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtWidgetsApplicationClass);
        statusBar->setObjectName("statusBar");
        QtWidgetsApplicationClass->setStatusBar(statusBar);

        retranslateUi(QtWidgetsApplicationClass);

        QMetaObject::connectSlotsByName(QtWidgetsApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplicationClass)
    {
        QtWidgetsApplicationClass->setWindowTitle(QCoreApplication::translate("QtWidgetsApplicationClass", "QtWidgetsApplication", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplicationClass: public Ui_QtWidgetsApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION_H
