#ifndef LISTITEM_H
#define LISTITEM_H

#include <QObject>

class ListItem : public QObject
{
    Q_OBJECT
public:
    explicit ListItem(QObject *parent = 0);

    int info;
    ListItem *next;


signals:

public slots:

};

#endif // LISTITEM_H
