#include<iostream>
#include<vector>
#include<string>

  
  using namespace std;


class personne
{
    protected:

    string nom;
    int ag;

    public:

    virtual void ajouter_publication() = 0;
    
};


class chapitre
{
    private:

    string title;
    int page_debut;
    int page_fin;
    int numero;
};


class livre
{
  private:

  string nom;
  int nb_pages;
  int nb_copie_vendue;
  vector <string> co_auteur;
  string auteur;
  vector <chapitre> chapitres;
  string genre;
};

class auteur : public personne
{
    private:

    vector <livre> livres;
    string editeur;
    float revenue;

    public:

    float revenue_totale()
    {

    }

    void demande_participation()
    {

    }
};


class editeur : public personne
{
    public:

    void supprimer_chapitre()
    {

    }

    void ajuster_livre()
    {
      
    }
};