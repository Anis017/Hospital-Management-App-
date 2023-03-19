#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <direct.h>
#include <iomanip>
using namespace std;

struct patient
{
    int info;
    int cle;
    char nom[50], prenom[50];
    int age;
    char datea[11];
    char symptomes[100];
};

struct patient p;
int ajout(patient p, int r, int &nb, FILE *fp)
{

    nb = 0;
    fp = fopen("setting.txt", "ab+");
    while (fread(&p, sizeof(p), 1, fp))
    {
        if (p.cle != nb)
        {
            nb++;
        }
    }

    int l;
    l = nb;
    int c = 1;
    char autre;
    autre = 'Y';
    fseek(fp, 0, SEEK_END);
    while (autre == 'Y' || autre == 'y')
    {
        system("cls");
        if (r == 1)
        {
            p.info = 1;
        }
        if (r == 2)
        {
            p.info = 2;
        }
        if (r == 3)
        {
            p.info = 3;
        }
        if (l != 0)
        {
            p.cle = l + 1;
        }
        else
        {
            p.cle = c;
        }

        cout << "Entrer le nom : ";
        cin >> p.nom;
        cout << "Entrer le prenom : ";
        cin >> p.prenom;
        cout << "Entrer l'age    : ";
        cin >> p.age;
        while (p.age <= 0 || p.age >= 150)
        {
            cout << "age incorrect veuillez resaisir l'age: ";
            cin >> p.age;
        }
        cout << "entrer la date d'addmision (jj/mm/aa)  : ";
        cin >> p.datea;
        cout << "entrer les symptomes    : ";
        cin >> p.symptomes;
        fwrite(&p, sizeof(patient), 1, fp);
        cout << "\n Ajouter un autre patient (Y/N) ";
        fflush(stdin);
        autre = getchar();
        if (autre == 'Y' || autre == 'y')
        {
            l++;
        }
    }

    fclose(fp);
    return 0;
}
int affichp(patient p, int &nb, FILE *fp)
{
    int chx, ag;
    char da[10], path[100];
    bool trouv1 = false, trouv2 = false, trouv3 = false;

    fp = fopen("setting.txt", "rb");
    int l = 0;
    cout << "Selectionez un mode d'affichage: " << endl;
    cout << "1_ Classic (Tout les patients)" << endl;
    cout << "2_ Age" << endl;
    cout << "3_ Date d'admission " << endl;
    cout << "4_ Pathologies" << endl;
    cin >> chx;
    if (chx == 1)
    {
        system("cls");
        fseek(fp, 0, SEEK_SET);
        cout << "********** Patient hospitalise **********" << endl;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.info == 1)
            {
                cout << "============ Patient " << l + 1 << " ==============" << endl;
                cout << "\n";
                cout << "             cle: 00" << p.cle << endl;
                cout << "\n"
                     << "   - Nom: " << p.nom << "\t "
                     << "Prenom: " << p.prenom;
                cout << "\n";
                cout << "\n"
                     << "   - age: " << p.age;
                cout << "\n";
                cout << "\n"
                     << "   - Date d'admission: " << p.datea;
                cout << "\n";
                cout << "\n"
                     << "   - Symptomes: " << p.symptomes;
                cout << "\n";
                cout << "\n";
                l++;
            }
        }
    }
    if (chx == 2)
    {
        system("cls");
        cout << "Veuillez saisir l'age: ";
        cin >> ag;
        system("cls");
        fseek(fp, 0, SEEK_SET);
        cout << "********** Patient hospitalise (selon l'age) **********" << endl;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.info == 1 && p.age == ag)
            {
                cout << "============ Patient " << l + 1 << " ==============" << endl;
                cout << "\n";
                cout << "             cle: 00" << p.cle << endl;
                cout << "\n"
                     << "   - Nom: " << p.nom << "\t "
                     << "Prenom: " << p.prenom;
                cout << "\n";
                cout << "\n"
                     << "   - age: " << p.age;
                cout << "\n";
                cout << "\n"
                     << "   - Date d'admission: " << p.datea;
                cout << "\n";
                cout << "\n"
                     << "   - Symptomes: " << p.symptomes;
                cout << "\n";
                cout << "\n";
                l++;
                trouv1 = true;
            }
        }
        if (trouv1 == false)
        {
            cout << "\n\n\n\n\n";
            cout << "                Aucun patient avec cet age ";
        }
    }
    if (chx == 3)
    {
        system("cls");
        cout << "veuillez saisir la date d'admission (jj/mm/aa): ";
        cin >> da;
        system("cls");
        fseek(fp, 0, SEEK_SET);
        cout << "********** Patient hospitalise (selon la date d'admission) **********" << endl;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.info == 1 && strcmp(p.datea, da) == 0)
            {
                cout << "============ Patient " << l + 1 << " ==============" << endl;
                cout << "\n";
                cout << "             cle: 00" << p.cle << endl;
                cout << "\n"
                     << "   - Nom: " << p.nom << "\t "
                     << "Prenom: " << p.prenom;
                cout << "\n";
                cout << "\n"
                     << "   - age: " << p.age;
                cout << "\n";
                cout << "\n"
                     << "   - Date d'admission: " << p.datea;
                cout << "\n";
                cout << "\n"
                     << "   - Symptomes: " << p.symptomes;
                cout << "\n";
                cout << "\n";
                l++;
                trouv2 = true;
            }
        }
        if (trouv2 == false)
        {
            cout << "\n\n\n\n\n";
            cout << "                Aucun patient avec cette date d'admission ";
        }
    }
    if (chx == 4)
    {
        system("cls");
        cout << "Veuillez saisir la pathologie: ";
        cin >> path;
        system("cls");
        fseek(fp, 0, SEEK_SET);
        cout << "********** Patient hospitalise (selon la pathologie) **********" << endl;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.info == 1 && strcmp(p.symptomes, path) == 0)
            {
                cout << "============ Patient " << l + 1 << " ==============" << endl;
                cout << "\n";
                cout << "             cle: 00" << p.cle << endl;
                cout << "\n"
                     << "   - Nom: " << p.nom << "\t "
                     << "Prenom: " << p.prenom;
                cout << "\n";
                cout << "\n"
                     << "   - age: " << p.age;
                cout << "\n";
                cout << "\n"
                     << "   - Date d'admission: " << p.datea;
                cout << "\n";
                cout << "\n"
                     << "   - Symptomes: " << p.symptomes;
                cout << "\n";
                cout << "\n";
                l++;
                trouv3 = true;
            }
        }
        if (trouv3 == false)
        {
            cout << "\n\n\n\n\n";
            cout << "                Aucun patient avec cette pathologie ";
        }
    }
    fclose(fp);
    return 0;
}
int affichg(patient p, int &nb, FILE *fp)
{

    cout << "********** Patient gueris **********" << endl;
    int l = 0;
    fp = fopen("setting.txt", "rb");
    fseek(fp, 0, SEEK_SET);
    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        if (p.info == 2)
        {
            cout << "============ Patient " << l + 1 << " ==============" << endl;
            cout << "\n";
            cout << "             cle: 00" << p.cle << endl;
            cout << "\n"
                 << "    Nom: " << p.nom << "\t "
                 << "Prenom: " << p.prenom;
            cout << "\n";
            cout << "\n"
                 << "    age: " << p.age;
            cout << "\n";
            cout << "\n"
                 << "    Date d'admission: " << p.datea;
            cout << "\n";
            cout << "\n"
                 << "    Symptomes: " << p.symptomes;
            cout << "\n";
            cout << "\n";
            l++;
        }
    }
    fclose(fp);
    return 0;
}
int affichd(patient p, int &nb, FILE *fp)
{

    cout << "********** Patient decede **********" << endl;
    int l = 0;
    fp = fopen("setting.txt", "rb");
    fseek(fp, 0, SEEK_SET);
    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        if (p.info == 3)
        {
            cout << "============ Patient " << l + 1 << " ==============" << endl;
            cout << "\n";
            cout << "             cle: 00" << p.cle << endl;
            cout << "\n"
                 << "    Nom: " << p.nom << "\t "
                 << "Prenom: " << p.prenom;
            cout << "\n";
            cout << "\n"
                 << "    age: " << p.age;
            cout << "\n";
            cout << "\n"
                 << "    Date d'admission: " << p.datea;
            cout << "\n";
            cout << "\n"
                 << "    Symptomes: " << p.symptomes;
            cout << "\n";
            cout << "\n";
            l++;
        }
    }

    fclose(fp);
    return 0;
}
int modif(patient p, int &nb, FILE *fp)
{

    fp = fopen("setting.txt", "rb+");
    int cl;
    char autre;
    autre = 'Y';
    bool trouv = false;
    while (autre == 'Y' || autre == 'y')
    {
        system("cls");
        cout << "\n Entrer la cle du patient a modifier : ";
        cin >> cl;
        fseek(fp, 0, SEEK_SET);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (cl == p.cle)
            {
                cout << "Entrer le nom : ";
                cin >> p.nom;
                cout << "Entrer le prenom : ";
                cin >> p.prenom;
                cout << "Entrer l'age    : ";
                cin >> p.age;
                cout << "entrer la date d'addmision   : ";
                cin >> p.datea;
                cout << "entrer les symptomes    :";
                cin >> p.symptomes;
                fseek(fp, -sizeof(p), SEEK_CUR);
                fwrite(&p, sizeof(p), 1, fp);
                trouv = true;
                break;
            }
        }
        if (trouv == false)
        {
            cout << "\n patient inexistant veuillez resaisir la cle" << endl;
        }
        cout << "\n Modifier un autre patient? (Y/N) ";
        fflush(stdin);
        autre = getchar();
    }
    fclose(fp);
    return 0;
}
int sortieg(patient p, int &nb, FILE *fp)
{

    fp = fopen("setting.txt", "rb+");
    float cl;
    char autre;
    bool trouv = false;
    autre = 'Y';
    while (autre == 'Y' || autre == 'y')
    {
        system("cls");
        cout << "\n Entrer la cle du patient a deplacer vers les gueris : ";
        cin >> cl;
        fseek(fp, 0, SEEK_SET);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (cl == p.cle)
            {
                p.info = 2;
                fseek(fp, -sizeof(p), SEEK_CUR);
                fwrite(&p, sizeof(p), 1, fp);
                trouv = true;
                break;
            }
        }
        if (trouv == false)
        {
            cout << "\n patient inexistant veuillez resaisir la cle" << endl;
        }
        cout << "\n Deplacer un autre patient parmis les gueris (Y/N) ";
        fflush(stdin);
        autre = getchar();
    }
    fclose(fp);
    return 0;
}
int sortied(patient p, int &nb, FILE *fp)
{
    fp = fopen("setting.txt", "rb+");
    float cl;
    char autre;
    bool trouv = false;
    autre = 'Y';
    while (autre == 'Y' || autre == 'y')
    {
        system("cls");
        cout << "\n Entrer la cle du patient a deplacer vers les deces : ";
        cin >> cl;
        fseek(fp, 0, SEEK_SET);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (cl == p.cle)
            {
                p.info = 3;
                fseek(fp, -sizeof(p), SEEK_CUR);
                fwrite(&p, sizeof(p), 1, fp);
                trouv = true;
                break;
            }
        }
        if (trouv == false)
        {
            cout << "\n patient inexistant veuillez resaisir la cle" << endl;
        }
        cout << "\n Deplacer un autre patient parmis les deces (Y/N) ";
        fflush(stdin);
        autre = getchar();
    }
    fclose(fp);
    return 0;
}

