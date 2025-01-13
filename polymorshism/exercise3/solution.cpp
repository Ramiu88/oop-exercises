#include<iostream>
#include<vector>
#include<string>

 
    using namespace std;


class joueur
{
    private:

    int age;
    string nom;
    int carte_jaune;
    vector <string>positions;
    vector <string> equipe_precedentes;
    vector <string> coupes;
    int discipline;

    public:

    void affichage()
    {
      cout << "Age : "<<age<<endl;
      cout << "Nom : "<<nom<<endl;
      cout << "Carte jaune : "<<carte_jaune<<endl;
      cout << "Discipline : "<<discipline<<endl;
      for(int i = 0;i < positions.size();i++)
      {
          cout << "Position : "<<positions[i]<<endl;
          cout << "Equipe precedente : "<<equipe_precedentes[i]<<endl;
          cout << "Coupe : "<<coupes[i]<<endl;
      }
    }

   void suppression()
   {
      auto it = find(positions.begin(),positions.end(),"defenseur central");

        if(it !=positions.end())
        {
           if(age < 20)
           {
             positions.erase(it);
           }
        }
   }

   void ajouter_positionn(string pos)
   {
       if(find(positions.begin(),positions.end(),pos) != positions.end())
       {
         cout << "position deja existe"<<endl;
       }

       else

        {
            if(pos == "gardien de but")
            {
               if(age < 18)
               {
                 if(coupes.size() >= 3)
                 {
                    cout << "Vous pouvez occuper le gardien de but"<<endl;
                    positions.push_back(pos);

                 }
               }

               else
               {
                 cout << "Vous pouvez pas occuper la position du gardien du but"<<endl;

               }
            }

            else

                {
                    cout << "Vous pouvez occuper la position : "<<pos<<endl;
                }
        }
   }

    void changement_discipline()
    {
       if(carte_jaune <=1 && age < 20)
       {
          discipline++;
       }

       else if(age > 27 && (equipe_precedentes.size() == 0 || carte_jaune > 3))
       {
         discipline--;
       }
    }


    void modifier_position(string pos)
    {
        for(int i = 0;i < positions.size();i++)
        {
           if(positions[i] == pos)
           {
              positions[i] = pos;
              break;
           }
        }
    }

    int& get_age()
    {
       return age;
    }


    vector <string>& get_positions()
    {
        return positions;
    }

    int& get_discipline()
    {
       return discipline;
    }

    string& get_nom()
    {
       return nom;
    }

};



class equipe

{
    private:

    string name;
    int nb_trophes;
    vector <string> competition;
    vector <int> nb_points;
    vector <joueur> joueurs;

    public:

    void mise_a_jour()
    {

    }

    void ajouter_positions()
    {

    }

    void supprimer_positions()
    {
       
    }
};


class entraineur : public equipe
{
    private:

    string email;
    vector <string> positions;
    vector <int> age_minimum;

    public:

    void diminuer_nb_poste(vector <joueur> joueurs)
    {
        for(int i = 0;i < joueurs.size();i++)
        {
          if(joueurs[i].get_age() < 16)
          {
             joueurs[i].get_positions().resize(1);
          }

          else if(joueurs[i].get_age() > 19)
          {
             joueurs[i].get_positions().resize(2);
          }
        }
    }

    void transfer(joueur a)
    {

      if(a.get_discipline() < 2)
      {
        int counter = 0;
        for(int i = 0;i < a.get_positions().size();i++)
        {
           for(int j = 0;j < positions.size();i++)
           {
              if(a.get_positions()[i] == positions[j])
              {
                 counter++;
              }

              if(counter >=2)
              {
                 cout << "Le Joueur : "<<a.get_nom()<<" est transfere"<<endl;
              }
           }
        }
      }
    }


    void suppression(joueur player)
    {
        for(int i = 0;i < player.get_positions().size();i++)
        {
           if(age_minimum[i] > player.get_age())
           {
              player.get_positions().erase(player.get_positions().begin()+i);
              // to do later
           }
        }
    }

    
};