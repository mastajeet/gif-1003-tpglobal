/*
 * calidationFormat.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: etudiant
 */

#include "validationFormat.h"
#include <string>
#include <tr1/regex>
#include <iostream>

bool validerImmatriculation(const std::string& p_immatriculation)
{
	bool patternTrouve;

	patternTrouve=false;

	patternTrouve += validerPattern(p_immatriculation,"000 AAA","999 ZZZ");
	patternTrouve += validerPattern(p_immatriculation,"000A000","999Z999");
	patternTrouve += validerPattern(p_immatriculation,"A00 AAA","Z99 ZZZ");
	patternTrouve += validerPattern(p_immatriculation,"AAA 000","ZZZ 999");
	patternTrouve += validerPattern(p_immatriculation,"L000000","L999999");


	return patternTrouve;
};

bool validerNiv(const std::string p_niv)
{
	return true;
}


bool validerPattern(const std::string& p_immatriculation, const std::string& p_caracteresMinimaux, const std::string& p_caracteresMaximaux)
{
	bool patternReconnu;
	patternReconnu = true;
	if(p_caracteresMinimaux.length()==p_caracteresMaximaux.length())
	{
		std::cout << "Pattern a tester: " << p_caracteresMinimaux << std::endl;
		for(int i=0; i<p_caracteresMinimaux.length(); i++){
			const char valeurAsciiCaractere = p_immatriculation[i];
			const char valeurAsciiMinimale = p_caracteresMinimaux[i];
			const char valeurAsciiMaximale = p_caracteresMaximaux[i];
			std::cout << "A tester: " << valeurAsciiCaractere <<", valeur minimale: "<< valeurAsciiMinimale <<", valeur maximale: "<< valeurAsciiMaximale << std::endl;
			std::cout << valeurAsciiCaractere << " >= " << valeurAsciiMinimale <<": "<< (valeurAsciiCaractere >= valeurAsciiMinimale) << std::endl;
			std::cout << valeurAsciiCaractere << " <= " << valeurAsciiMaximale <<": "<< (valeurAsciiCaractere <= valeurAsciiMaximale) << std::endl;

			if(!(valeurAsciiCaractere>=valeurAsciiMinimale && valeurAsciiCaractere<=valeurAsciiMaximale))
			{

				patternReconnu= false;
			}
		}
	}
	return patternReconnu;

};
