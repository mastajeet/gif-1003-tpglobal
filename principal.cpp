#include <iostream>
#include "validationFormat.h"
#include "Vehicule.h"
using namespace std;



void afficherInformationVehicule(const Vehicule& p_vehicule)
{
	cout << endl ;
	cout << "-- Information sur le vehicule -------------------"<< endl ;
	cout << p_vehicule.reqVehiculeFormate() << endl;
	cout << endl ;
}

string obtenirImmatriculation()
{

	bool valid_immatriculation = false;
	string immatriculation;

	do{
		cout << "Veuillez entrer le numero d'immatriculation du vehicule" << endl;

		getline(cin,immatriculation);

		if(util::validerImmatriculation(immatriculation))
		{
			valid_immatriculation = true;
		}

	}while(!valid_immatriculation);

	return immatriculation;
}

string obtenirNumeroSerie()
{
	bool valid_niv = false;
	string niv;
	do{
		cout << "Veuillez entrer le numero de serie du vehicule" << endl;
		cin >> niv;
		if(util::validerNiv(niv))
		{
			valid_niv = true;
		}

	}while(!valid_niv);
	cin.ignore();
	return niv;
}

void modifierNumeroPlaque(Vehicule& p_vehicule)
{
	char modifierPlaque = 'N';
	string immatriculation;

	cout << "Desirez-vous modifier le numero de plaque? (O = oui, N = *non)" << endl;
	cin >> modifierPlaque;
	cin.ignore();

	if(modifierPlaque == 'O')
	{
		immatriculation = obtenirImmatriculation();
		p_vehicule.asgImmatriculation(immatriculation);
		afficherInformationVehicule(p_vehicule);
	}
}

int main() {

	string niv;
	string immatriculation;

	niv = obtenirNumeroSerie();
	immatriculation = obtenirImmatriculation();

	Vehicule mon_vehicule = Vehicule(niv,immatriculation);

	afficherInformationVehicule(mon_vehicule);
	modifierNumeroPlaque(mon_vehicule);

	cout << "Merci d'avoir utilise le createur de voiture 2000" << endl;
}




// tests
/*
 *
 *
 * cout << "NIV Valide: " << util::validerNiv("WMWMF33577TL68593")  << endl;
 *
 * validerImmatriculation("L123456") == true;
 * validerImmatriculation("L123K56") == false
 * validerImmatriculation("l123456") == false
 *
 * validerImmatriculation("000 ABC") == true
 * validerImmatriculation("123K321") == true
 * validerImmatriculation("12kK456") == false
 *
 *
 * validerImmatriculation("Z45 KED") == true
 * validerImmatriculation("LOL 418") == true
 *
 *
 *
 * appliquerTransformation("ABC44FF","1234567890") == 1234466
 * appliquerPoids("1234","1234") == 30
 *
 *
 * validerNivContientExclusionGlobale("12345678901234567") == 0
 * validerNivContientExclusionGlobale("OK123") == 1
 *
 *
 * appliquerTransformationDesLettres("ABCDEFGHIJKLMNOPQRSTUVWXYZ","12345678012345070923456789") == 12345678012345070923456789
 * validerNivContientErreurParPosition("123456787A") == 0
 * validerNivContientErreurParPosition("12345678XA") == 0
 * validerNivContientErreurParPosition("12345678XU") == 1
 * validerNivContientErreurParPosition("12345678KA") == 1
 * validerNivContientErreurParPosition("12345678KZ") == 1
 *
 *
 * const Vehicule a = Vehicule("okay_niv","that's it_immat");
 * const Vehicule b = Vehicule("okay!!!!","!!!!that's it");
 * const Vehicule c = Vehicule("okay!!!!","!!!!that's it");
 *
 * cout << (a==b) << endl;
 * cout << (a==c) << endl;
 * cout << (b==c) << endl;
 *
 * 	cout << (a.reqImmatriculation()=="that's it_immat") << endl;
 *	cout << (a.reqNiv()=="okay_niv") << endl;
 *

 */
