#include "fourn.h"

#include <QDebug>
#include "connexion.h"
fourn::fourn()
{
code="";
adr="";
tel="";
reg="";
fax="";
mail="";
dailliv="";
modepi="";
}
fourn::fourn(QString code,QString adr,QString tel,QString reg,QString fax,QString mail,QString dailliv,QString modepi)
{
  this->code=code;
  this->adr=adr;
  this->tel=tel;
  this->reg=reg;
     this->fax=fax;
     this->mail=mail;
     this->dailliv=dailliv;
    this->modepi=modepi;
}

QString fourn::get_code(){return  code;}
QString fourn::get_adr(){return  adr;}
QString fourn::get_tel(){return  tel;}
QString fourn::get_reg(){return  reg;}
QString fourn::get_fax(){return  fax;}
QString fourn::get_mail(){return  mail;}
QString fourn::get_dailliv(){return  dailliv;}
QString fourn::get_modepi(){return  modepi;}


bool fourn::ajouter()
{
QSqlQuery query;


query.prepare("INSERT INTO fourn (CODE , ADR , TEL , REG , FAX , MAIL , DAILLIV , MODEPI) "
                    "VALUES (:code , :adr , :tel , :reg , :fax , :mail , :dailliv , :modepi)");
query.bindValue(":code", code);
query.bindValue(":adr", adr);
query.bindValue(":tel", tel);
query.bindValue(":reg", reg);
query.bindValue(":fax", fax);
query.bindValue(":mail", mail);
query.bindValue(":dailliv", dailliv);
query.bindValue(":modepi", modepi);
return    query.exec();
}

QSqlQueryModel * fourn::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fourn");

    return model;
}


bool fourn::supprimer(QString code )
{
QSqlQuery query;

query.prepare("Delete from fourn where CODE = :code  ");
query.bindValue(":code", code);

return    query.exec();
}
bool fourn::modifier( QString code,QString adr,QString tel,QString reg,QString fax,QString mail,QString dailliv,QString modepi){
    QSqlQuery query;


    query.prepare("UPDATE fourn SET  ADR = :adr, TEL = :tel  , FAX= :fax , MAIL= :mail , DAILLIV= :dailliv , MODEPI= :modepi WHERE CODE = :code ");
    query.bindValue(":code", code);
    query.bindValue(":adr", adr);
    query.bindValue(":tel", tel);
    query.bindValue(":reg", reg);
    query.bindValue(":fax", fax);
    query.bindValue(":mail", mail);
    query.bindValue(":dailliv", dailliv);
    query.bindValue(":modepi", modepi);
    return  query.exec();
}

QSqlQueryModel *fourn::listerfourn()
{

    QSqlQueryModel *model = new QSqlQueryModel();
                            model->setQuery("select code from fourn");
                       return model;
                     }




QSqlQueryModel * fourn::tridesc()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fourn order by code desc");

    return model;
}


QSqlQueryModel * fourn::rechercher(QString code)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM fourn WHERE code= '"+code+"'") ;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tel"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Région"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Fax"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Dailliv"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Modepi"));


    return model;
}
