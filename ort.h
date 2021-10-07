#ifndef ORT_H
#define ORT_H
#include <QString>
#include <QVector>
using namespace std;

class Ort
{
private:
    QString name;
    double langengrad;
    double breitengrad;
    bool checked = false;
public:
    Ort(const QString& n, const double& langen, const double& breiten);

    QString getName() const { return name; }
    double getLangengrad() const { return langengrad; }
    double getBreitengrad() const { return breitengrad; }

    double enfernung(Ort* other);
    void addNachbar(Ort* other);
    virtual QString ausgabe();

    vector<pair<Ort*, double>> nachbarList;
};

#endif // ORT_H
