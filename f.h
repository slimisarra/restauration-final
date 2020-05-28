#ifndef F_H
#define F_H

#include <QDialog>
#include "equipement.h"
#include "maintenance.h"
#include "vendre.h"
namespace Ui {
class f;
}

class f : public QDialog
{
    Q_OBJECT

public:
    explicit f(QWidget *parent = nullptr);
    ~f();
private slots:

    void on_ajoutertous_clicked();

    void on_ajoutermaintenance_clicked();

    void on_refresh_clicked();

    void on_refresh_clicked(bool checked);

    void on_ajoutervendre_clicked();

    void on_modifer_clicked();

    void on_supprimer_clicked();

    void on_chercher_editingFinished();

    void on_chercher_textEdited(const QString &arg1);

    void on_chercher2_clicked();

    void on_trier_activated(const QString &arg1);

    void on_trier_activated(int index);

    void on_facture_clicked();

    void on_trier_currentIndexChanged(const QString &arg1);

    void on_trier_currentIndexChanged(int index);

    void on_trier_clicked();

    void on_eq_clicked();

    void on_maintenir_7_clicked();

    void on_vendre_3_clicked();

    void on_pushButton_221_clicked();

    void on_pushButton_283_clicked();

    void on_equip_clicked();

    void on_pushButton_235_clicked();

    void on_pushButton_233_clicked();

    void on_pushButton_240_clicked();

    void on_maintenir_clicked();

    void on_maintenir_2_clicked();

    void on_pushButton_254_clicked();

    void on_maintenir_3_clicked();

    void on_pushButton_263_clicked();

    void on_maintenir_5_clicked();

    void on_pushButton_270_clicked();

    void on_maintenir_8_clicked();

    void on_vendre_clicked();

    void on_equip_2_clicked();

    void on_vendre_2_clicked();

    void on_pushButton_246_clicked();

    void on_equip_3_clicked();

    void on_maintenir_4_clicked();

    void on_pushButton_253_clicked();

    void on_pushButton_255_clicked();

    void on_equip_4_clicked();

    void on_maintenir_6_clicked();

    void on_pushButton_262_clicked();

    void on_pushButton_273_clicked();

    void on_pushButton_264_clicked();

    void on_equip_6_clicked();

    void on_maintenir_9_clicked();

    void on_pushButton_269_clicked();

    void on_equip_7_clicked();

    void on_maintenir_10_clicked();

    void on_maintenir_11_clicked();

    void on_pushButton_271_clicked();

    void on_pushButton_223_clicked();

    void on_pushButton_272_clicked();

    void on_pushButton_282_clicked();

    void on_equip_8_clicked();

    void on_maintenir_12_clicked();

    void on_maintenir_13_clicked();

    void on_pushButton_274_clicked();

    void on_pushButton_275_clicked();

    void on_maintenir_19_clicked();

    void on_pushButton_18_clicked();

    void on_maintenir_15_clicked();

    void on_maintenir_17_clicked();

    void on_pushButton_227_clicked();

    void on_pushButton_229_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_285_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_287_clicked();

    void on_pushButton_288_clicked();

    void on_pushButton_286_clicked();

    void on_equip_11_clicked();

    void on_equip_9_clicked();

    void on_equip_10_clicked();

    void on_maintenir_18_clicked();

    void on_maintenir_14_clicked();

    void on_maintenir_16_clicked();

    void makePlot();
    void on_pushButton_225_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_customPlot_customContextMenuRequested(const QPoint &pos);

    void on_cher_clicked();

    void on_cher_windowIconTextChanged(const QString &iconText);

    void on_cher_windowTitleChanged(const QString &title);

    void on_refreshm_clicked();

    void on_refreshm_2_clicked();

    void on_refreshv_clicked();

    void on_refreshv_2_clicked();

    void on_pushButton_230_clicked();

    void on_pushButton_232_clicked();

    void on_pushButton_228_clicked();

    void on_pushButton_231_clicked();

private:
    Ui::f *ui;
    equipement tmp;
    maintenance tmp1;
    vendre tmp2;
};

#endif // F_H
