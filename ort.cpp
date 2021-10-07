#include "ort.h"
#include "math.h"

Ort::Ort(const QString& n, const double& langen, const double& breiten)
    : name(n), langengrad(langen), breitengrad(breiten)
{

}

QString Ort::ausgabe()
{
    return this->getName() + " (" + QString::number(this->langengrad) + " | " + QString::number(this->breitengrad) + ")";
}

double Ort::enfernung(Ort *other)
{
    double distance{};
    double dx = 71.5 * (this->langengrad - other->langengrad);
    double dy = 111.3 * (this->breitengrad - other->breitengrad);
    distance = sqrt(dx * dx + dy * dy);
    return distance;
}

void Ort::addNachbar(Ort *other)
{
    pair<Ort*, double> newOrt = make_pair(other, this->enfernung(other));
    nachbarList.push_back(newOrt);
}
