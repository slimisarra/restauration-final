#ifndef VENDRE_H
#define VENDRE_H
#include <QString>
#include <QSqlQueryModel>

class vendre
{
 private:
    QString referencev;
    int prix;
    QString acheteur;
    QString libellev;
public:
    vendre();
    vendre(QString,QString, QString, int);
    QString getreferencev();
    QString getlibellev();
    QString getacheteur();
    int getprix();
    // A implementer les gets et les sets
     bool ajouterv();
    QSqlQueryModel* afficherv();
    QSqlQueryModel* listerlibv();
    QSqlQueryModel* listerrefv();
    void listerch();
    QSqlQueryModel* listerprix();
    int stat_moins();
    int stat_plus();
    QString apercu_pdf();
    bool verifierId(QString);
};

#endif // VENDRE_H
