#include "adresse.h"

Adresse::Adresse(const QString& n, const double& langen, const double& breiten, const QString& s, const int& nr, const int& p, const QString& g)
    : Ort(n, langen, breiten), str(s), hnr(nr), plz(p), gemeinde(g)
{

}

QString Adresse::ausgabe()
{
    return Ort::ausgabe() + ": " + this->str + " " + QString::number(this->hnr) + ", " + QString::number(this->plz) + " " + this->gemeinde;
}
