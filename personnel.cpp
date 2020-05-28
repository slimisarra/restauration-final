#include "personnel.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QDebug>

personnel::personnel()
{  salaire=0;
    nom="";prenom="";datenaiss="";dateemb="";departement="",id="";
}
personnel::personnel(QString departement,QString nom,QString prenom , int salaire,QString datenaiss , QString id, QString dateemb )
{
    this->id=id;
    this->departement=departement;
    this->datenaiss=datenaiss;
    this->dateemb=dateemb;
    this->salaire=salaire;
    this->nom=nom;
    this->prenom=prenom;
}
QString personnel::getid(){return id;}
void personnel::setid(QString id){this->id=id;}
bool personnel::ajouter(){
    QSqlQuery query;

    QString res_sal= QString::number(salaire);
          query.prepare("INSERT INTO personnel ( departement , nom , prenom , salaire, datenaiss, id, dateemb) "
                        "VALUES ( :departement,:nom, :prenom , :salaire , :datenaiss , :id , :dateemb)");

          query.bindValue(":departement",departement);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
            query.bindValue(":salaire",res_sal);
          query.bindValue(":datenaiss",datenaiss);
         query.bindValue(":id",id);
          query.bindValue(":dateemb",dateemb);
          return  query.exec();

}
QSqlQueryModel* personnel::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM PERSONNEL order by  ID asc ");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("departement"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("datenaiss"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("dateemb"));
        return model;
}

bool personnel::supprimer(QString id)
{
QSqlQuery query;
query.prepare("Delete from PERSONNEL where ID =:id ");
query.bindValue(":id",id);
return    query.exec();
}

bool personnel:: modifier(QString departement,QString nom,QString prenom , int salaire,QString datenaiss , QString id, QString dateemb)
{
    QSqlQuery query;

    query.prepare("UPDATE PERSONNEL SET   DEPARTEMENT= :departement , NOM= :nom , PRENOM= :prenom , DATENAISS= :datenaiss, ID= :id , DATEEMB= :dateemb  where ID=:id" );
    query.bindValue(":departement", departement);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
      query.bindValue(":salaire", salaire);
     query.bindValue(":datenaiss", datenaiss);
      query.bindValue(":id", id);
      query.bindValue(":dateemb", dateemb);

    return  query.exec();

}

QSqlQueryModel* personnel::affecter()
{
QSqlQueryModel *model = new QSqlQueryModel();
                        model->setQuery("select NUM from DEPARTEMENT");
                        return model;
}

QSqlQueryModel * personnel::chercher(QString id)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM personnel WHERE id= '"+id+"'") ;
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("departement"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date naiss"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("date emb"));

     return model;
 }

//Compter les p avec prix -1000 et retourner leur pourcentage
int personnel::stat_moins()
{   int moins =0;
    int total =0;
    QSqlQuery query0;
     query0.exec("SELECT * FROM personnel ");
     while(query0.next())
                 {
                     total = total + 1;

                 }
    QSqlQuery query;
     query.exec("SELECT * FROM personnel WHERE salaire < 100");
     while(query.next())
                 {
                     moins = moins + 1;

                 }
     return ((moins*100)/total);

}

int personnel::stat_plus()
{   int plus =0;
    int total =0;
    QSqlQuery query0;
     query0.exec("SELECT * FROM personnel ");
     while(query0.next())
                 {
                     total = total + 1;

                 }
    QSqlQuery query;
     query.exec("SELECT * FROM personnel WHERE salaire > 100");
     while(query.next())
                 {
                     plus = plus + 1;

                 }
     return ((plus*100)/total);

}

bool personnel::verifierId(QString id)
{

    QSqlQuery query;
    QString n;
   // QString  num = QString::number(id);
            query.exec("SELECT ID from personnel");
            while (query.next())
            {
                n=query.value("id").toString();
                if (n==id)
                {
                    return true;
                }
            }
    return false;

      }
