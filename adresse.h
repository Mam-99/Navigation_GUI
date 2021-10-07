#ifndef ADRESSE_H
#define ADRESSE_H
#include <QString>
#include <QVector>
#include "ort.h"
using namespace std;

class Adresse : public Ort
{
private:
    QString str;
    int hnr;
    int plz;
    QString gemeinde;
public:
    Adresse(const QString& n, const double& langen, const double& breiten, const QString& s, const int& nr, const int& p, const QString& g);

    QString getStrasse() const { return str; }
    int getHausnummer() const { return hnr; }
    int getPLZ() const { return plz; }
    QString getGemeinde() const { return gemeinde; }
    QString ausgabe() override;
};

#endif // ADRESSE_H
