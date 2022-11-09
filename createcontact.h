#ifndef CREATECONTACT_H
#define CREATECONTACT_H

#include <QDialog>
#include "mainwindow.h"
#include "contactinfo.h"

namespace Ui {
class CreateContact;
}

class CreateContact : public QDialog
{
    Q_OBJECT

public:
    explicit CreateContact(QWidget *parent = nullptr);
    ~CreateContact();

    CreateContact(MainWindow *l_mainWindow, QWidget *parent = nullptr); //Конструтор, при добавлении виджета в список
    CreateContact(ContactInfo *l_contactInfo, Contact l_contact, QWidget *parent = nullptr); //Конструтор, при редактировании существующего элемента

private slots:
    void on_buttonBox_accepted(); //Бинд кнопки ОК

private:
    Ui::CreateContact *ui;

    void standart_constr(); //Функция для конструторов. Служит для сокращения кода

    MainWindow* mw_parent;  //MainWindow, который вызвал это окно
    ContactInfo* ci_parent; //ContactInfo, который вызвал это окно

    bool formatNum(QString* l_num); //Форматирование номера телефона
};
#endif // CREATECONTACT_H
