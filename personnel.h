#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>

class personnel
{ int salaire;
    QString id , departement,nom,prenom,datenaiss,dateemb;
public:
    personnel();
    personnel(QString,QString,QString ,int,QString , QString ,QString);
    QString getid();
    void setid(QString);
    // A implementer les gets et les sets
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* affecter();

    bool supprimer(QString);
    QSqlQueryModel * chercher(QString id);


    bool modifier(QString,QString,QString ,int,QString , QString ,QString);
public slots:
    int stat_moins();
    int stat_plus();
    bool verifierId(QString id);
private:

};

#endif // PERSONNEL_H
