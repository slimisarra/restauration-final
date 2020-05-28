#include "bonf.h"

#include <QDebug>
#include "connexion.h"

bonf::bonf()
{
 pic="";
codef="";
datebonf="";
codep="";
libelle="";
qtprod="";


}
bonf::bonf(QString pic,QString codef,QString datebonf,QString codep,QString libelle ,QString qtprod)
{
   this->pic=pic;
  this->codef=codef;
  this->datebonf=datebonf;
    this->codep=codep;
     this->libelle=libelle;
  this->qtprod=qtprod;


}
QString bonf::get_pic(){return  pic;}
QString bonf::get_codef(){return  codef;}
QString bonf::get_datebonf(){return  datebonf;}
QString bonf::get_codep(){return  codep;}
QString bonf::get_libelle(){return  libelle;}
 QString bonf::get_qtprod(){return  qtprod;}



bool bonf::ajouterbonf()
{
QSqlQuery query;

query.prepare("INSERT INTO bonf (PIC, CODEF, DATEBONF ,CODEP, LIBELLE , QTPROD  ) "
                    "VALUES (:pic, :codef, :datebonf , :codep , :libelle , :qtprod )");
query.bindValue(":pic", pic);
query.bindValue(":codef", codef);
query.bindValue(":datebonf", datebonf);
query.bindValue(":codep", codep);
query.bindValue(":libelle", libelle);
query.bindValue(":qtprod", qtprod);


return    query.exec();
}

bool bonf::modifier( QString pic,QString codef,QString datebonf,QString codep,QString libelle,QString qtprod){
    QSqlQuery query;

    query.prepare("UPDATE BONF SET   PIC = :pic , CODEF = :codef  , DATEBONF = :datebonf, CODEP = :codep  , LIBELLE = :libelle, QTPROD = :qtprod   WHERE    pic = :pic ");
    query.bindValue(":pic", pic);
    query.bindValue(":codef", codef);
    query.bindValue(":datebonf", datebonf);
    query.bindValue(":codep", codep);
    query.bindValue(":libelle", libelle);
    query.bindValue(":qtprod", qtprod);



    return  query.exec();
}





bool bonf::supprimer(QString pic  )
{
QSqlQuery query;

query.prepare("Delete from bonf where PIC = :pic   ");
query.bindValue(":pic", pic);


return    query.exec();
}
QSqlQueryModel * bonf::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select pic,datebonf from bonf");

    return model;
}
QSqlQueryModel * bonf::afficher2(QString pic)
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select codep , libelle , qtprod from bonf where pic= '"+pic+"'");
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code produit"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("Qt produit"));
    return model;
}



QSqlQueryModel * bonf::tridesc()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select pic,datebonf from bonf order by DATEBONF desc");

    return model;
}



QSqlQueryModel * bonf::rechercher(QString pic)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM bonf WHERE pic= '"+pic+"'") ;



    return model;
}
QString bonf:: apercu_pdf()
 {
     QString text="             ** La Listes Des Achats **       \n \n " ;
     QSqlQuery query ;
     QString i,x;
     QString d;
     QString e,c,h;
     int inc = 0;
      query.exec("SELECT * FROM bonf ");
      while (query.next())
      {
         i=query.value(0).toString();
          x=query.value(1).toString();
         d=query.value(2).toString();
         e=query.value(3).toString();
         c=query.value(1).toString();

         inc++;
         char
 numstr[21]; // enough to hold all numbers up to 64-bits
         QString result = itoa(inc, numstr, 10);
         text += "\n Num Piéce: "+result+"\n\n - Code Fournisseur: "+ x+"\n  - - Date Du Bon: "+ i+"\n  - Code Produit: "+d+"\n  - Libelle: "+e+"\n  - Quantité: "+c+"\n\n_________________________\n";

     }

             return text ;
 }
bool bonf::verifierId(QString pic)
{

    QSqlQuery query;
    QString n;

            query.exec("SELECT PIC from BONF");
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
