#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include <QWidget>
#include <QDialog>

#include "mainwindow.h"
#include "addcomputermenu.h"
#include "personcreatemenu.h"
#include "addlinksmenu.h"


namespace Ui {
class DisplayList;
}

class DisplayList : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayList(QWidget *parent = 0);
    ~DisplayList();

private slots:
    void on_pBPBack_clicked();

    void on_pBLBack_clicked();

    void on_pBCBack_clicked();

    void on_pBCAdd_clicked();

    void on_tableWidget_activated(const QModelIndex &index);

    void on_ListComputers_clicked(const QModelIndex &index);

    void on_pBLAdd_clicked();

    void on_pBPAdd_clicked();

    void on_ListLinks_clicked(const QModelIndex &index);

    void on_ListPersons_clicked(const QModelIndex &index);

private:
    Ui::DisplayList *ui;
};

#endif // DISPLAYLIST_H
