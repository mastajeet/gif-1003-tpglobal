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

namespace util
{
	/**
	 * \brief fonction qui valide une plaque d'immatriculation
	 * \param[in] p_immatriculation une chaine de caractere a tester
	  */
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

	/**
	 * \brief fonction qui valide un numero d'identification d'un vehicule
	 * \param[in] p_niv une chaine de caractere a tester
	*/
	bool validerNiv(const std::string& p_niv)
	{
		bool nivValide = true;

		if(nivValide && validerNivContientExclusionGlobale(p_niv))
		{
			nivValide = false;
			std::cout << "le numero d'identification a un erreur au niveau global" << std::endl;
		}

		if(nivValide && validerNivContientErreurParPosition(p_niv))
		{
			nivValide = false;
			std::cout << "Un position n'est pas correctement definie" << std::endl;

		}

		if(nivValide && !validerCoherenceNiv(p_niv))
		{
			nivValide = false;
			std::cout << "Le numero de confirmation en position 9 n'est pas egal a celui attendu" << std::endl;
		}


		return nivValide;
	}


	/**
	 * \brief fonction qui verifie si un numero d'identification a le bon numero de validation
	 * \param[in] p_niv une chaine de caractere contenant le numero de validation a tester
	*/
	bool validerCoherenceNiv(const std::string& p_niv)
	{
		bool nivCoherent;
		const int valeurConfirmation = obtenirNumeroConfirmateur(p_niv);

		const std::string nivTransforme = appliquerTransformationDesLettres(p_niv,"12345678012345070923456789");
		const int valeurAgregee = appliquerPoids(nivTransforme,"87654329098765432") + appliquerPoids(nivTransforme,"00000001000000000");
		const int valeurTestConfirmation = modulo(valeurAgregee,11);
		nivCoherent = (valeurTestConfirmation==valeurConfirmation) ; //appliquerTransformation()
		return nivCoherent;
	}

	int obtenirNumeroConfirmateur(const std::string& p_niv)
	{
		int valeurConfirmation;
		const int valeurOffset = '0';
		const char itemConfirmation = p_niv[8];

		if(validerPattern(itemConfirmation,'0','9'))
		{
			valeurConfirmation = (int)(itemConfirmation-valeurOffset);
		}
		else if (validerPattern(itemConfirmation,'X','X'))
		{
			valeurConfirmation = 10;
		}

		return valeurConfirmation;
	}

	/**
	 * \brief fonction qui retourne vrai si le numero d'identifaction contient une erreur pour un caractere a une position precise
	 * \param[in] p_niv une chaine de caractere contenant le numero de validation a tester
	*/
	bool validerNivContientErreurParPosition(const std::string& p_niv)
	{
		bool nivContientErreurParPosition = false;

		//position 9 (index 8) qui est entre 0 et 9 ou X
		if(!nivContientErreurParPosition &&
				!(validerPattern(p_niv[8],'0','9') || validerPattern(p_niv[8],'X','X')))
		{
			nivContientErreurParPosition = true;
			std::cout << "Le Niv ne contient pas 0-9 ou X a la 9e position" << std::endl;
		}

		//Position 10 qui ne peut pas etre U ou Z
		if(!nivContientErreurParPosition &&
				(validerPattern(p_niv[9],'U','U') || validerPattern(p_niv[9],'Z','Z')) )
		{
			nivContientErreurParPosition = true;
			std::cout << "Le Niv contient un U ou un Z a la 10e position" << std::endl;
		}

		return nivContientErreurParPosition;
	}

	/**
	 * \brief fonction qui retourne vrai si un numero d'identification contient une erreur globale (mauvaise longueur, caractere proscrit globalement...)
	 * \param[in] p_niv une chaine de caractere contenant le numero de validation a tester
	*/
	bool validerNivContientExclusionGlobale(const std::string& p_niv)
	{

		bool nivContientExclusionGlobale = false;

		// Doit contenir 17 characteres
		if(!nivContientExclusionGlobale && p_niv.length() != 17){
			nivContientExclusionGlobale = true;
			std::cout << "le numero d'identification n'a pas 17 caracteres" << std::endl;
		}

		//doit etre chiffre ou lettres majuscules (alphanumerique)
		if(!nivContientExclusionGlobale)
		{
			for(unsigned int i = 0; i < p_niv.length(); i++)
			{
				nivContientExclusionGlobale = nivContientExclusionGlobale || !(validerPattern(p_niv[i],'0','9') || validerPattern(p_niv[i],'A','Z')) ;

			}
			if(nivContientExclusionGlobale)
			{
				std::cout << "le numero d'identification n'est pas uniquement constitue de chiffre et de lettre majuscules" << std::endl;
			}
		}

		// ne peut pas contenir I O ou Q
		if(!nivContientExclusionGlobale)
		{
			for(unsigned int i = 0; i < p_niv.length(); i++)
			{
				nivContientExclusionGlobale = nivContientExclusionGlobale || validerPattern(p_niv[i],'I','I');
				nivContientExclusionGlobale = nivContientExclusionGlobale || validerPattern(p_niv[i],'O','O');
				nivContientExclusionGlobale = nivContientExclusionGlobale || validerPattern(p_niv[i],'Q','Q');

			}
			if(nivContientExclusionGlobale){
				std::cout << "le numero d'identification contient les lettre I O ou Q" << std::endl;
			}
		}

		// 5 derniere positions sont normalemnet numerique...juste lever un warning console
		bool dernierCaracterereNumeriques = false;

		for(unsigned int i = 11; i < p_niv.length(); i++)
			{
				dernierCaracterereNumeriques = dernierCaracterereNumeriques || validerPattern(p_niv[i],'0','9');
			}
			if(!dernierCaracterereNumeriques){
				std::cout << "Attention: Les 5 derniers caracteres du NIV sont normalement numeriques, il se pourrait qu'il y ait une erreur" << std::endl;
		}

		return nivContientExclusionGlobale;
	}

