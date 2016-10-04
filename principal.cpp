#include <iostream>
#include "validationFormat.h"
using namespace std;

int main() {

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
 * appliquerTransformation("ABCFF","1234567890") == 12366
 * appliquerPoids("1234","1234") == 30
 *
 */
