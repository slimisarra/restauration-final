#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QWidget>
#include <QString>
class departement
{

private:

     QString nom_d , num;


public:
   departement();
   departement(QString,QString);

      QString get_num();
      QString get_nomd();


    bool ajouterdepartement();
    QSqlQueryModel * afficherdepartement();
      QSqlQueryModel * afficher2(QString);
    bool supprimerdepartement(QString);
      QSqlQueryModel * chercherdepart(QString id);
    bool modifierdepartement(QString,QString);
      bool modifiernb();

      bool verifierNum(QString num);
};

#endif // DEPARTEMENT_H
