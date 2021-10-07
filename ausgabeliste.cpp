#include "ausgabeliste.h"
#include "ui_ausgabeliste.h"

AusgabeListe::AusgabeListe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AusgabeListe)
{
    ui->setupUi(this);
}

AusgabeListe::~AusgabeListe()
{
    delete ui;
}

AusgabeListe::AusgabeListe(vector<Ort*> vec, QWidget* parent)
    : QWidget(parent),
      ui(new Ui::AusgabeListe)
{
    ui->setupUi(this);
    this->setWindowTitle("Informationen");

    for(unsigned int i=0; i<vec.size(); i++){
        ui->listWidget->addItem(vec[i]->ausgabe());
    }
}

AusgabeListe::AusgabeListe(vector<Ort*> vec, bool entfernung, QWidget* parent)
    : QWidget(parent),
      ui(new Ui::AusgabeListe)
{
    ui->setupUi(this);
    this->setWindowTitle("Entfernung");

    entfernung = true;
    double result = vec[0]->enfernung(vec[1]);
    QString ausgabe = "Entfernung zwisch " + vec[0]->getName() + " <-> " + vec[1]->getName() + ": " + QString::number(result) + "km";
    ui->listWidget->addItem(ausgabe);
}

AusgabeListe::AusgabeListe(QString aus[], unsigned int size, QWidget* parent)
    : QWidget(parent),
      ui(new Ui::AusgabeListe)
{
    ui->setupUi(this);
    this->setWindowTitle("Routing");
    for(unsigned int i=0; i<size; i++){
        ui->listWidget->addItem(aus[i] + "km");
    }
}




