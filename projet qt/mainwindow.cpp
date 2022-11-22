#include <QMessageBox>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QSqlQuery>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sponsor.h"










MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tab_sponsor_2->setModel(Etmp.afficher());
    
}

MainWindow::~MainWindow()
{

    delete ui;
 
}






void MainWindow::on_pb_ajouter_clicked()
{
    QString nom=ui->le_nom->text();
    QString localisation=ui->le_localisation->text();
    int numtel=ui->le_num->text().toInt();
    int code=ui->le_code->text().toInt();
    QString email=ui->le_ad->text();



   Sponsor E(nom,localisation,numtel,code,email);

bool test=E.ajouter();

if(test)
{

    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("Ajouter effectué.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_sponsor_2->setModel(Etmp.afficher());
}
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr("Ajouter non  effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pb_supprimer_clicked()
{


    int code =ui->le_code_supp->text().toInt();
    bool test=Etmp.supprimer(code);
    if(test)
    {
       QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("suppression effectuee \n"
                                            "click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_sponsor_2->setModel(Etmp.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                               QObject::tr("suppression non effectuee.\n"
                                      "click Cancel to exit."),QMessageBox::Cancel);

}




void MainWindow::on_pb_modifier_clicked()
{
    Sponsor E1;
     int code =ui->le_code_supp->text().toInt();
bool test=Etmp.supprimer(code);
    if(!test){
        QMessageBox::critical(nullptr, QObject::tr("nope"),
                    QObject::tr("update failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    }
    else
    {

        QString nom=ui->le_nom->text();
        QString localisation=ui->le_localisation->text();
        int numtel=ui->le_num->text().toInt();
        int code=ui->le_code->text().toInt();
        QString email=ui->le_ad->text();



       Sponsor E(nom,localisation,numtel,code,email);

      bool test1=E.ajouter();
   if(test1)
{

            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("update successful.\n"
                                    "update effectuer."), QMessageBox::Cancel);
            ui->tab_sponsor_2->setModel(E.afficher());


}
        else

            QMessageBox::critical(nullptr, QObject::tr("nope"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_pushButton_9_clicked()
{
    Sponsor E1;
    E1.setcode(ui->le_code2_2->text().toInt());
    bool test=E1.recherche(E1.getcode());
 ui->tab_sponsor_3->setModel(E1.afficher1());
    if(test){


        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("numero found.\n"
                                "rechercher effectuer."), QMessageBox::Cancel);


    }
    else
           QMessageBox::critical(nullptr, QObject::tr("nope"),
                       QObject::tr("numero not found .\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_pdf_clicked()
{


        QPdfWriter pdf("C:/Users/wildb/OneDrive/Desktop/projet qt/sponsor/sponsor.pdf");

           QPainter painter(&pdf);
           int i = 4000;
                  painter.setPen(Qt::darkCyan);
                  painter.setFont(QFont("Time New Roman", 25));
                  painter.drawText(3000,1400,"SPONSOR");
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Time New Roman", 15));
                  painter.drawRect(100,100,9400,2500);
                  painter.drawRect(100,3000,9400,500);
                  painter.setFont(QFont("Time New Roman", 9));
                  painter.drawText(400,3300,"NOM");
                  painter.drawText(1350,3300,"LOCALISATION");
                  painter.drawText(2200,3300,"NUMTEL");
                  painter.drawText(3400,3300,"CODE");
                  painter.drawText(4400,3300," EMAIL");

                  painter.drawRect(100,3000,9400,9000);

                  QSqlQuery query;
                  query.prepare("select * from Sponsor");
                  query.exec();
                  while (query.next())
                  {

                      painter.drawText(1350,i,query.value(1).toString());
                      painter.drawText(2300,i,query.value(2).toString());
                      painter.drawText(3400,i,query.value(3).toString());
                      painter.drawText(4400,i,query.value(4).toString());
                      painter.drawText(6200,i,query.value(5).toString());




                     i = i + 350;
                  }
                  QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                  QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }








void MainWindow::on_pushButton_2_clicked()

{
    Sponsor E;
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_sponsor_5->setModel(E.tri_code());
}





void MainWindow::on_pushButton_clicked()
{

        QString filename=QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
        if(QString::compare(filename,QString())!=0){

            QImage image;
            bool valid =image.load(filename);
            if(valid){
                image=image.scaledToWidth( ui->tab_sponsor_4->width(),Qt::SmoothTransformation);
               // ui->tab_sponsor_4->setPixmap(QPixmap::fromImage(image));

        }
            else{

                //error handling
            }
    }


}


/*void MainWindow::on_pushButton_12_clicked()
{
    Sponsor E;
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                                        QObject::tr("historique effectué.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);

            ui->tab_sponsor_5->setModel(E.save());

}*/
