#ifndef MENUS_H
#define MENUS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class menus
{public:
    menus();
    menus(QString,QString,QString,QString,QString);

    QString get_code();
    QString get_nature();
    QString get_datemenu();
    QString get_qtprod();
    QString get_libelle();

    bool ajouter();
    QSqlQueryModel * afficher2(QString);
    QSqlQueryModel * afficher();

    QSqlQueryModel * tridesc();
    bool supprimer(QString,QString);
     QSqlQueryModel *afficher_Re_produit(QString ,QString );
    bool modifier(QString,QString,QString,QString,QString);
    QSqlQueryModel *rechercher(QString);

private:
    QString libelle,nature,datemenu,code,qtprod;

};
#endif // MENUS_H
