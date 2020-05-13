#ifndef NOMEN_H
#define NOMEN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class nomen
{public:
    nomen();
    nomen(int,int,int);
    int get_code();
    int get_codecomp();
    int get_coef();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    int code,codecomp,coef;

};


#endif // NOMEN_H
