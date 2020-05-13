#include "nomen.h"
#include <QDebug>
#include "connexion.h"

nomen::nomen()
{
code=0;
codecomp=0;
coef=0;

}
nomen::nomen(int code,int codecomp,int coef)
{
  this->code=code;
  this->codecomp=codecomp;
     this->coef=coef;


}
int nomen::get_code(){return  code;}
int nomen::get_codecomp(){return  codecomp;}
int nomen::get_coef(){return  coef;}



bool nomen::ajouter()
{
QSqlQuery query;
QString rescode= QString::number(code);
QString rescodecomp= QString::number(codecomp);
QString rescoef= QString::number(coef);
query.prepare("INSERT INTO nomen (CODE, CODECOMP, COEF) "
                    "VALUES (:code, :codecomp, :coef )");
query.bindValue(":code", rescode);
query.bindValue(":codecomp", rescodecomp);
query.bindValue(":coef", rescoef);



return    query.exec();
}

