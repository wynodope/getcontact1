#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Contact // Класс контакта. Будет использоваться во всем проекте
{
private:

    QString num;
    QString name;

public:

    Contact() : num(""), name("") {};
    Contact(QString l_num, QString l_name) : num(l_num), name(l_name) {};

    QString getNum() {return num;}
    QString getName() {return name;}

    inline void setNum(QString l_num) { num = l_num; }
    inline void setName(QString l_name) { name = l_name; }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddContact(Contact newContact); //Добавление контакта в список

private slots:

    void on_btn_createContact_clicked(); //Бинд кнопки создания контакта

    void on_pushButton_clicked();        //Бинд кнопки информации

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
