#ifndef BONF_H
#define BONF_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class bonf
{public:
    bonf();
    bonf(QString,QString,QString,QString,QString,QString);
   QString get_pic();
   QString get_codef();
    QString get_datebonf();
    QString get_codep();
    QString get_libelle();
    QString get_qtprod();


    bool ajouterbonf();
    QSqlQueryModel * afficher2(QString);
    QSqlQueryModel * afficher();

    QSqlQueryModel * tridesc();
    bool supprimer(QString);
     QSqlQueryModel *afficher_Re_produit(QString ,QString );
    bool modifier(QString,QString,QString,QString,QString,QString);
    QSqlQueryModel *rechercher(QString);
    QString  apercu_pdf();

private:
    QString pic,codef,datebonf,codep,libelle,qtprod;
};

#endif // BONF_H
