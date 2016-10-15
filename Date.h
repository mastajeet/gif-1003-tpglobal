/**
 * \file Date.h
 * \brief Fichier qui contient l'interface de la classe Date qui sert au maintien et � la manipulation des dates.
 * \author Yves Roy Version initiale, THE
 * \date 12 mars 2013
 * \version 3.1 sans contrat
 */
// derni�re modification : 2014-02-06

#ifndef DATE_H_
#define DATE_H_
#include <string>

namespace util
{
/**
 * \class Date
 * \brief Cette classe sert au maintien et � la manipulation des dates.
 *
 *              Cette classe peut aussi servir � prendre la date courante du
 *              syst�me et � faire des calculs avec des dates.
 *              <p>
 *              Les limites de validit� de cette date est du 1er janvier
 *              1970 au 31 d�cembre 2037.
 *              <p>
 *              La validit� d'une date peut �tre v�rifi�e avec la m�thode statique
 *              bool Date::verifierDate(jour, mois, annee).\n
 *             Attributs:   time_t m_temps   Nombre de secondes �coul� depuis le premier
 *                               			janvier 1970
 * 				time_t m_temps pour long m_temps
 */
class Date
{
public:
	Date();
	Date(long p_jour, long p_mois, long p_annee);

	void asgDate(long p_jour, long p_mois, long p_annee);
	bool ajouteNbJour(long p_nbjour);

	long reqJour() const;
	long reqMois() const;
	long reqAnnee() const;

	long reqJourAnnee() const;
	std::string reqDateFormatee() const;

	bool operator ==(const Date& p_date) const;
	bool operator <(const Date& p_date) const;
	int operator -(const Date& p_date) const;

	static bool estBissextile(long p_annee);
	static bool validerDate(long p_jour, long p_mois, long p_annee);

	friend std::ostream& operator<<(std::ostream& p_os, const Date& p_date);
private:
	std::string reqNomJourSemaine() const;
	std::string reqNomMois() const;

	time_t m_temps;
};

} // namespace util

#endif /* DATE_H_ */

