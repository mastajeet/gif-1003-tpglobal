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
bool validerNiv(const std::string p_niv);

bool validerPattern(const std::string& p_immatriculation, const std::string& p_caracteresMinimaux, const std::string& p_caracteresMaximaux);

std::string appliquerTransformation(const std::string& p_vin,const std::string& p_tableauTransformationParChar);
int appliquerPoids(const std::string& p_vin,const std::string& p_tableauPoidsParPosition);


#endif /* VALIDATIONFORMAT_H_ */
