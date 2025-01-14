#include<iostream>
#include<vector>
#include<string>


  using namespace std;


class athlete
{
   protected:

   string name;
   string domaine;
   float salaire;

   public:

   void affichage()
   {
     cout << "Name : "<<name<<endl;
     cout << "Domaine : "<<domaine<<endl;
     cout << "Salaire: "<<salaire<<endl;
   }
};

class parent
{
    protected:

    int nb_enfant;
    string name;

};


class joueur : public athlete, public parent
{
   private:

   string position;
   vector <string> match;
   vector <int> duree_de_jeu;
   vector <float> evaluation;

   public:

   void affichage()
   {
     cout << "Position : "<<position<<endl;

     athlete::affichage();

     for(int i = 0;i < match.size();i++)
     {
        cout << "Match "<<match[i]<<" de la duree "<<duree_de_jeu[i]<<" avec l'evaluation "<<evaluation[i]<<endl;
     }
   }

};

class responsable
{
   virtual void affichage() = 0;
   virtual void ajouter_joueurs() = 0;
};