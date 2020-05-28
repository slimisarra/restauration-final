#ifndef FOURN_H
#define FOURN_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class fourn
{public:
    fourn();
    fourn(QString,QString,QString,QString,QString,QString,QString,QString);

    QString get_code();
    QString get_adr();
     QString get_tel();
    QString get_reg();
    QString get_fax();
    QString get_mail();
    QString get_dailliv();
     QString get_modepi();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tridesc();
    bool supprimer(QString);
    bool modifier(QString,QString,QString,QString,QString,QString,QString,QString);
    QSqlQueryModel *listerfourn();
    QSqlQueryModel *rechercher(QString);
bool verifierId(QString );
private:
    QString code,adr,tel,reg,fax,mail,dailliv,modepi;

};
#endif // FOURN_H
