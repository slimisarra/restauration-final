#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQueryModel>

class equipement
{
 private:
    QString reference;
    QString famille,libelle;
  public:
    QString etat;
    equipement();
    equipement(QString,QString,QString ,QString);
    QString getfamille();
    QString getlibelle();
    QString getetat();
    QString getreference();



    // A implementer les gets et les sets
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifierm(QString ,QString);
    bool supprimer(QString);
    QSqlQueryModel * chercher(QString);
     QSqlQueryModel * rechercher( QString);
      bool verifierId(QString);
};

#endif // EQUIPEMENT_H
