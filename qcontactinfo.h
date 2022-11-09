#ifndef QCONTACTINFO_H
#define QCONTACTINFO_H

#include <QWidget>
#include "mainwindow.h"

class QContactInfo : public QWidget
{
    Q_OBJECT
public:
    explicit QContactInfo(QWidget *parent = nullptr);
    QContactInfo(Contact * l_contact) : contactInfo(l_contact) {};

private:

    Contact* contactInfo;
    void SetContact(Contact* l_contact);

public:

    inline Contact* getContact() {return contactInfo;}

signals:

};

#endif // QCONTACTINFO_H
