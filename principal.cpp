#include <iostream>
#include "validationFormat.h"
using namespace std;

int main() {

	cout << "NIV Valide: " << validerNiv("WA1DKBFP8BA015672")  << endl;
	return 0;
}


// tests
/*
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
 */
