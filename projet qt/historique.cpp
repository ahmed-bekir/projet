




#include "historique.h"

historique::historique()
{

}
void historique::save(QString id,QString nom, QString prenom, QString age, QString salaire, QString mail, QString poste)
{    QFile file ("C:/Users/arafe/OneDrive/Desktop/gestionemplye/historique.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";

     QTextStream out(&file);
     out << id+"\n"+nom << "\n"+prenom << "\n"+age << "\n"+salaire << "\n"+mail << "\n"+poste << "\n""------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";


}
QString historique::load()
{   tmp="";
    QFile file("C:/Users/arafe/OneDrive/Desktop/gestionemplye/historique.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;
}
