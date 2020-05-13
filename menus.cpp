#include "menus.h"
#include <QDebug>
#include "connexion.h"

menus::menus()
{
code="";
nature="";
datemenu="";
qtprod="";
libelle="";

}
menus::menus(QString code,QString nature,QString datemenu,QString qtprod,QString libelle)
{
  this->code=code;
  this->nature=nature;
  this->datemenu=datemenu;
  this->qtprod=qtprod;
  this->libelle=libelle;

}

QString menus::get_code(){return  code;}
QString menus::get_nature(){return  nature;}
QString menus::get_datemenu(){return  datemenu;}
 QString menus::get_qtprod(){return  qtprod;}
QString menus::get_libelle(){return  libelle;}


bool menus::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO menus (CODE, NATURE, DATEMENU , QTPROD , LIBELLE ) "
                    "VALUES (:code, :nature, :datemenu , :qtprod , :libelle )");
query.bindValue(":code", code);
query.bindValue(":nature", nature);
query.bindValue(":datemenu", datemenu);
query.bindValue(":qtprod", qtprod);
query.bindValue(":libelle", libelle);

return    query.exec();
}

bool menus::modifier( QString code,QString nature,QString datemenu,QString qtprod,QString libelle){
    QSqlQuery query;

    query.prepare("UPDATE MENUS SET   CODE = :code , NATURE = :nature , DATEMENU = :datemenu  , QTPROD = :qtprod , LIBELLE = :libelle  WHERE NATURE = :nature ");
    query.bindValue(":code", code);
    query.bindValue(":nature", nature);
    query.bindValue(":datemenu", datemenu);
    query.bindValue(":qtprod", qtprod);
    query.bindValue(":libelle", libelle);


    return  query.exec();
}





bool menus::supprimer(QString datemenu ,QString nature )
{
QSqlQuery query;

query.prepare("Delete from menus where NATURE = :nature and DATEMENU = :datemenu ");
query.bindValue(":nature", nature);
query.bindValue(":datemenu", datemenu);
return    query.exec();
}
QSqlQueryModel * menus::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select datemenu,nature from menus");

    return model;
}
QSqlQueryModel * menus::afficher2(QString datemenu)
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select Code , QTPROD , libelle from MENUS WHERE  DATEMENU = '"+datemenu+"'"  );

    return model;
}


QSqlQueryModel * menus::tridesc()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select datemenu,nature from menus   order by  datemenu desc");

    return model;
}

QSqlQueryModel * menus::rechercher(QString datemenu)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM menus WHERE  datemenu= '"+datemenu+"'" ) ;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nature"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date menu"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Libelle"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Qt produit"));




    return model;
}
