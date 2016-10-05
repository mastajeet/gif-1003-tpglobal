/*
 * validationFormat.h
 *
 *  Created on: Oct 3, 2016
 *      Author: etudiant
 */

#include <string>

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

bool validerImmatriculation(const std::string& p_immatriculation);
bool validerNiv(const std::string& p_niv);

bool validerPattern(const std::string& p_immatriculation, const std::string& p_caracteresMinimaux, const std::string& p_caracteresMaximaux);
bool validerPattern(const char& p_caractere, const char& p_caractereMinimal, const char& p_caractereMaximal);

std::string appliquerTransformationDesLettres(const std::string& p_vin,const std::string& p_tableauTransformationParChar);
int appliquerPoids(const std::string& p_vin,const std::string& p_tableauPoidsParPosition);
bool validerNivContientExclusionGlobale(const std::string& p_niv);
bool validerNivContientErreurParPosition(const std::string& p_niv);
bool validerCoherenceNiv(const std::string& p_niv);

int modulo(const int& p_nombreADiviser,const int& p_diviseur);


#endif /* VALIDATIONFORMAT_H_ */
