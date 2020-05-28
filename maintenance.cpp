#include "maintenance.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
maintenance::maintenance()
{
    referencem="";
     libellem="";agent="";
     prix=0;duree="";
}

maintenance::maintenance(QString referencem,QString libellem,QString agent,QString duree,int prix)
{
    this->referencem=referencem;
    this->agent=agent;
    this->libellem=libellem;
    this->duree=duree;
    this->prix=prix;
}
QString maintenance::getreferencem(){return referencem;}
QString maintenance::getagent(){return agent;}
QString maintenance::getlibellem(){return libellem;}
QString maintenance::getduree(){return duree;}
int maintenance::getprix(){return prix;};
bool maintenance::ajouterm(){
    QSqlQuery query;

          query.prepare("INSERT INTO maintenance (referencem, libellem, agent, prix, duree) "
                        "VALUES (:referencem, :libellem, :agent, :prix, :duree)");
          query.bindValue(":referencem", referencem);
          query.bindValue(":libellem", libellem);
          query.bindValue(":agent", agent);
          query.bindValue(":prix", prix);
          query.bindValue(":duree", duree);
          return  query.exec();

}
QSqlQueryModel* maintenance::afficherm()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM maintenance ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Referencem"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("libellem"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("agent"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Duree"));
        return model;
}
QSqlQueryModel* maintenance::listerlibm()
{
    QSqlQueryModel *model2 = new QSqlQueryModel();
    model2->setQuery("select libelle from equipement where etat='maintenir'");
    return model2;
}
QSqlQueryModel* maintenance::listerrefm()
{
QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("select reference from equipement where etat='maintenir'");
 return model;
}

QSqlQueryModel * maintenance::trierprix()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM maintenance ORDER BY prix DESC") ;
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Referencem"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libellem"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("agent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Duree"));
    return model;

}
bool maintenance::verifierId(QString referencem)
{

    QSqlQuery query;
    QString n;
   // QString  num = QString::number(id);
            query.exec("SELECT referencem from maintenance");
            while (query.next())
            {
                n=query.value("referencem").toString();
                if (n==referencem)
                {
                    return true;
                }
            }
    return false;

      }

