#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QString>
#include "listitem.h"

ListItem* buildList(int maxSize);
ListItem* buildListAscending(int maxSize);
ListItem * searchListElement(ListItem *listBegin, int numberToSearch);
void inspectList(ListItem *listBegin);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ListItem *listBegin = new ListItem;
    qDebug()<< "build list descending";
    qDebug()<< "=====================";
    listBegin = buildList(3);
    inspectList(listBegin);

    qDebug()<< "build list ascending";
    qDebug()<< "====================";
    listBegin = buildListAscending(3);
    inspectList(listBegin);

    listBegin = searchListElement(listBegin, 2);

    if(listBegin == NULL){
        qDebug() << "Element was not found";
    }else{
        qDebug() << "Element with" << listBegin->info << "was in list.";
    }

    delete listBegin;

    return a.exec();
}

/**
    Builds a dynamic linear list with
    maxSize and returns the begining of
    the list.

    Notice: The list will be sorted descending,
    due the fact that the newest number will be inserted
    at the beginning of the list;
*/
ListItem* buildList(int maxSize)
{
    int count = 1;
    ListItem *start = new ListItem;
    if(maxSize == count-1){
        qDebug()<<"Could not build a list. Size of List is " << maxSize;
        return start;
    }
    for(count;count<=maxSize;count++){
        ListItem * item = new ListItem;
        item->info = count;
        item->next = start;
        start = item;
        qDebug()<< "start is now with info " << start->info;
    }
    return start;
}

ListItem* buildListAscending(int maxSize)
{
    int count = 1;
    bool firstPos = true;
    ListItem *startItem = new ListItem;
    ListItem *endItem = new ListItem;
    for(count;count<=maxSize;count++){
        ListItem *item = new ListItem;
        item->info = count;
        if(firstPos){
            startItem = item;
            startItem->next = endItem;
            endItem = startItem;
            firstPos = false;
        }else{
            endItem->next = item;
            endItem = endItem->next;
        }

    }
    return startItem;
}

/**
  Generates an output of a list. It gets the beginning of
  the list as argument.
*/
void inspectList(ListItem *listBegin)
{
    ListItem * item = listBegin;
    while(item != 0){
        try{
            qDebug()<< "info for item is: " << item->info;
            item = item->next;
        }catch(...){

        }
    }
    qDebug()<< "End of list.";
}

ListItem * searchListElement(ListItem *listBegin, int numberToSearch)
{
    bool found = false;
    int atIndex = 1;
    ListItem *foundItem;
    QString description = QString::number(numberToSearch)+ " was not found";
    if(listBegin != NULL)
    {
        while(listBegin != NULL){
            if(listBegin->info == numberToSearch){
                found = true;
                foundItem = listBegin;
                break;
            }else{
                listBegin = listBegin->next;
                atIndex++;
            }
        }
    }
    if(found)
        description = QString::number(numberToSearch) + " found at "
                      + QString::number(atIndex);
    qDebug()<< description;
    return foundItem;
}
