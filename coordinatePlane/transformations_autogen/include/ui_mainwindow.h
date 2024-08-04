/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *ozXlabel;
    QLabel *angleLabel;
    QRadioButton *oyRot;
    QLabel *oxLabel;
    QRadioButton *ozRot;
    QRadioButton *oxRot;
    QLabel *oyLabel;
    QLineEdit *angle;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *oxLabel1;
    QLineEdit *oxTrans;
    QHBoxLayout *horizontalLayout_2;
    QLabel *oyLabel1;
    QLineEdit *oyTrans;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ozLabel1;
    QLineEdit *ozTrans;
    QSpacerItem *verticalSpacer;
    QPushButton *apply;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(982, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 4, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ozXlabel = new QLabel(groupBox);
        ozXlabel->setObjectName(QString::fromUtf8("ozXlabel"));

        gridLayout->addWidget(ozXlabel, 2, 0, 1, 1);

        angleLabel = new QLabel(groupBox);
        angleLabel->setObjectName(QString::fromUtf8("angleLabel"));

        gridLayout->addWidget(angleLabel, 3, 0, 1, 1);

        oyRot = new QRadioButton(groupBox);
        oyRot->setObjectName(QString::fromUtf8("oyRot"));

        gridLayout->addWidget(oyRot, 1, 2, 1, 1, Qt::AlignLeft);

        oxLabel = new QLabel(groupBox);
        oxLabel->setObjectName(QString::fromUtf8("oxLabel"));

        gridLayout->addWidget(oxLabel, 0, 0, 1, 1);

        ozRot = new QRadioButton(groupBox);
        ozRot->setObjectName(QString::fromUtf8("ozRot"));

        gridLayout->addWidget(ozRot, 2, 2, 1, 1, Qt::AlignLeft);

        oxRot = new QRadioButton(groupBox);
        oxRot->setObjectName(QString::fromUtf8("oxRot"));

        gridLayout->addWidget(oxRot, 0, 2, 1, 1, Qt::AlignLeft);

        oyLabel = new QLabel(groupBox);
        oyLabel->setObjectName(QString::fromUtf8("oyLabel"));

        gridLayout->addWidget(oyLabel, 1, 0, 1, 1);

        angle = new QLineEdit(groupBox);
        angle->setObjectName(QString::fromUtf8("angle"));

        gridLayout->addWidget(angle, 3, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1, Qt::AlignRight);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        oxLabel1 = new QLabel(groupBox_2);
        oxLabel1->setObjectName(QString::fromUtf8("oxLabel1"));

        horizontalLayout->addWidget(oxLabel1);

        oxTrans = new QLineEdit(groupBox_2);
        oxTrans->setObjectName(QString::fromUtf8("oxTrans"));

        horizontalLayout->addWidget(oxTrans);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        oyLabel1 = new QLabel(groupBox_2);
        oyLabel1->setObjectName(QString::fromUtf8("oyLabel1"));

        horizontalLayout_2->addWidget(oyLabel1);

        oyTrans = new QLineEdit(groupBox_2);
        oyTrans->setObjectName(QString::fromUtf8("oyTrans"));

        horizontalLayout_2->addWidget(oyTrans);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ozLabel1 = new QLabel(groupBox_2);
        ozLabel1->setObjectName(QString::fromUtf8("ozLabel1"));

        horizontalLayout_3->addWidget(ozLabel1);

        ozTrans = new QLineEdit(groupBox_2);
        ozTrans->setObjectName(QString::fromUtf8("ozTrans"));

        horizontalLayout_3->addWidget(ozTrans);


        gridLayout_3->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 1, 1, 1, Qt::AlignRight);

        verticalSpacer = new QSpacerItem(0, 39, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        apply = new QPushButton(centralwidget);
        apply->setObjectName(QString::fromUtf8("apply"));

        gridLayout_2->addWidget(apply, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Rotation parameters", nullptr));
        ozXlabel->setText(QCoreApplication::translate("MainWindow", "OZ", nullptr));
        angleLabel->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        oyRot->setText(QString());
        oxLabel->setText(QCoreApplication::translate("MainWindow", "OX", nullptr));
        ozRot->setText(QString());
        oxRot->setText(QString());
        oyLabel->setText(QCoreApplication::translate("MainWindow", "OY", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Translation parameters", nullptr));
        oxLabel1->setText(QCoreApplication::translate("MainWindow", "OX", nullptr));
        oyLabel1->setText(QCoreApplication::translate("MainWindow", "OY", nullptr));
        ozLabel1->setText(QCoreApplication::translate("MainWindow", "OZ", nullptr));
        apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
