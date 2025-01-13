#include<iostream>
#include<vector>
#include<string>

    using namespace std;


class etudiant 
{
    private:

    string nom;
    string prenom;
    vector <string> matiere;
    vector <float> note;
    int absence;

    public:

    etudiant(string nom,string prenom) = delete;

    etudiant(){}

    etudiant(string nom,string prenom,vector <string> matiere,vector <float> note,int absence = 0)
    {
       this->nom = nom;
       this->prenom = prenom;
       this->matiere = matiere;
       this->note = note;
       this->absence = absence;

    }


    void set_info(string user_matiere,float user_note)
    {
       auto pos = find(matiere.begin(),matiere.end(),user_matiere);

        if(pos != matiere.end())
        {
           cout << "matiere deja exist"<<endl;
           return;
        }

        else

         {
            matiere.push_back(user_matiere);
            note.push_back(user_note);
         }
    }

    void affichage()
    {
       cout << "Nom : "<<nom<<endl;
       cout << "Pronem : "<<prenom<<endl;
       cout << "Nombre d'absence : "<<absence<<endl;
       for(int i = 0;i < matiere.size();i++)
       {
         cout << "La matiere : "<<matiere[i]<<" avec la note : "<<note[i]<<endl;
       }
    }


    float moyenne()
    {
       float sum = 0;
       float result;

        for(int i = 0;i < note.size();i++)
        {
           sum = sum + note[i];
        }

          return result = sum=note.size();
    }


    void suppression()
    {
       for(int i = 0;i < matiere.size();i++)
       {
         if(note[i] < 10)
         {
            note.erase(note.begin()+i);
         }
       }
    }

    friend void affichage_note_maximale();
    friend class administration;


    vector <string>& get_matiere()
    {
       return matiere;
    }

    vector <float>& get_note()
    {
      return note;
    }
};


void affichage_note_maximale()
{

}


class delegue : public etudiant
{
    protected:

    int numero_tel;
    vector <string> enseignant;
    vector <int> date_examen;


    public:

    delegue(int numero_tel,vector <string> enseignant,vector <int> date_examen)
    {
       this->numero_tel = numero_tel;
       this->enseignant = enseignant;
       this->date_examen = date_examen;

    }

    void modifier_date(string new_matiere, int user_date)
    {
       for(int i = 0;i < get_matiere().size();i++)
       {
         if(get_matiere()[i] == new_matiere)
         {
             auto pos = find(date_examen.begin(),date_examen.end(),user_date);

              if(pos != date_examen.end())
              {
                 cout << "Date deja Exist"<<endl;
              }

              else

               {
                  date_examen[i] = user_date;
               }
         }
       }
    }


    void annuler_seance(string user_teacher)
    {
        auto pos = find(enseignant.begin(),enseignant.end(),user_teacher);

         if(pos != enseignant.end())
         {
           cout << "La sceance de la matiere : "<<get_matiere()[pos-enseignant.begin()]<<" de l'enseignant : "<<user_teacher<<" est annule"<<endl;
         }
    }
};

class bde : public delegue
{
    private:

    int id;

    public:

    void planifier_evenement(int date)
    {
       bool b;
        for(int i = 0;i < date_examen.size();i++)
        {
           if(date = date_examen[i])
           {
              b = false;
              break;
           }

           if(b = false)
           {
             cout << "La date : "<<date<<" coincide avec la date des examens"<<endl;
           }

           else
            {
                cout << "Evenment planifier dans la date : "<<date<<endl;
            }
        }
    }
};

class groupe
{
   private:

   string nom;
   vector<etudiant> etudiants;
   string filiere;

   public:

   float moyenne_groupe()
   {
        float result;
        float sum = 0;

        for(int i = 0;i < etudiants.size();i++)
        {
           sum = sum + etudiants[i].moyenne();
        }

        return result = sum/etudiants.size();
   }

   void nb_validation(string mat)
   {
       int count = 0;
      
        for(int i = 0;i < etudiants.size();i++)
        {
           for(int j = 0;j < etudiants[i].get_matiere().size();j++)
           {
              auto pos = find(etudiants[i].get_matiere().begin(),etudiants[i].get_matiere().end(),mat);

                if(pos != etudiants[i].get_matiere().end())
                {
                   if(etudiants[i].get_note()[pos-etudiants[i].get_matiere().begin()] > 10)
                   {
                     count++;
                   }
                }
           }
        }

            cout << "Le nombre des etudians qui ont valide la matiere : "<<mat<<" est : "<<count<<endl;
   }


};

    class administration
   {
      public:

      void avertissement(etudiant e)
      {
          if(e.absence > 15)
          {
              cout << "Avertissement"<<endl;
          }
      }

      void bonus(etudiant student)
      {
        bool b = true;

          for(int i = 0;i < student.note.size();i++)
          {
             if(student.note[i] <=12 || student.absence)
             {
                b = false;
                break;
             }
          }

           if(b == true)
           {
              cout << "felitations "<<student.nom<<endl;
           }
      }
   };