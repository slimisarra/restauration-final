#include "equipement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
equipement::equipement()
{
    reference="";
        famille="";libelle="";etat="";
}

equipement::equipement(QString reference,QString famille,QString libelle,QString etat)
{
    this->reference=reference;
    this->famille=famille;
    this->libelle=libelle;
    this->etat=etat;
}
QString equipement::getreference(){return reference;}
QString equipement::getfamille(){return famille;}
QString equipement::getlibelle(){return libelle;}
QString equipement::getetat(){return etat;}
bool equipement::ajouter(){
    QSqlQuery query;

          query.prepare("INSERT INTO equipement (reference, famille, libelle, etat) "
                        "VALUES (:reference, :famille, :libelle, :etat)");
          query.bindValue(":reference",reference);
          query.bindValue(":famille", famille);
          query.bindValue(":libelle", libelle);
          query.bindValue(":etat", etat);

          return query.exec();

}

bool equipement::modifierm(QString reference,QString etat)
{
    QSqlQuery query;


        query.prepare("UPDATE equipement SET etat=:etat WHERE reference=:reference");
        query.bindValue(":etat", etat);
        query.bindValue(":reference", reference);
        return query.exec();
}
bool equipement::supprimer(QString reference)
{
    QSqlQuery query;
    query.prepare("DELETE FROM equipement WHERE reference = :reference ");
    query.bindValue(":reference", reference);

    return  query.exec();
}

 QSqlQueryModel * equipement::chercher(QString lib)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM equipement WHERE libelle= '"+lib+"'") ;
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Famille"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("libelle"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

     return model;
 }
 QSqlQueryModel * equipement::rechercher( QString c)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from equipement where (equipement.libelle LIKE '"+c+"%')");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Famille"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("libelle"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

     return model;
 }
 bool equipement::verifierId(QString reference)
 {

     QSqlQuery query;
     QString n;
    // QString  num = QString::number(id);
             query.exec("SELECT reference from equipement");
             while (query.next())
             {
                 n=query.value("reference").toString();
                 if (n==reference)
                 {
                     return true;
                 }
             }
     return false;

       }
