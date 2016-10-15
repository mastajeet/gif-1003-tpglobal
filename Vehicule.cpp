/*
 * Vehicule.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: etudiant
 */

#include "Vehicule.h"
#include "Date.h"
#include <sstream>
#include <iostream>

Vehicule::Vehicule(const std::string& p_niv,const std::string& p_immatriculation)
:m_niv(p_niv), m_immatriculation(p_immatriculation), m_dateEnregistrement(util::Date())
{
}

std::string Vehicule::reqNiv() const {
	return m_niv;
}

std::string Vehicule::reqImmatriculation() const {
	return m_immatriculation;
}

util::Date Vehicule::reqDateEnregistrement() const {
	return m_dateEnregistrement;
}

void Vehicule::asgImmatriculation(const std::string& p_immatriculation) {
	m_immatriculation = p_immatriculation;
}

std::string Vehicule::reqVehiculeFormate() const {
	std::ostringstream output_stream;

	output_stream << "Numero de serie                 :" << reqNiv() << std::endl;
	output_stream << "Numero d'immatriculation        :" << reqImmatriculation() << std::endl;
	output_stream << "date d'enregistrement           :" << reqDateEnregistrement().reqDateFormatee() << std::endl;

	return output_stream.str();
}

bool Vehicule::operator ==(const Vehicule& p_vehicule) const {
	bool vehiculeEstEgal = false;
	if(m_niv == p_vehicule.m_niv and m_immatriculation == p_vehicule.m_immatriculation and m_dateEnregistrement == p_vehicule.m_dateEnregistrement)
	{
		vehiculeEstEgal = true;
	}

	return vehiculeEstEgal;
}