	/**
	 * \brief fonction qui verifie un caractere est dans les bornes de deux arguments
	 * \param[in] p_caractere un caractere a tester
	 * \param[in] p_caractereMinimal un caractere qui est la borne inferieure incluse
	 * \param[in] p_caractereMaximal un caractere qui est la borne supperieure incluse
	*/
	bool validerPattern(const char& p_caractere, const char& p_caractereMinimal, const char& p_caractereMaximal)
	{
		bool patternReconnu;
		patternReconnu = true;
		if(!(p_caractere>=p_caractereMinimal && p_caractere<=p_caractereMaximal))
		{
			patternReconnu= false;
		}
		return patternReconnu;

	};

	/**
	 * \brief fonction qui verifie si une tous les caracteres d'une chaine de caracteres respectent les bornes inferieures et supperieur d'un pattern
	 * \param[in] p_chaineATester la chaine de caracteres a tester
	 * \param[in] p_caracteresMinimaux borne inferieur (incluse) pour les caracteres aux memes positions
	 * \param[in] p_caracteresMaximaux borne supperieure (incluse) pour les caracteres aux memes positions
	*/
	bool validerPattern(const std::string& p_chaineATester, const std::string& p_caracteresMinimaux, const std::string& p_caracteresMaximaux)
	{
		std::cout << "validerPattern - Debug" << std::endl;
		bool patternReconnu;
		patternReconnu = true;
		if(p_caracteresMinimaux.length()==p_caracteresMaximaux.length())
		{
			std::cout << "Pattern a tester: " << p_caracteresMinimaux << std::endl;
			for(unsigned int i=0; i < p_chaineATester.length(); i++){
				const char valeurAsciiCaractere = p_chaineATester[i];
				const char valeurAsciiMinimale = p_caracteresMinimaux[i];
				const char valeurAsciiMaximale = p_caracteresMaximaux[i];
				std::cout << "A tester: " << valeurAsciiCaractere <<", valeur minimale: "<< valeurAsciiMinimale <<", valeur maximale: "<< valeurAsciiMaximale << std::endl;
				std::cout << valeurAsciiCaractere << " >= " << valeurAsciiMinimale <<": "<< (valeurAsciiCaractere >= valeurAsciiMinimale) << ", ";
				std::cout << valeurAsciiCaractere << " <= " << valeurAsciiMaximale <<": "<< (valeurAsciiCaractere <= valeurAsciiMaximale) << std::endl;

				if(!(valeurAsciiCaractere>=valeurAsciiMinimale && valeurAsciiCaractere<=valeurAsciiMaximale))
				{

					patternReconnu= false;
				}
			}
		}
		return patternReconnu;

	};


	/**
	 * \brief fonction transforme chacune des lettres selon un pattern.
	 * \param[in] p_vin la chaine de caracteres a transformer
	 * \param[in] p_transformationParChar table de transformation des valeurs. la premiere position transforme les A, la deuxieme transforme les B, etc
	 */
	std::string appliquerTransformationDesLettres(const std::string& p_vin,const std::string& p_transformationParChar)
	{
		std::string vinTransforme;
		char tableauOffset;

		vinTransforme= "";
		tableauOffset = 'A';


		for(unsigned int i=0;i<p_vin.length();i++)
		{
			if(validerPattern(p_vin[i],'A','Z'))
			{
				vinTransforme += p_transformationParChar[p_vin[i]-tableauOffset];
			}else{
				vinTransforme += p_vin[i];
			}
		}

		return vinTransforme;
	};

	/**
	 * \brief retourne le reste d'une division entiere
	 * \param[in] p_nombreADiviser le nombre a diviser
	 * \param[in] p_diviseur le nombre qui divise le nombre a diviser
	 */
	int modulo(const int& p_nombreADiviser,const int& p_diviseur){

		const int nombreDivisionComplete =  p_nombreADiviser / p_diviseur;
		const int restantDivisionEntiere = p_nombreADiviser - nombreDivisionComplete * p_diviseur;
		return restantDivisionEntiere;
	}

	/**
	 * \brief fonction applique des poids aux caracteres aux meme positions
	 * \param[in] p_vin la chaine de caracteres a ponderer
	 * \param[in] p_tableauPoidsParPosition vecteur de poids. la premiere position pondere la premiere position, la deuxieme pondere la deuxieme, etc
	 */
	int appliquerPoids(const std::string& p_vinTransforme,const std::string& p_tableauPoidsParPosition)
	{
		int vinTransformeAggrege;
		vinTransformeAggrege= 0;
		char caractereOffset;
		caractereOffset = '0';

		std::cout << "appliquerPoids - Debug" << std::endl;

		for(unsigned int i=0;i<p_vinTransforme.length();i++){
			std::cout << "increment: " << (int)p_tableauPoidsParPosition[i]-caractereOffset << " * " << (int)p_vinTransforme[i]-caractereOffset << " = " << (((int)p_tableauPoidsParPosition[i]-caractereOffset) * ((int)p_vinTransforme[i]-caractereOffset)) <<std::endl;
			vinTransformeAggrege += (int)(p_tableauPoidsParPosition[i]-caractereOffset)*((int)p_vinTransforme[i]-caractereOffset);
		}

		return vinTransformeAggrege;

	};
}
