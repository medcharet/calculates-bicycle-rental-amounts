#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  if (debut < 0 || debut > 24 || fin < 0 || fin > 24) {
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    return 1;
  } else if (debut == fin) {
    cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
    return 1;
  } else if (debut > fin) {
    cout << "Bizarre, le début de la location est après la fin ..." << endl;
    return 1;
  }

  int duree_location = fin - debut;
  int tarif_horaire;
  int montant_total = 0;

  if (debut >= 0 && fin <= 7 || debut >= 17 && fin <= 24) {
    tarif_horaire = 1;
    montant_total = duree_location;
    cout << "Vous avez loué votre vélo pendant "<<endl << duree_location << " heure(s) au tarif horaire de 1 franc(s)" << endl;
  } else if (debut >= 7 && fin <= 17) {
    tarif_horaire = 2;
    montant_total = duree_location * 2;
    cout << "Vous avez loué votre vélo pendant "<<endl << duree_location << " heure(s) au tarif horaire de 2 franc(s)" << endl;

  } else if (debut < 7 && fin > 17) {
    tarif_horaire = 1;
    int duree_location1 = 7 - debut;
    int duree_location2 = fin - 17;
    montant_total = duree_location1 + duree_location2 + 20;
    cout << "Vous avez loué votre vélo pendant "<<endl << duree_location1+duree_location2 << " heure(s) au tarif horaire de " << tarif_horaire << " franc(s)" << endl;
    cout << 10 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
  } else if (debut < 7 && fin > 7 && fin <= 17) {
    tarif_horaire = 1;
    int duree_location1 = 7 - debut;
    int duree_location2 = fin - 7;
    montant_total = duree_location1 + duree_location2 * 2;
    cout << "Vous avez loué votre vélo pendant "<<endl << duree_location1 << " heure(s) au tarif horaire de " << tarif_horaire << " franc(s)" << endl;
    cout << duree_location2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
  } else if (debut >= 7 && debut < 17 && fin > 17 && fin <= 24) {
    int duree_location1 = 17 - debut;
    int duree_location2 = fin - 17;
    montant_total = duree_location1 * 2 + duree_location2;
    cout << "Vous avez loué votre vélo pendant "<<endl << duree_location2 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
    cout << duree_location1 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
  }

  cout << "Le montant total à payer est de " << montant_total << " franc(s)." << endl;

  return 0;
}