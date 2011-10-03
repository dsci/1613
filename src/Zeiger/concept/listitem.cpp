#include "listitem.h"

ListItem::ListItem(QObject *parent) :
    QObject(parent)
{
    //this->info = 0;
    this->next = 0;
}
