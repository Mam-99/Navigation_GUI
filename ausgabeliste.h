#ifndef AUSGABELISTE_H
#define AUSGABELISTE_H
#include "ort.h"
#include "adresse.h"
#include "pol.h"
#include <QWidget>

namespace Ui {
class AusgabeListe;
}

class AusgabeListe : public QWidget
{
    Q_OBJECT

public:
    explicit AusgabeListe(QWidget *parent = nullptr);
    AusgabeListe(vector<Ort*> vec, QWidget* parent = nullptr);
    AusgabeListe(vector<Ort*> vec, bool entfernung, QWidget* parent = nullptr);
    AusgabeListe(QString aus[], unsigned int size, QWidget* parent = nullptr);
    ~AusgabeListe();

private:
    Ui::AusgabeListe *ui;
};

#endif // AUSGABELISTE_H
