#include "contactinfo.h"
#include "ui_contactinfo.h"
#include <QMessageBox>
#include <createcontact.h>

ContactInfo::ContactInfo(QWidget *parent) : //Стандартный конструктор
    QWidget(parent),
    ui(new Ui::ContactInfo)
{
    ui->setupUi(this); //Отображение визуала
}

ContactInfo::ContactInfo(Contact l_contact, QWidget *parent) : QWidget(parent), ui(new Ui::ContactInfo), contact(l_contact) //Конструктор с определением контакта
{
    ui->setupUi(this); //Отображение визуала
    setContactInfo(); //Обновление виджета
}

ContactInfo::~ContactInfo()
{
    delete ui;
}

void ContactInfo::setContactInfo()
{
    if(contact.getName() == "" || contact.getNum() == "") //Вызов ошибки при неверный значениях класса Contact
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось найти информацию о контакте");
        return;
    }

    QLabel* l_name = ui->l_name; //Берем из визуальной формы 2 виджета, отображающих текст
    QLabel* l_num = ui->l_num;

    l_name->setText(contact.getName()); //Меняем текст в виджетах
    l_num->setText(contact.getNum());
}

void ContactInfo::setContactInfo(Contact l_contact)
{
    contact = l_contact; //Переопределяем контакт
    setContactInfo();    //Обновление виджета
}

void ContactInfo::on_pushButton_clicked()
{
    CreateContact window(this, contact, parentWidget()); //Создание окна, для редактирования контакта
    window.exec();                                       //Отображение окна
}

