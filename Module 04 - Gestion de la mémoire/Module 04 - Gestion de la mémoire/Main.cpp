

#include <iostream>
#include "ListeInt.h"

int main()
{
    ListeEntiers TestListe = ListeEntiers();

	for (int i = 0; i < 10; i++)
	{
		TestListe.ajouterFin(i);
	}
	for (int i = 0; i < TestListe.nombreElements(); i++)
	{
		std::cout << TestListe.obtenir(i) << std::endl;
	}

	std::cout << TestListe.nombreElements() << std::endl;

	TestListe.supprimerFin();
	TestListe.supprimerFin();

	std::cout << TestListe.nombreElements() << std::endl;

	ListeEntiers TestListeParCopie(TestListe);

	ListeEntiers TestListeParDeplacement = std::move(TestListe);

	for (int i = 0; i < TestListeParDeplacement.nombreElements(); i++)
	{
		std::cout << TestListeParDeplacement.obtenir(i) << std::endl;
	}
	
}

