#include "departement.h"
#include <QSqlQuery>
#include <QVariant>



departement::departement()
{

    nom_d="" , num="" ;

}

 departement::departement(QString num ,QString nom_d)
{
     this->num=num;
    this->nom_d=nom_d;


}

QString departement::get_num(){return num;}
QString departement::get_nomd(){return nom_d;}

bool departement::ajouterdepartement()
{
QSqlQuery query;
query.prepare("INSERT INTO DEPARTEMENT (NUM , NOM_D) "
                    "VALUES (   :num, :nom_d)");


query.bindValue(":num", num);
query.bindValue(":nom_d", nom_d);
;

return    query.exec();
}


    QSqlQueryModel * departement::afficherdepartement()
    {QSqlQueryModel * model= new QSqlQueryModel();


    model->setQuery("select * from DEPARTEMENT order by  NUM asc ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_d"));
        return model;
    }



    bool departement::supprimerdepartement(QString num)
    {
    QSqlQuery query;
    query.prepare("Delete from DEPARTEMENT where NUM =:num ");
    query.bindValue(":num",num);
    return    query.exec();
    }

    bool departement:: modifierdepartement(QString num , QString nom_d)
    {
        QSqlQuery query;

        query.prepare("UPDATE DEPARTEMENT SET  NUM= :num, NOM_D= :nom_d where NUM= :num" );


        query.bindValue(":num", num);
        query.bindValue(":nom_d", nom_d);

        return  query.exec();

    }

    QSqlQueryModel * departement::chercherdepart(QString nom_d)
     {
         QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM departement WHERE nom_d= '"+nom_d+"'") ;
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));


         return model;
     }

    bool departement::modifiernb()
    {

    }

    bool departement::verifierNum(QString num)
    {

        QSqlQuery query;
        QString n;
       // QString  num = QString::number(num);
                query.exec("SELECT num from departement");
                while (query.next())
                {
                    n=query.value("num").toString();
                    if (n==num)
                    {
                        return true;
                    }
                }
        return false;

          }


