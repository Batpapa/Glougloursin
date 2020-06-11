#define QT_SCALE_FACTOR 5

#include "Sources/Core/grid.h"
#include "Sources/Window/mainwindow.h"

#include <QApplication>
#include <QFile>

// TODOs /////////////////////////////////////////////////////

void test()
{

}

#include <QtNetwork/QNetworkInterface>
QString getMacAddress()
{
    QList<QNetworkInterface> ni = QNetworkInterface::allInterfaces();
    for (int k = 0; k < ni.size(); ++k)
    {
        if (!(ni[k].flags() & QNetworkInterface::IsLoopBack))
        {
            return ni[k].hardwareAddress();
        }
    }
    return QString();
}
bool acceptedDevice()
{
    QString deviceMac = getMacAddress();
    QList<QString> acceptedMacList = {"D8:CB:8A:83:D5:A5"};
    for (int k = 0; k < acceptedMacList.size(); ++k)
    {
        if (deviceMac == acceptedMacList[k])
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    test();

    if (!acceptedDevice())
    {
        qWarning() << "Application unable to start.";
        return 0;
    }

    // Launch location
    QFile exe(argv[0]);
    qInfo() << "===== Starting application =====";
    qInfo() << QString("Source : %1").arg(exe.fileName());

    // Build database
    qInfo() << "Building grid...";
    Grid* grid = new Grid();
    qInfo() << "Grid built.";

    // Build window
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qputenv("QT_SCALE_FACTOR", "1");
    QApplication a(argc, argv);
    qInfo() << "Building window...";
    MainWindow w(grid);
    qInfo() << "Window built.";

    // Parse inputs
    QList<QString> inputs;
    if (argc > 1)
    {
        for (int k = 1; k < argc; ++k)
        {
            inputs.push_back(argv[k]);
        }
    }
    w.setInputs(inputs);

    w.show();
    return a.exec();
}














//    {
//        Society* s = new Society("Entreprise 1");
//        Society::Contact c;
//        c.firstName = "Jimmy";
//        c.lastName = "Mouche";
//        c.mail = "mister@mouche.fr";
//        c.phone = "0668452213";
//        c.address = "Chez Mme Vinaigrette, 163 rue du Cloître, 33400 Talence";
//        s->setContact(c);
//        database->addSociety(s);

//        {
//            Engine* e = new Engine();
//            e->setPark("T402");
//            e->setType("Pelle electro-motrice");
//            e->setImmatriculation("AB-411-TP");
//            e->setYear(1385);
//            e->setBrand("Bouzin");
//            e->setSerial("A132354-E8");
//            s->addEngine(e);

//            {
//                e->addVGP(new VGP(QDate(2019, 1, 10), 6));
//                e->VGPs().last()->addFile("test.pdf");
//                e->addVGP(new VGP(QDate(2020, 1, 15), 3));
//            }
//        }

//        {
//            Engine* e = new Engine();
//            e->setPark("P112");
//            e->setType("Fosse à purin");
//            e->setImmatriculation("AK-RT");
//            e->setYear(2015);
//            e->setBrand("Baloche");
//            e->setSerial("ELF6872");
//            s->addEngine(e);

//            {
//                e->addVGP(new VGP(QDate(2020, 1, 10), 6));
//                e->VGPs().last()->addFile("test.pdf");
//            }
//        }
//    }

//    {
//        Society* s = new Society("Entreprise 2");
//        Society::Contact c;
//        c.firstName = "Caca";
//        c.lastName = "Prout";
//        c.mail = "a@b.fr";
//        c.phone = "0645221485";
//        c.address = "Je ne sais pas où j'habite";
//        s->setContact(c);
//        database->addSociety(s);

//        {
//            Engine* e = new Engine();
//            e->setPark("T402");
//            e->setType("Pelle electro-motrice");
//            e->setImmatriculation("XR-411-TP");
//            e->setYear(1522);
//            e->setBrand("Bouzin");
//            e->setSerial("AD845");
//            s->addEngine(e);

//            {
//                e->addVGP(new VGP(QDate(2015, 7, 18), 3));
//                e->VGPs().last()->addFile("test.pdf");
//                e->addVGP(new VGP(QDate(2016, 1, 12), 6));
//            }
//        }

//        {
//            Engine* e = new Engine();
//            e->setPark("P112");
//            e->setType("Fosse à purin");
//            e->setImmatriculation("AK-RTDD4");
//            e->setYear(2015);
//            e->setBrand("Baloche");
//            e->setSerial("FR85E");
//            s->addEngine(e);

//            {
//                e->addVGP(new VGP(QDate(2018, 5, 22), 4));
//                e->VGPs().last()->addFile("test.pdf");
//            }
//        }
//    }

//    {
//        Society* s = new Society("Entreprise 3");
//        Society::Contact c;
//        c.firstName = "Cacaman";
//        c.lastName = "Prout";
//        c.mail = "caca@man.fr";
//        c.phone = "0557423510";
//        c.address = "2 rue Lavoir";
//        s->setContact(c);
//        database->addSociety(s);

//        {
//            Engine* e = new Engine();
//            e->setPark("E70");
//            e->setType("Grue auxiliaire");
//            e->setImmatriculation("RG-7");
//            e->setYear(1745);
//            e->setBrand("Mikit");
//            e->setSerial("ABB0");
//            s->addEngine(e);
//        }
//    }
