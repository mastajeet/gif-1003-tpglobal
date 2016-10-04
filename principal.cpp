#include <iostream>
#include "validationFormat.h"
using namespace std;

int main() {

	cout << validerImmatriculation("LOL 418")  << endl;
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
 */
