#include "connexion.h"

connexion::connexion()
{

}

bool connexion::ouvrircnx()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("bejaoui");
    db.setPassword("lefi");
    if(db.open())
        return true;

        return false;

}
void connexion::fermercnx()
{db.close();}
