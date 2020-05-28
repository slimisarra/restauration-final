#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class produit
{public:
    produit();
    produit(QString,QString,QString,int,int,QString,QString);

    QString get_code();
     QString get_libelle();
    QString get_dateprod();
    int get_prix();
    int get_qt();
    QString get_catg();
    QString get_famil();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher3();
    QSqlQueryModel * tridesc();
    bool supprimer(QString);
    bool modifier(QString,QString,QString,int,int,QString,QString);
    QSqlQueryModel *listerprod();
    QSqlQueryModel *rechercher(QString);
    int stat_moins();
    int stat_plus();
    bool verifierId(QString );

private:
    QString code,libelle,catg,famil,dateprod;
    int prix,qt;
};

#endif // PRODUIT_H
