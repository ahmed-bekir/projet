#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sponsor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:




    void on_pb_ajouter_clicked();



    void on_pb_supprimer_clicked();




void on_le_code2_cursorPositionChanged(int arg1, int arg2);

void on_pb_modifier_clicked();

void on_pushButton_9_clicked();

void on_tab_sponsor_activated(const QModelIndex &index);

void on_le_code_supp_cursorPositionChanged(int arg1, int arg2);
void on_image_clicked();



void on_pdf_clicked();

void on_pushButton_clicked();

void on_pushButton_2_clicked();

void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    Sponsor E;
    Sponsor Etmp;

};

#endif // MAINWINDOW_H
