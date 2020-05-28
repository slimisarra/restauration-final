#include "boni.h"

#include <QDebug>
#include "connexion.h"

boni::boni()
{
 pic="";
dateboni="";
codep="";
libelle="";
qtprod="";


}
boni::boni(QString pic,QString dateboni,QString codep,QString libelle ,QString qtprod)
{
   this->pic=pic;
  this->dateboni=dateboni;
    this->codep=codep;
     this->libelle=libelle;
  this->qtprod=qtprod;


}
QString boni::get_pic(){return  pic;}

QString boni::get_dateboni(){return  dateboni;}
QString boni::get_codep(){return  codep;}
QString boni::get_libelle(){return  libelle;}
 QString boni::get_qtprod(){return  qtprod;}



bool boni::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO boni (PIC, DATEBONI ,CODEP, LIBELLE , QTPROD  ) "
                    "VALUES (:pic,  :dateboni , :codep , :libelle , :qtprod )");
query.bindValue(":pic", pic);

query.bindValue(":dateboni", dateboni);
query.bindValue(":codep", codep);
query.bindValue(":libelle", libelle);
query.bindValue(":qtprod", qtprod);


return    query.exec();
}

bool boni::modifier( QString pic,QString dateboni,QString codep,QString libelle,QString qtprod){
    QSqlQuery query;

    query.prepare("UPDATE BONI SET   PIC = :pic   , DATEBONI = :dateboni, CODEP = :codep  , LIBELLE = :libelle, QTPROD = :qtprod   WHERE    pic = :pic ");
    query.bindValue(":pic", pic);
    query.bindValue(":dateboni", dateboni);
    query.bindValue(":codep", codep);
    query.bindValue(":libelle", libelle);
    query.bindValue(":qtprod", qtprod);



    return  query.exec();
}





bool boni::supprimer(QString pic  )
{
QSqlQuery query;

query.prepare("Delete from boni where PIC = :pic  ");
query.bindValue(":pic", pic);


return    query.exec();
}
QSqlQueryModel * boni::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select pic,dateboni from boni");

    return model;
}
QSqlQueryModel * boni::afficher2(QString pic)
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select codep ,  libelle , qtprod from boni WHERE pic= '"+pic+"'");

    return model;
}



QSqlQueryModel * boni::tridesc()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from boni order by DATEBONI desc");

    return model;
}

QSqlQueryModel * boni::rechercher(QString pic)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM boni WHERE pic= '"+pic+"'") ;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("pic"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date bon"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Code produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Qt produit"));

    return model;
}

QString boni:: apercu_pdf()
 {
     QString text="             ** La Listes Des Produits **       \n \n " ;
     QSqlQuery query ;
     QString i;
     QString d;
     QString e,c,h;
     int inc = 0;
      query.exec("SELECT * FROM boni ");
      while (query.next())
      {
         i=query.value(0).toString();
         d=query.value(1).toString();
         e=query.value(2).toString();
         c=query.value(3).toString();

         inc++;
         char
 numstr[21]; // enough to hold all numbers up to 64-bits
         QString result = itoa(inc, numstr, 10);
         text += "\n Num Piéce: "+result+"\n\n  - Date Du Bon: "+ i+"\n  - Code Produit: "+d+"\n  - Libelle: "+e+"\n  - Quantité: "+c+"\n\n_________________________\n";

     }

             return text ;
 }
bool boni::verifierId(QString pic)
{

    QSqlQuery query;
    QString n;

            query.exec("SELECT PIC from BONI");
            while (query.next())
            {
                n=query.value("pic").toString();
                if (n==pic)
                {
                    return true;
                }
            }
    return false;

      }
