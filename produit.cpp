#include "produit.h"
#include <QDebug>
#include "connexion.h"
produit::produit()
{
code="";
libelle="";
dateprod="";
prix=0;
qt=0;
catg="";
famil="";
}
produit::produit(QString code,QString libelle,QString dateprod,int prix,int qt,QString catg,QString famil)
{
  this->code=code;
  this->libelle=libelle;
  this->dateprod=dateprod;
  this->prix=prix;
     this->qt=qt;
     this->catg=catg;
     this->famil=famil;
}

QString produit::get_code(){return  code;}
QString produit::get_libelle(){return  libelle;}
QString produit::get_dateprod(){return  dateprod;}
int produit::get_prix(){return  prix;}
int produit::get_qt(){return  qt;}
QString produit::get_catg(){return  catg;}
QString produit::get_famil(){return  famil;}

bool produit::ajouter()
{
QSqlQuery query;

QString resprix= QString::number(prix);
QString resqt= QString::number(qt);
query.prepare("INSERT INTO produit (CODE, LIBELLE, DATEPROD , PRIX , QT , CATG , FAMIL) "
                    "VALUES (:code, :libelle, :dateprod , :prix , :qt , :catg , :famil)");
query.bindValue(":code", code);
query.bindValue(":libelle", libelle);
query.bindValue(":dateprod", dateprod);
query.bindValue(":prix", resprix);
query.bindValue(":qt", resqt);
query.bindValue(":catg", catg);
query.bindValue(":famil", famil);
return    query.exec();
}

QSqlQueryModel * produit::rechercher(QString code)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM produit WHERE code= '"+code+"'") ;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Qt"));


    return model;
}
QSqlQueryModel * produit::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from produit");

    return model;
}


bool produit::supprimer(QString code )
{
QSqlQuery query;

query.prepare("Delete from produit where CODE = :code  ");
query.bindValue(":code", code);

return    query.exec();
}
bool produit::modifier( QString code,QString libelle,QString dateprod,int prix,int qt,QString catg,QString famil){
    QSqlQuery query;

    QString resprix= QString::number(prix);
    QString resqt= QString::number(qt);
    query.prepare("UPDATE produit SET  LIBELLE = :libelle, DATEPROD = :dateprod  , PRIX= :prix , QT= :qt , CATG= :catg , FAMIL= :famil WHERE CODE = :code ");
    query.bindValue(":code", code);
    query.bindValue(":libelle", libelle);
    query.bindValue(":dateprod", dateprod);
    query.bindValue(":prix", resprix);
    query.bindValue(":qt", resqt);
    query.bindValue(":catg", catg);
    query.bindValue(":famil", famil);
    return  query.exec();
}

QSqlQueryModel *produit::listerprod()
{

    QSqlQueryModel *model = new QSqlQueryModel();
                            model->setQuery("select code from produit");
                       return model;
                     }

QSqlQueryModel * produit::tridesc()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from produit order by dateprod desc");

    return model;
}

int produit::stat_moins()
{   int moins =0;
    int total =0;
    QSqlQuery query0;
     query0.exec("SELECT * FROM produit ");
     while(query0.next())
                 {
                     total = total + 1;

                 }
    QSqlQuery query;
     query.exec("SELECT * FROM produit WHERE qt < 10");
     while(query.next())
                 {
                     moins = moins + 1;

                 }
     return ((moins*100)/total);

}

int produit::stat_plus()
{   int plus =0;
    int total =0;
    QSqlQuery query0;
     query0.exec("SELECT * FROM produit ");
     while(query0.next())
                 {
                     total = total + 1;

                 }
    QSqlQuery query;
     query.exec("SELECT * FROM produit WHERE qt > 10");
     while(query.next())
                 {
                     plus = plus + 1;

                 }
     return ((plus*100)/total);

}
QSqlQueryModel * produit::afficher3()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from produit where qt<10");

    return model;
}
