
#include <iostream>
#include "ListeInt.h"

//class ListeEntiers
//{
//public:
//	ListeEntiers();
//	ListeEntiers(const ListeEntiers& p_listeACopier);
//	ListeEntiers(ListeEntiers&& p_listeADeplacer);
//	~ListeEntiers();
//
//	void ajouterFin(const int& p_valeur);
//	void supprimerFin();
//	int obtenir(const int& p_valeur);
//	int nombreElements() const;
//	int capacite() const;
//	ListeEntiers& operator=(const ListeEntiers& p_listeACopier);
//	ListeEntiers& operator=(ListeEntiers&& p_listeADeplacer);
//	void parcourir(void(*p_fonction)(const int&));
//private:
//	int* m_valeurs;
//	int m_capacite;
//	int m_nbElements;
//
//};

ListeEntiers::ListeEntiers() :
	m_valeurs(new int[1]), m_capacite(1), m_nbElements(0) 
{
	std::cout << "Constructeur par default" << std::endl;
}


ListeEntiers::ListeEntiers(const ListeEntiers& p_listeACopier) :
	m_valeurs(nullptr), m_capacite(p_listeACopier.m_capacite), m_nbElements(p_listeACopier.m_nbElements)
{
	std::cout << "Constructeur par copie" << std::endl;
}

ListeEntiers::ListeEntiers(ListeEntiers&& p_listeACopier) :
	m_valeurs(p_listeACopier.m_valeurs), m_capacite(p_listeACopier.m_capacite), m_nbElements(p_listeACopier.m_nbElements)
{
	std::cout << "Constructeur par deplacement" << std::endl;
}

ListeEntiers::~ListeEntiers()
{
	std::cout << "ListeEntiers destructeur" << std::endl;
}

int ListeEntiers::nombreElements() const 
{
	return this->m_nbElements;
}

void ListeEntiers::ajouterFin(const int& p_valeur)
{
	if (this->m_nbElements == this->m_capacite)
	{
		this->m_capacite *= 2;
	}
	
	this->m_valeurs[this->m_nbElements++] = p_valeur;
}

void ListeEntiers::supprimerFin()
{
	if (this->m_nbElements != 0)
	{
		this->m_valeurs[this->m_nbElements] = NULL;
		--m_nbElements;
	}
}

int ListeEntiers::obtenir(const int& p_indice)
{
	if (p_indice <= this->m_nbElements)
	{
		return this->m_valeurs[p_indice];
	}
}

int ListeEntiers::capacite() const
{
	return this->m_capacite;
}

ListeEntiers& ListeEntiers::operator=(const ListeEntiers& p_objectAAffecter) 
{
	if (this != &p_objectAAffecter)
	{
		this->m_capacite = p_objectAAffecter.m_capacite;
		this->m_nbElements = p_objectAAffecter.m_nbElements;
		this->m_valeurs = p_objectAAffecter.m_valeurs;
	}

	return *this;
}

ListeEntiers& ListeEntiers::operator=(ListeEntiers&& p_objectAAffecter)
{
	if (this != &p_objectAAffecter)
	{
		this->m_capacite = p_objectAAffecter.m_capacite;
		this->m_nbElements = p_objectAAffecter.m_nbElements;
		this->m_valeurs = p_objectAAffecter.m_valeurs;
	}

	return *this;
}

void ListeEntiers::parcourir(void(*p_fonction)(const int&))
{
	for (int i = 0; i < this->m_nbElements; i++)
	{
		p_fonction(this->m_valeurs[i]);
	}
}