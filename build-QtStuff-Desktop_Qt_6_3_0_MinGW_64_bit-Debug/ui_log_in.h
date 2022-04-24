/********************************************************************************
** Form generated from reading UI file 'log_in.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_IN_H
#define UI_LOG_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_log_in
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *log_in)
    {
        if (log_in->objectName().isEmpty())
            log_in->setObjectName(QString::fromUtf8("log_in"));
        log_in->resize(400, 300);
        lineEdit = new QLineEdit(log_in);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 50, 231, 20));
        lineEdit_2 = new QLineEdit(log_in);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 110, 231, 20));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(log_in);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 160, 171, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 183, 200);"));
        label = new QLabel(log_in);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 331, 21));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(false);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(log_in);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 61, 20));
        QFont font2;
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 183, 200);"));
        label_3 = new QLabel(log_in);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 61, 21));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(1, 183, 200);"));

        retranslateUi(log_in);

        QMetaObject::connectSlotsByName(log_in);
    } // setupUi

    void retranslateUi(QDialog *log_in)
    {
        log_in->setWindowTitle(QCoreApplication::translate("log_in", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("log_in", "LOG IN", nullptr));
        label->setText(QCoreApplication::translate("log_in", "Please Log-in", nullptr));
        label_2->setText(QCoreApplication::translate("log_in", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("log_in", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class log_in: public Ui_log_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_IN_H
