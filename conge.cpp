#include "conge.h"
#include <QSqlQuery>
#include <QVariant>


conge::conge()
{
    ref=0;
    id_p="";
    datedebut="";
    datefin="";

}

 conge::conge(int ref ,QString id_p, QString datedebut, QString datefin)
{
     this->ref=ref;
    this->id_p=id_p;
    this->datedebut=datedebut;
    this->datefin=datefin;

}

 int conge::get_ref(){return ref;}
 void conge::setref(int ref){this->ref=ref;}

bool conge::ajouterconge()
{
QSqlQuery query;
query.prepare("INSERT INTO CONGE (REF , ID_P , DATEDEBUT , DATEFIN) "
                    "VALUES (   :ref, :id_p, :datedebut, :datefin)");


query.bindValue(":ref", ref);
query.bindValue(":id_p", id_p);
query.bindValue(":datedebut", datedebut);
query.bindValue(":datefin", datefin);


return    query.exec();
}


    QSqlQueryModel * conge::afficherconge()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CONGE order by  DATEDEBUT asc ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("id personnel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date debut"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date fin"));

        return model;
    }



    bool conge::supprimerconge(QString id_p)
    {
    QSqlQuery query;
    query.prepare("Delete from CONGE where ID_P =:id_p ");
    query.bindValue(":id_p",id_p);
    return    query.exec();
    }

    bool conge:: modifierconge(int ref,QString id_p,QString datedebut , QString datefin)
    {
        QSqlQuery query;

        query.prepare("UPDATE CONGE SET  ref= :ref, id_p= :id_p , datedebut= :datedebut, datefin= :datefin  where ref=:ref" );


        query.bindValue(":ref", ref);
        query.bindValue(":id_p", id_p);
         query.bindValue(":datedebut", datedebut);
        query.bindValue(":datefin", datefin);


        return  query.exec();

    }

    QSqlQueryModel* conge::affecterperso()
    {
    QSqlQueryModel *model = new QSqlQueryModel();
                            model->setQuery("select ID from PERSONNEL");
                            return model;
    }

    QSqlQueryModel * conge::chercherconge(QString id_p)
     {
         QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM conge WHERE id_p= '"+id_p+"'") ;
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("id personnel"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("date debut"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("date fin"));

         return model;
     }

    bool conge::verifierRef(int ref)
    {

        QSqlQuery query;
        QString n;
       QString  num = QString::number(ref);
                query.exec("SELECT ref from conge");
                while (query.next())
                {
                    n=query.value("ref").toString();
                    if (n==num)
                    {
                        return true;
                    }
                }
        return false;

          }


