#include "vendre.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
vendre::vendre()
{
    referencev="";
     libellev="";acheteur="";
     prix=0;
}

vendre::vendre(QString referencev,QString libellev,QString acheteur,int prix)
{
    this->referencev=referencev;
    this->acheteur=acheteur;
    this->libellev=libellev;
    this->prix=prix;
}
QString vendre::getreferencev(){return referencev;}
QString vendre::getacheteur(){return acheteur;}
QString vendre::getlibellev(){return libellev;}
int vendre::getprix(){return prix;};
bool vendre::ajouterv(){
    QSqlQuery query;

          query.prepare("INSERT INTO vendre (referencev, libellev, acheteur, prix) "
                        "VALUES (:referencev, :libellev, :acheteur, :prix)");
          query.bindValue(":referencev", referencev);
          query.bindValue(":libellev", libellev);
          query.bindValue(":acheteur", acheteur);
          query.bindValue(":prix", prix);
          return  query.exec();

}
QSqlQueryModel* vendre::afficherv()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM vendre ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Referencev"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("libellev"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("acheteur"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
        return model;
}
QSqlQueryModel* vendre::listerlibv()
{
    QSqlQueryModel *model2 = new QSqlQueryModel();
    model2->setQuery("select libelle from equipement where etat='vendre'");
    return model2;
}
QSqlQueryModel* vendre::listerrefv()
{
QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("select reference from equipement where etat='vendre'");
 return model;
}
void vendre::listerch()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select acheteur from vendre");

}
QSqlQueryModel* vendre::listerprix()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select prix from prix");
    return model;
}

int vendre::stat_moins()
{   int moins =0;
    int total =0;
    QSqlQuery query0;
     query0.exec("SELECT * FROM vendre ");
     while(query0.next())
                 {
                     total = total + 1;

                 }
    QSqlQuery query;
     query.exec("SELECT * FROM vendre WHERE prix < 200");
     while(query.next())
                 {
                     moins = moins + 1;

                 }
     return ((moins*100)/total);

}
int vendre::stat_plus()
{   int plus =0;
    int total =0;
    QSqlQuery query0;
     query0.exec("SELECT * FROM vendre ");
     while(query0.next())
                 {
                     total = total + 1;

                 }
    QSqlQuery query;
     query.exec("SELECT * FROM vendre WHERE prix > 200");
     while(query.next())
                 {
                     plus = plus + 1;

                 }
     return ((plus*100)/total);

}
QString vendre:: apercu_pdf()
 {
     QString text="             ** La Listes Des Achats **       \n \n " ;
     QSqlQuery query ;
     QString i;
     QString d;
     QString e,c,h,g;
     int inc = 0;
      query.exec("SELECT * FROM vendre");
      while (query.next())
      {
         i=query.value(0).toString();
         d=query.value(1).toString();
         e=query.value(2).toString();
         c=query.value(3).toString();
         g=query.value(4).toString();
         inc++;
         char numstr[21]; // enough to hold all numbers up to 64-bits
         QString result = itoa(inc, numstr, 10);
         text += "\n Eqiupement à vendre: "+result+"\n\n  - Reference: "+ i+"\n  - Nom Equipement: "+d+"\n  - Nom Client: "+e+"\n  - Prix: "+c+"\n  - Date_Livraison: "+g+"\n\n_________________________\n";

     }

             return text ;
 }
bool vendre::verifierId(QString referencev)
{

    QSqlQuery query;
    QString n;
   // QString  num = QString::number(id);
            query.exec("SELECT referencev from vendre");
            while (query.next())
            {
                n=query.value("referencev").toString();
                if (n==referencev)
                {
                    return true;
                }
            }
    return false;

      }
