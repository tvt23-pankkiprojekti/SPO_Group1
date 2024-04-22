/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *line;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *N7;
    QPushButton *N2;
    QPushButton *N8;
    QPushButton *N3;
    QPushButton *N6;
    QPushButton *N4;
    QPushButton *N9;
    QPushButton *N1;
    QPushButton *N5;
    QPushButton *enterBtn;
    QPushButton *undoBtn;
    QPushButton *N0;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(317, 314);
        Dialog->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";"));
        line = new QLineEdit(Dialog);
        line->setObjectName("line");
        line->setGeometry(QRect(70, 90, 181, 28));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 221, 51));
        label->setStyleSheet(QString::fromUtf8("color: rgb(66, 108, 164);\n"
"font: 700;"));
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 120, 256, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        N7 = new QPushButton(gridLayoutWidget);
        N7->setObjectName("N7");
        N7->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N7, 2, 0, 1, 1);

        N2 = new QPushButton(gridLayoutWidget);
        N2->setObjectName("N2");
        N2->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N2, 0, 1, 1, 1);

        N8 = new QPushButton(gridLayoutWidget);
        N8->setObjectName("N8");
        N8->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N8, 2, 1, 1, 1);

        N3 = new QPushButton(gridLayoutWidget);
        N3->setObjectName("N3");
        N3->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N3, 0, 2, 1, 1);

        N6 = new QPushButton(gridLayoutWidget);
        N6->setObjectName("N6");
        N6->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N6, 1, 2, 1, 1);

        N4 = new QPushButton(gridLayoutWidget);
        N4->setObjectName("N4");
        N4->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N4, 1, 0, 1, 1);

        N9 = new QPushButton(gridLayoutWidget);
        N9->setObjectName("N9");
        N9->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N9, 2, 2, 1, 1);

        N1 = new QPushButton(gridLayoutWidget);
        N1->setObjectName("N1");
        N1->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N1, 0, 0, 1, 1);

        N5 = new QPushButton(gridLayoutWidget);
        N5->setObjectName("N5");
        N5->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N5, 1, 1, 1, 1);

        enterBtn = new QPushButton(gridLayoutWidget);
        enterBtn->setObjectName("enterBtn");
        enterBtn->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(enterBtn, 3, 1, 1, 1);

        undoBtn = new QPushButton(gridLayoutWidget);
        undoBtn->setObjectName("undoBtn");
        undoBtn->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(undoBtn, 3, 2, 1, 1);

        N0 = new QPushButton(gridLayoutWidget);
        N0->setObjectName("N0");
        N0->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(N0, 3, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:16pt;\">ENTER YOUR PIN</span></p></body></html>", nullptr));
        N7->setText(QCoreApplication::translate("Dialog", "7", nullptr));
        N2->setText(QCoreApplication::translate("Dialog", "2", nullptr));
        N8->setText(QCoreApplication::translate("Dialog", "8", nullptr));
        N3->setText(QCoreApplication::translate("Dialog", "3", nullptr));
        N6->setText(QCoreApplication::translate("Dialog", "6", nullptr));
        N4->setText(QCoreApplication::translate("Dialog", "4", nullptr));
        N9->setText(QCoreApplication::translate("Dialog", "9", nullptr));
        N1->setText(QCoreApplication::translate("Dialog", "1", nullptr));
        N5->setText(QCoreApplication::translate("Dialog", "5", nullptr));
        enterBtn->setText(QCoreApplication::translate("Dialog", "ENTER", nullptr));
        undoBtn->setText(QCoreApplication::translate("Dialog", "UNDO", nullptr));
        N0->setText(QCoreApplication::translate("Dialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
