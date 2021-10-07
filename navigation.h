#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QMainWindow>
#include <QRadioButton>
#include <QInputDialog>
#include <QMessageBox>
#include <fstream>
#include <climits>      // for Int_Max
#include "ort.h"
#include "adresse.h"
#include "pol.h"
#include "ausgabeliste.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Navigation; }
QT_END_NAMESPACE

class Navigation : public QMainWindow
{
    Q_OBJECT

public:
    Navigation(QWidget *parent = nullptr);
    ~Navigation();

    // Hilfsfunktionen fuer Dijkstra
    int miniDist(double distance[], bool visited[]);
    void Dijkstra(double** g, int startNode);

private slots:
    void pushBtnEntfernung();
    void pushBtnInformation();
    void pushBtnAlleOrte();
    void pushBtnLoeschen();
    void pushBtnHinzufugen();
    void pushBtnRouting();
    void pushBtnLaden();
    void pushBtnSpeichern();

private:
    Ui::Navigation *ui;
    vector<Ort*> vec;
    vector<QRadioButton*> RB_List;
};
#endif // NAVIGATION_H
