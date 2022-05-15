/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_shop
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *shop)
    {
        if (shop->objectName().isEmpty())
            shop->setObjectName(QString::fromUtf8("shop"));
        shop->resize(400, 300);
        buttonBox = new QDialogButtonBox(shop);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(shop);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 241, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(shop);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(46, 110, 61, 21));

        retranslateUi(shop);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, shop, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, shop, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(shop);
    } // setupUi

    void retranslateUi(QDialog *shop)
    {
        shop->setWindowTitle(QCoreApplication::translate("shop", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("shop", "SHOP", nullptr));
        label_2->setText(QCoreApplication::translate("shop", "Health", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shop: public Ui_shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
