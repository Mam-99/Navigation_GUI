#ifndef POL_H
#define POL_H
#include <QString>
#include <QVector>
#include "ort.h"
using namespace std;

class Pol : public Ort
{
private:
    QString kategorie;
    QString bemerkung;
public:
    Pol(const QString& n, const double& langen, const double& breiten, const QString& k, const QString& b);

    QString getKategorie() const { return kategorie; }
    QString getBemerkung() const { return bemerkung; }

    QString ausgabe() override;
};

#endif // POL_H
