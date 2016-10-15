/*
 * Vehicule.h
 *
 *  Created on: Oct 15, 2016
 *      Author: etudiant
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_

#include <string>
#include "Date.h"

class Vehicule{

public:
	Vehicule(const std::string& p_niv,const std::string& p_immatriculation);
	std::string reqNiv() const;
	std::string reqImmatriculation() const;
	util::Date reqDateEnregistrement() const;
	void asgImmatriculation(const std::string& p_immatriculation);
	std::string reqVehiculeFormate() const;
	bool operator== (const Vehicule& p_vehicule) const;

private:
	std::string m_niv;
	std::string m_immatriculation;
	util::Date m_dateEnregistrement;

};



#endif /* VEHICULE_H_ */
