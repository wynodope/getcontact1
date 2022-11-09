#include "createcontact.h"
#include "ui_createcontact.h"
#include "mainwindow.h"
#include <QMessageBox>

CreateContact::CreateContact(QWidget *parent) : QDialog(parent), ui(new Ui::CreateContact) //Стандартный конструктор
{
    standart_constr(); //Стандартная функция для конструкторов
}

CreateContact::CreateContact(MainWindow *l_mainWindow, QWidget *parent) //Конструктор при вызове из MainWindow
    : QDialog(parent), ui(new Ui::CreateContact), mw_parent(l_mainWindow), ci_parent(nullptr)
{
    standart_constr(); //Стандартная функция для конструкторов
}

CreateContact::CreateContact(ContactInfo *l_contactInfo, Contact l_contact, QWidget *parent) //Конструктор при вызове из ContactInfo
    : QDialog(parent), ui(new Ui::CreateContact), mw_parent(nullptr), ci_parent(l_contactInfo)
{
    standart_constr(); //Стандартная функция для конструкторов

    QString l_name = l_contact.getName(); //Берем информацию о контакте, с которым работаем
    QString l_num = l_contact.getNum();

    ui->le_name->setText(l_name); //Вводим в редакторы текста информацию о контакте, который редактируем
    ui->le_num->setText(l_num);
}

void CreateContact::standart_constr() //Стандартная функция для конструкторов
{
    ui->setupUi(this);                            //Отображение виджета

    setWindowIcon(QIcon(":/img/Img/plus.png"));   //Меняем иконку окна
    setWindowTitle("Создать контакт");            //Меняем название окна

    ui->le_num->setText("+7");                    //В начало строки редактирования вставляем символы формата
}

CreateContact::~CreateContact()
{
    delete ui;
}

bool CreateContact::formatNum(QString* num)
{
    if(*num == "") //Проверка на пустоту
    {
        QMessageBox::warning(this, "Неверный ввод данных", "Введите номер телефона!"); //Вывод сообщения об ошибке
        return false;
    }

    if(num->mid(0, 2) != "+7") //Проверки символов на соотвествие формату
        num->insert(0,"+7");

    if(num->mid(2, 2) != " (")
        if(num->mid(3, 2) != " (")
            num->insert(2," (");

    if(num->mid(7, 2) != ") ")
        num->insert(7,") ");

    if(num->mid(7, 2) != ") ")
        num->insert(7,") ");

    if(num->mid(12, 1) != "-")
        num->insert(12,"-");

    if(num->mid(15, 1) != "-")
        num->insert(15,"-");

    if(num->length() > 18) //Проверка длины номера
    {
        QMessageBox::warning(this, "Неверный ввод данных", "Неверная длина номера телефона!"); //Вывод сообщения об ошибке
        return false;
    }

    return true;
}

void CreateContact::on_buttonBox_accepted() //Нажатие на кнопку Ок
{
    QString num = ui->le_num->text();       //Берем текст из ввода
    QString l_name = ui->le_name->text();

    if(!formatNum(&num)) //Форматирование номера и проверка на его корректность
        return;

    if(l_name == "") //Проверка на пустоту
    {
        QMessageBox::warning(this, "Неверный ввод данных", "Введите имя контакта!"); //Вывод сообщения об ошибке
        return;
    }

    if(mw_parent) //Если окно вызвал MainWindow то...
    {
        Contact contact(num, l_name);   //Виджет контакта
        mw_parent->AddContact(contact); //Добавляем контакт в список
        return;
    }

    if(ci_parent) //Если вызвал ContactInfo то...
        ci_parent->setContactInfo(Contact(num,l_name)); //Обновлене уже существующего элемента в списке
}

