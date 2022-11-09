#include "qcontactinfo.h"

QContactInfo::QContactInfo(QWidget *parent) : QWidget(parent)
{
    Contact* contact = new Contact(0,"");
    SetContact(contact);
}

void QContactInfo::SetContact(Contact* l_contact)
{
    contactInfo = l_contact;
}