void showMenu();
int main()
{
    FILE *f;
    int v;
    int i;
    patient p;
    char c;
    do
    {
        showMenu();
        c = getch();
        switch (c)
        {
        case '1':
            system("cls");
            ajout(p, v, i, f);
            getche();
            break;
        case '2':
            system("cls");
            modif(p, i, f);
            getche();
            break;
        case '3':
            system("cls");
            sortieg(p, i, f);
            getche();
            break;
        case '4':
            system("cls");
            sortied(p, i, f);
            getche();
            break;
        case '5':
            system("cls");
            affichp(p, i, f);
            getche();
            break;
        case '6':
            system("cls");
            affichg(p, i, f);
            getche();
            break;
        case '7':
            system("cls");
            affichd(p, i, f);
            getche();
            break;
        case '8':
            system("cls");
            int fich;
            cout << "1_ Patient" << endl;
            cout << "2_ gueris" << endl;
            cout << "3_ deces" << endl;
            cout << "veuiller entrer le fichier sur lequel travailler: ";
            cin >> fich;
            if (fich == 1)
            {
                v = 1;
            }
            if (fich == 2)
            {
                v = 2;
            }
            if (fich == 3)
            {
                v = 3;
            }
            break;
        case '9':
            system("cls");
            cout << "voulez vous quitter le programme o/n ?? ";
            cin >> c;
            break;
        }
        system("cls");
    } while (c != 'o');
    return 0;
}
void showMenu()
{
    cout << "\n\n\n\n";
    cout << "  #####################################################\n";
    cout << "     1.  Ajouter  des patients." << endl;
    cout << "     2.  Mettre a jour les informations d'un patient. " << endl;
    cout << "     3.  Sortie d'un patient pour gu\202rison " << endl;
    cout << "     4.  Sortie d'un patient d\202c\202d\202 " << endl;
    cout << "     5.  Afficher les patients hospitalis\202s" << endl;
    cout << "     6.  Afficher les patients gu\202ris" << endl;
    cout << "     7.  Afficher les patients d\202c\202d\202s." << endl;
    cout << "     8.  param\212Atres" << endl;
    cout << "     9.  Quitter." << endl;
    cout << "  #####################################################" << endl;
    cout << "\t Votre choix :   " << endl;
    cout << "NB: Avant d'ajouter des patients veuillez d'abord choisir un fichier 8  ";
}
