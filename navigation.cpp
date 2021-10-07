#include "navigation.h"
#include "ui_navigation.h"

Navigation::Navigation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Navigation)
{
    ui->setupUi(this);
    this->setWindowTitle("navigationssystem");

    connect(ui->Loeschen, SIGNAL(released()), this, SLOT(pushBtnLoeschen()));
    connect(ui->Hinzufugen, SIGNAL(released()), this, SLOT(pushBtnHinzufugen()));
    connect(ui->Entfernung, SIGNAL(released()), this, SLOT(pushBtnEntfernung()));
    connect(ui->Information, SIGNAL(released()), this, SLOT(pushBtnInformation()));
    connect(ui->AlleOrte, SIGNAL(released()), this, SLOT(pushBtnAlleOrte()));
    connect(ui->Routing, SIGNAL(released()), this, SLOT(pushBtnRouting()));
    connect(ui->Laden, SIGNAL(released()), this, SLOT(pushBtnLaden()));
    connect(ui->Speichern, SIGNAL(released()), this, SLOT(pushBtnSpeichern()));

    Ort* Kiel = new Ort("Kiel", 10.135555, 54.3227085);                     // 0 Kiel
    Ort* Schwerin = new Ort("Schwerin", 11.4148038, 53.6288297);            // 1 Schwerin
    Ort* Hamburg = new Ort("Hamburg", 10.000654, 53.550341);                // 2 Hamburg
    Ort* Bremen = new Ort("Bremen", 8.8071646, 53.0758196);                 // 3 Bremen
    Ort* Hannover = new Ort("Hannover", 9.7385532, 52.3744779);             // 4 Hannover
    Ort* Magdeburg = new Ort("Magdeburg", 11.6399609, 52.1315889);          // 5 Magdeburg
    Ort* Berlin = new Ort("Berlin", 13.3888599, 52.5170365);                // 6 Berlin
    Ort* Potsdam = new Ort("Potsdam", 13.0591397, 52.4009309);              // 7 Potsdam
    Ort* Cottbus = new Ort("Cottbus", 14.3357307, 51.7567447);              // 8 Cottbus
    Ort* Dresden = new Ort("Dresden", 13.7381437, 51.0493286);              // 9 Dresden
    Ort* Chemnitz = new Ort("Chemnitz", 12.9252977, 50.8322608);            // 10 Chemnitz
    Ort* Erfurt = new Ort("Erfurt", 11.0287364, 50.9777974);                // 11 Erfurt
    Ort* Kassel = new Ort("Kassel", 9.4924096, 51.3154546);                 // 12 Kassel
    Ort* Dusseldorf = new Ort("Dusseldorf", 6.7763137, 51.2254018);         // 13 Dusseldorf
    Ort* Koblenz = new Ort("Koblenz", 7.5943951, 50.3533278);               // 14 Koblenz
    Ort* Wiesbaden = new Ort("Wiesbaden", 8.2416556, 50.0820384);           // 15 Wiesbaden
    Ort* Wurzburg = new Ort("Wurzburg", 9.932966, 49.79245);                // 16 Wurzburg
    Ort* Nurnberg = new Ort("Nurnberg", 11.077298, 49.453872);              // 17 Nurnberg
    Pol* H_da = new Pol("H_da", 8.637914657592773, 49.8663444519043, "Hochschule", "Bildung");      // 18 H_da
    Ort* Mainz = new Ort("Mainz", 8.2762513, 50.0012314);                   // 19 Mainz
    Ort* Saarbrucken = new Ort("Saarbrucken", 6.996379, 49.234362);         // 20 Saarbrucken
    Ort* Stuttgart = new Ort("Stuttgart", 9.1800132, 48.7784485);           // 21 Stuttgart
    Ort* Ulm = new Ort("Ulm", 9.9934336, 48.3974003);                       // 22 Ulm
    Ort* Augsburg = new Ort("Augsburg", 10.8986971, 48.3668041);            // 23 Augsburg
    Ort* Munchen = new Ort("Munchen", 11.5753822, 48.1371079);              // 24 Munchen
    Ort* Konstanz = new Ort("Konstanz", 9.1750718, 47.659216);              // 25 Konstanz
    Ort* Freiburg = new Ort("Freiburg", 7.8494005, 47.9960901);             // 26 Freiburg

    // Kiel
    Kiel->addNachbar(Hamburg);
    Kiel->addNachbar(Schwerin);
    vec.push_back(Kiel);
    RB_List.push_back(ui->Kiel);

    // Schwerin
    Schwerin->addNachbar(Kiel);
    Schwerin->addNachbar(Hamburg);
    Schwerin->addNachbar(Hannover);
    Schwerin->addNachbar(Magdeburg);
    Schwerin->addNachbar(Berlin);
    vec.push_back(Schwerin);
    RB_List.push_back(ui->Schwerin);

    // Hamburg
    Hamburg->addNachbar(Kiel);
    Hamburg->addNachbar(Schwerin);
    Hamburg->addNachbar(Hannover);
    Hamburg->addNachbar(Bremen);
    vec.push_back(Hamburg);
    RB_List.push_back(ui->Hamburg);

    // Bremen
    Bremen->addNachbar(Hamburg);
    Bremen->addNachbar(Hannover);
    Bremen->addNachbar(Dusseldorf);
    vec.push_back(Bremen);
    RB_List.push_back(ui->Bremen);

    // Hannover
    Hannover->addNachbar(Bremen);
    Hannover->addNachbar(Hamburg);
    Hannover->addNachbar(Schwerin);
    Hannover->addNachbar(Magdeburg);
    Hannover->addNachbar(Erfurt);
    Hannover->addNachbar(Kassel);
    Hannover->addNachbar(Dusseldorf);
    vec.push_back(Hannover);
    RB_List.push_back(ui->Hannover);

    // Magdeburg
    Magdeburg->addNachbar(Hannover);
    Magdeburg->addNachbar(Schwerin);
    Magdeburg->addNachbar(Potsdam);
    Magdeburg->addNachbar(Erfurt);
    vec.push_back(Magdeburg);
    RB_List.push_back(ui->Magdeburg);

    // Berlin
    Berlin->addNachbar(Schwerin);
    Berlin->addNachbar(Potsdam);
    Berlin->addNachbar(Cottbus);
    vec.push_back(Berlin);
    RB_List.push_back(ui->Berlin);

    // Potsdam
    Potsdam->addNachbar(Berlin);
    Potsdam->addNachbar(Cottbus);
    Potsdam->addNachbar(Magdeburg);
    vec.push_back(Potsdam);
    RB_List.push_back(ui->Potsdam);

    // Cottbus
    Cottbus->addNachbar(Berlin);
    Cottbus->addNachbar(Potsdam);
    Cottbus->addNachbar(Erfurt);
    Cottbus->addNachbar(Dresden);
    vec.push_back(Cottbus);
    RB_List.push_back(ui->Cottbus);

    // Dresden
    Dresden->addNachbar(Cottbus);
    Dresden->addNachbar(Erfurt);
    Dresden->addNachbar(Chemnitz);
    vec.push_back(Dresden);
    RB_List.push_back(ui->Dresden);

    // Chemnitz
    Chemnitz->addNachbar(Dresden);
    Chemnitz->addNachbar(Erfurt);
    Chemnitz->addNachbar(Wurzburg);
    Chemnitz->addNachbar(Nurnberg);
    vec.push_back(Chemnitz);
    RB_List.push_back(ui->Chemnitz);

    // Erfurt
    Erfurt->addNachbar(Hannover);
    Erfurt->addNachbar(Magdeburg);
    Erfurt->addNachbar(Cottbus);
    Erfurt->addNachbar(Dresden);
    Erfurt->addNachbar(Chemnitz);
    Erfurt->addNachbar(Wurzburg);
    Erfurt->addNachbar(Kassel);
    vec.push_back(Erfurt);
    RB_List.push_back(ui->Erfurt);

    // Kassel
    Kassel->addNachbar(Hannover);
    Kassel->addNachbar(Erfurt);
    Kassel->addNachbar(Wurzburg);
    Kassel->addNachbar(Wiesbaden);
    Kassel->addNachbar(Koblenz);
    Kassel->addNachbar(Dusseldorf);
    vec.push_back(Kassel);
    RB_List.push_back(ui->Kassel);

    // Dusseldorf
    Dusseldorf->addNachbar(Bremen);
    Dusseldorf->addNachbar(Hannover);
    Dusseldorf->addNachbar(Kassel);
    Dusseldorf->addNachbar(Koblenz);
    Dusseldorf->addNachbar(Saarbrucken);
    vec.push_back(Dusseldorf);
    RB_List.push_back(ui->Dusseldorf);

    // Koblenz
    Koblenz->addNachbar(Dusseldorf);
    Koblenz->addNachbar(Kassel);
    Koblenz->addNachbar(Mainz);
    Koblenz->addNachbar(Saarbrucken);
    vec.push_back(Koblenz);
    RB_List.push_back(ui->Koblenz);

    // Wiesbaden
    Wiesbaden->addNachbar(Kassel);
    Wiesbaden->addNachbar(Koblenz);
    Wiesbaden->addNachbar(Mainz);
    vec.push_back(Wiesbaden);
    RB_List.push_back(ui->Wiesbaden);

    // Wurzburg
    Wurzburg->addNachbar(Kassel);
    Wurzburg->addNachbar(Erfurt);
    Wurzburg->addNachbar(Chemnitz);
    Wurzburg->addNachbar(Nurnberg);
    Wurzburg->addNachbar(Munchen);
    Wurzburg->addNachbar(Ulm);
    Wurzburg->addNachbar(Stuttgart);
    Wurzburg->addNachbar(H_da);
    vec.push_back(Wurzburg);
    RB_List.push_back(ui->Wurzburg);

    // Nurnberg
    Nurnberg->addNachbar(Wurzburg);
    Nurnberg->addNachbar(Chemnitz);
    Nurnberg->addNachbar(Munchen);
    vec.push_back(Nurnberg);
    RB_List.push_back(ui->Nurnberg);

    // H_da
    H_da->addNachbar(Mainz);
    H_da->addNachbar(Wurzburg);
    H_da->addNachbar(Stuttgart);
    H_da->addNachbar(Saarbrucken);
    vec.push_back(H_da);
    RB_List.push_back(ui->h_da);

    // Mainz
    Mainz->addNachbar(Koblenz);
    Mainz->addNachbar(Wiesbaden);
    Mainz->addNachbar(H_da);
    Mainz->addNachbar(Saarbrucken);
    vec.push_back(Mainz);
    RB_List.push_back(ui->Mainz);

    // Saarbrucken
    Saarbrucken->addNachbar(Dusseldorf);
    Saarbrucken->addNachbar(Koblenz);
    Saarbrucken->addNachbar(Mainz);
    Saarbrucken->addNachbar(H_da);
    Saarbrucken->addNachbar(Stuttgart);
    vec.push_back(Saarbrucken);
    RB_List.push_back(ui->Saarbrucken);

    // Stuttgart
    Stuttgart->addNachbar(H_da);
    Stuttgart->addNachbar(Wurzburg);
    Stuttgart->addNachbar(Ulm);
    Stuttgart->addNachbar(Freiburg);
    Stuttgart->addNachbar(Saarbrucken);
    vec.push_back(Stuttgart);
    RB_List.push_back(ui->Stuttgart);

    // Ulm
    Ulm->addNachbar(Stuttgart);
    Ulm->addNachbar(Wurzburg);
    Ulm->addNachbar(Augsburg);
    Ulm->addNachbar(Konstanz);
    vec.push_back(Ulm);
    RB_List.push_back(ui->Ulm);

    // Augsburg
    Augsburg->addNachbar(Ulm);
    Augsburg->addNachbar(Munchen);
    Augsburg->addNachbar(Konstanz);
    vec.push_back(Augsburg);
    RB_List.push_back(ui->Augsburg);

    // Munchen
    Munchen->addNachbar(Nurnberg);
    Munchen->addNachbar(Wurzburg);
    Munchen->addNachbar(Augsburg);
    vec.push_back(Munchen);
    RB_List.push_back(ui->Munchen);

    // Konstanz
    Konstanz->addNachbar(Ulm);
    Konstanz->addNachbar(Augsburg);
    Konstanz->addNachbar(Freiburg);
    vec.push_back(Konstanz);
    RB_List.push_back(ui->Konstanz);

    // Freiburg
    Freiburg->addNachbar(Stuttgart);
    Freiburg->addNachbar(Konstanz);
    vec.push_back(Freiburg);
    RB_List.push_back(ui->Freiburg);
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::pushBtnLaden()
{
    string fileName{"ort.txt"};
    vec.clear();
    ifstream read{fileName.c_str(), ios::in};
    if(!read){
        QMessageBox ausgabe;
        ausgabe.setText("Datei kann nicht geoeffnet werden!");
        ausgabe.exec();
    }

    string leer{""};
    while(true){
        string name;
        getline(read, name, ';');
        if(name == "Adresse"){
            getline(read, name, ';');
            string langen;
            getline(read, langen, ';');
            string breiten;
            getline(read, breiten, ';');
            string str;
            getline(read, str, ';');
            string hnr;
            getline(read, hnr, ';');
            string plz;
            getline(read, plz,';');
            string gemeinde;
            getline(read, gemeinde, '\n');

            Adresse* adr = new Adresse(QString::fromStdString(name), stod(langen), stod(breiten),
                                       QString::fromStdString(str), stoi(hnr), stoi(plz), QString::fromStdString(gemeinde));
            vec.push_back(adr);
        }
        else if(name == "Poi"){
            getline(read, name, ';');
            string langen;
            getline(read, langen, ';');
            string breiten;
            getline(read, breiten, ';');
            string kategorie;
            getline(read, kategorie, ';');
            string bemerkung;
            getline(read, bemerkung, '\n');

            Pol* pol = new Pol(QString::fromStdString(name), stod(langen), stod(breiten),
                               QString::fromStdString(kategorie), QString::fromStdString(bemerkung));
            vec.push_back(pol);
        }
        else if(name == leer){
            break;
        }
        else{
            string langen;
            getline(read, langen, ';');
            string breiten;
            getline(read, breiten, '\n');

            Ort* ort = new Ort(QString::fromStdString(name), stod(langen), stod(breiten));
            vec.push_back(ort);
        }
    }

    QMessageBox ausgabe;
    ausgabe.setText("Laden erfolgreich!");
    ausgabe.exec();
    read.close();
}

int Navigation::miniDist(double *distance, bool *visited)
{
    double minimum = INT_MAX;
    int index;

    for(unsigned int i=0; i<vec.size(); i++){
        if(visited[i] == false and distance[i] <= minimum){
            minimum = distance[i];
            index = i;
        }
    }
    return index;
}

void Navigation::Dijkstra(double **g, int startNode)
{
    double distance[vec.size()];
    bool visited[vec.size()];

    for(unsigned int i=0; i<vec.size(); i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[startNode] = 0;
    for(unsigned int k = 0; k < vec.size(); k++)
    {
        int m = miniDist(distance, visited);
        visited[m]=true;
        for(unsigned int l = 0; l < vec.size(); l++)
        {
            // updating the distance of neighbouring vertex
            if(!visited[l] && g[m][l] && distance[m]!=INT_MAX && distance[m]+g[m][l]<distance[l])
                distance[l]=distance[m]+g[m][l];
        }
    }

    QString ausgabe[vec.size()];
    for(unsigned int i=0; i<vec.size(); i++){
        if((unsigned int)startNode == i) continue;
        else {
            ausgabe[i] = "Dijkstra: " + vec[startNode]->getName() + " - " + vec[i]->getName() + ": " + QString::number(distance[i]);
        }
    }
    AusgabeListe* aus = new AusgabeListe(ausgabe, vec.size());
    aus->show();
}

void Navigation::pushBtnRouting()
{
    int count = 0;      // Darf nur 2 Ort ausgewaehlt werden
    int index;
    for(unsigned int i=0; i<RB_List.size(); i++){
        if(RB_List[i]->isChecked()){
            for(unsigned int t=0; t<vec.size(); t++){
                if(RB_List[i]->text() == vec[t]->getName()){
                    count++;
                    index = i;
                    break;
                }
            }
        }
    }

    if(count == 1){
        double** graph;       // Dijkstra mit diesem Graph
        graph = new double*[vec.size()];
        for(unsigned int i=0; i<vec.size(); i++){
            graph[i] = new double[vec.size()];
        }

        for(unsigned int i=0; i<vec.size(); i++){
            for(unsigned int y=0; y<vec.size(); y++){
                graph[i][y] = 0;
            }
        }

        for(unsigned int i=0; i<vec.size(); i++){
            for(unsigned int y=0; y<vec.size(); y++){
                if(i != y){
                    for(unsigned int t=0; t<vec[i]->nachbarList.size(); t++){
                        if(vec[y]->getName() == vec[i]->nachbarList[t].first->getName()){
                            graph[i][y] = vec[i]->nachbarList[t].second;
                            graph[y][i] = vec[i]->nachbarList[t].second;
                        }
                    }
                }
            }
        }

        Dijkstra(graph, index);
        QString aus[vec.size()];
        for(unsigned int i=0; i<vec.size(); i++){
            for(unsigned int y=0; y<vec.size(); y++){
                aus[i] += QString::number(graph[i][y]) + "\t";
            }
        }
        AusgabeListe* ausgabe = new AusgabeListe(aus, vec.size());
        ausgabe->show();
    }
    else{
        QMessageBox ausgabe;
        ausgabe.setText("Es darf nur 1 Ort ausgewaehlt werden!");
        ausgabe.exec();
    }
}

void Navigation::pushBtnAlleOrte()
{
    AusgabeListe* ausgabe = new AusgabeListe(vec);
    ausgabe->show();
}

void Navigation::pushBtnLoeschen()
{

}

void Navigation::pushBtnSpeichern()
{
    string fileName{"ort.txt"};
    ofstream save{fileName.c_str(), ios::out | ios::trunc};
    if(!save){
        QMessageBox ausgabe;
        ausgabe.setText("Datei kann nicht geoeffnet werden!");
        ausgabe.exec();
    }

    Adresse* adr;
    Pol* pol;
    for(unsigned int i=0; i<vec.size(); i++){
        if((adr = dynamic_cast<Adresse*>(vec[i]))){
            save << "Adresse;";
            string name = vec[i]->getName().toStdString();
            save << name << ";" << vec[i]->getLangengrad() << ";" << vec[i]->getBreitengrad() << ";";
            save << adr->getStrasse().toStdString() << ";" << adr->getHausnummer()
                 << ";" << adr->getPLZ() << ";" << adr->getGemeinde().toStdString() << endl;
        }
        else if((pol = dynamic_cast<Pol*>(vec[i]))){
            save << "Poi;";
            string name = vec[i]->getName().toStdString();
            save << name << ";" << vec[i]->getLangengrad() << ";" << vec[i]->getBreitengrad() << ";";
            save << pol->getKategorie().toStdString() << ";" << pol->getBemerkung().toStdString() << endl;
        }
        else{
            string name = vec[i]->getName().toStdString();
            save << name << ";" << vec[i]->getLangengrad() << ";" << vec[i]->getBreitengrad() << endl;
        }
    }

    QMessageBox ausgabe;
    ausgabe.setText("Speichern erfolgreich!");
    ausgabe.exec();
    save.close();
}

void Navigation::pushBtnEntfernung()
{
    vector<Ort*> checked;
    int count = 0;
    for(unsigned int i=0; i<RB_List.size(); i++){
        if(RB_List[i]->isChecked()){
            for(unsigned int t=0; t<vec.size(); t++){
                if(RB_List[i]->text() == vec[i]->getName()){
                    checked.push_back(vec[i]);
                    count++;
                    break;
                }
            }
        }
    }
    if(count == 2){
        AusgabeListe* ausgabe = new AusgabeListe(checked, true);
        ausgabe->show();
    }
}

void Navigation::pushBtnHinzufugen()
{
    QString name = QInputDialog::getText(this, "Name des Ortes", "Name des Ortes");
    QString langen = QInputDialog::getText(this, "Langengrad", "Langengrad");
    QString breiten = QInputDialog::getText(this, "Breitengrad", "Breitengrad");
    QString ort = QInputDialog::getText(this, "Adresse oder Poi", "Handelt es sich um eine Adresse oder Pol?");
    if(ort == "Adresse" or ort == "adresse"){
        QString str = QInputDialog::getText(this, "Strasse", "Strasse");
        QString hnr = QInputDialog::getText(this, "Hausnummer", "Hausnummmer");
        QString plz = QInputDialog::getText(this, "PLZ", "PLZ");
        QString gemeinde = QInputDialog::getText(this, "Gemeinde", "Gemeinde");

        Adresse* adr = new Adresse(name, langen.toDouble(), breiten.toDouble(), str, hnr.toInt(), plz.toInt(), gemeinde);
        vec.push_back(adr);
    }
    else if(ort == "Poi" or ort == "POI" or ort == "poi"){
        QString kategorie = QInputDialog::getText(this, "Kategorie", "Kategorie");
        QString bemerkung = QInputDialog::getText(this, "Bemerkung", "Bemerkung");

        Pol* pol = new Pol(name, langen.toDouble(), breiten.toDouble(), kategorie, bemerkung);
        vec.push_back(pol);
    }
    else{
        QMessageBox ausgabe;
        ausgabe.setText("Falsche Eingabe");
        ausgabe.exec();
    }
}

void Navigation::pushBtnInformation()
{
    vector<Ort*> checked;
    for(unsigned int i=0; i<RB_List.size(); i++){
        if(RB_List[i]->isChecked()){
            for(unsigned int t=0; t<vec.size(); t++){
                if(RB_List[i]->text() == vec[i]->getName()){
                    checked.push_back(vec[i]);
                    break;
                }
            }
        }
    }

    AusgabeListe* ausgabe = new AusgabeListe(checked);
    ausgabe->show();
}





















