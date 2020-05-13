#include "menu.h"
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>

#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   menu m;
    connexion c;
    bool test=c.ouvrircnx();
        if(test)
        {m.show();
            QMessageBox::critical(nullptr, QObject::tr("Connexion avec succés"),
                        QObject::tr("Bienvenue.\n"
                                    ), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("Connexion faible"),
                        QObject::tr("Veillez rejoindre ultérieurement.\n"
                                   ), QMessageBox::Cancel);



        return a.exec();
    }


