#include<iostream>
#include<string>
#include<vector>

      using namespace std;



 class joueur
 {
    private:

    string name;
    int age;
    vector <string> position;
    int numero;
    int total_but;

    public:

     joueur()
     {

     }


     joueur(string name,int age)
     {
        this->name = name;
        this->age = age;
     }

     void affichage()
     {
        cout << "Name : "<<name<<endl;
        cout << "Age : "<<age<<endl;
        for(int i = 0;i < position.size();i++)
        {
           cout << " | "<<position[i]<<endl;
        }
        cout << "Numero : "<<numero<<endl;
        cout << "Total des buts : "<<total_but<<endl;
     }

     void ajouter_position(string position)
     {
           this->position.push_back(position);
     }


     string get_name()
     {
       return name;
     }

     int get_age()
     {
      return age;
     }

     vector <string>& get_position()
     {
        return position;
     }

     int get_numero()
     {
      return numero;
     }


     int get_total_but()
     {
       return total_but;
     }



 };


 class equipe
 {
    string name;
    int anne_creation;
    vector <joueur> joueurs;
    int nb_trophie;

    public:

    equipe()
    {

    }

    equipe(string name, int anne_creation)
    {
         this->name = name;
         this->anne_creation = anne_creation;
    }


    void affichage()
    {
      cout << "Name : "<<name<<endl;
      cout << "Anne de creation"<<anne_creation<<endl;
      cout << "Nombre des trophies : "<<nb_trophie<<endl;
      for(int i = 0;i < joueurs.size();i++)
      {
         cout << joueurs[i].get_name()<<endl;
         cout << joueurs[i].get_age()<<endl;
         cout << joueurs[i].get_numero()<<endl;
         cout << joueurs[i].get_total_but()<<endl;
         for(int j = 0;j < joueurs[i].get_position().size();j++)
         {
            cout << joueurs[i].get_position()[j]<<endl;
         }
      }
    }

    void suppresion(string poss)
    {
         for(int i = 0;i < joueurs.size();i++)
         {
            auto pos = find(joueurs[i].get_position().begin(),joueurs[i].get_position().end(),poss);

                 if(pos != joueurs[i].get_position().end())
                 {
                    joueurs[i].get_position().erase(joueurs[i].get_position().begin()+i);
                 }

         }
    }

    void ajouter_joueur(joueur jou)
    {
       joueurs.push_back(jou);
    }

 };


 int main()
 {



   return 0;
 }