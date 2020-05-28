#ifndef BONI_H
#define BONI_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class boni
{public:
    boni();
    boni(QString,QString,QString,QString,QString);
   QString get_pic();
    QString get_dateboni();
    QString get_codep();
    QString get_libelle();
    QString get_qtprod();


    bool ajouter();
    QSqlQueryModel * afficher2(QString);
    QSqlQueryModel * afficher();

    QSqlQueryModel * tridesc();
    bool supprimer(QString);
     QSqlQueryModel *afficher_Re_produit(QString ,QString );
    bool modifier(QString,QString,QString,QString,QString);
    QSqlQueryModel *rechercher(QString);
    QString  apercu_pdf();
    bool verifierId(QString );

private:
    QString pic,dateboni,codep,libelle,qtprod;
};

#endif // BONI_H
