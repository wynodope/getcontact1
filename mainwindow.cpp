#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createcontact.h"
#include "contactinfo.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) //Стандартный конструктор
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   
    ui->setupUi(this);                            //Отображение визуала

    setWindowTitle("Список контактов");          //Меняем заголовок окна
    setWindowIcon(QIcon(":/img/Img/phone.png")); //Меняем иконку окна

    QVBoxLayout* VB_Contacts = ui->vb_contacts;  //Берем список контактов
    VB_Contacts->setAlignment(Qt::AlignTop);     //Меняем настройку списка, для корректного отображения элементов
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_createContact_clicked() //При нажатии кнопки "Добавить контакт"
{
    CreateContact window(this, this);           //Создаем окно создания контакта
    window.exec();                              //Отображжаем окно
}

void MainWindow::AddContact(Contact newContact) //Добавление контакта в список
{
    QVBoxLayout* VB_Contacts = ui->vb_contacts; //Берем список контактов

    ContactInfo* contact = new ContactInfo(newContact, this); //Создем виджет, который будет отображать информацию о контакте
    contact->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum); //Устанавливаем настройки размера виджета
    VB_Contacts->addWidget(contact); //Добавляем элемент в список
}


void MainWindow::on_pushButton_clicked() //Нажатие на кнопку "информация"
{
    QString info =                                                                    //Информация о приложении
            "Программа создана для ВГТУ и не используется в комерческих целях. \
             Создатель программы: Внуков Владислав";

    QMessageBox::information(this,"Информация о приложении", info);                   //Вывод информации в отдельном окне
}

