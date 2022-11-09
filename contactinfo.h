#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class ContactInfo;
}

class ContactInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ContactInfo(QWidget *parent = nullptr);  //Конструкторы класса
             ContactInfo(Contact l_contact, QWidget *parent = nullptr);
             ~ContactInfo();

    inline Contact getContact() {return contact;}

    void setContactInfo();                   //Обновление информации о контакте на виджете
    void setContactInfo(Contact l_contact);  //Перегрузка, делает то же самое, но также переопределяет contact

    QString getName() {return contact.getName(); } //геттеры
    QString getNum() {return contact.getNum(); }

private slots:
    void on_pushButton_clicked(); //Бинд кнопки редактирования

private:
    Ui::ContactInfo *ui;

    Contact contact; //Контакт, который отображается в форме
};

#endif // CONTACTINFO_H
