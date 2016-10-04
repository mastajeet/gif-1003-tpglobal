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

#endif /* VALIDATIONFORMAT_H_ */
