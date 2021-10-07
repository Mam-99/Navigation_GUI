#include "pol.h"

Pol::Pol(const QString& n, const double& langen, const double& breiten, const QString& k, const QString& b)
    : Ort(n, langen, breiten), kategorie(k), bemerkung(b)
{

}

QString Pol::ausgabe()
{
    return Ort::ausgabe() + ": " + this->kategorie + ", " + this->bemerkung;
}
