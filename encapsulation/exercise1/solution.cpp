#include<iostream>
#include<vector>
#include<string>


    using namespace std;


  class auteur
  {
      private:

      string name;
      string id;
      vector <string> livres;
      vector <int> nb_pages;
      vector <int> nb_ventes;
      vector <int> anne_publication;
      float revenu = 0;

      public:

       void affichage()
       {
          cout << "Name : "<<name<<endl;
          cout << "Id : "<<id<<endl;
          for(int i = 0;i < livres.size();i++)
          {
             cout << "Livre : "<<livres[i]<<" a "<<nb_pages[i]<<" avec un nombre de vente "<<nb_ventes[i]<<" dans l'anne "<<anne_publication[i]<<endl;
          }
       }


       void suppression(int s)
       {
         for(int i = 0;i < livres.size();i++)
         {
            if(nb_ventes[i] < s)
            {
               nb_ventes.erase(nb_ventes.begin()+i);
            }
         }
       }


       void suppresion(string user_input)
       {

          auto pos = find(livres.begin(),livres.end(),user_input);


           if(pos != livres.end())
           {
             

               livres.erase(pos);
           }

           else

             {

                cout << "livres pas trouve!"<<endl;
             }


       }

       void calcule_revenu()
       {

         int sum = 0;

          for(int i = 0;i < livres.size();i++)
          {
             if(nb_pages[i] > 250)
             {
                sum = sum + (15 * nb_ventes[i]);
             }

             else

              {
                 sum = sum + (10 * nb_ventes[i]);
              }
          }

           revenu = sum;
       }

       void modification(string user)
       {

          int new_nbv;
          string livre_name;
          int new_nbp;
          int new_anne_pub;
          bool found = false;
          int index;

          for(int i = 0;i < livres.size();i++)

          {
             if(livres[i] == user)
             {
                break;
                found = true;
                index = i;
             }
          }

           if(found = false)
           {
             cout << "Livre non trouve"<<endl;
           }

           else
            
             {
                 cout << "Modifier les informations du livre"<<endl;
                 cout << "Modifier le nom : "<<endl;
                 cin >> livre_name;
                 cout << "Modifier le nombre de ventes"<<endl;
                 cin >> new_nbv;
                 cout << "Modifier le nombre des pages"<<endl;
                 cin >> new_nbp;
                 cout << "Modifier l'anne de publication"<<endl;
                 cin >> new_anne_pub;
             }

             livres[index] = livre_name;
             nb_ventes[index] = new_nbv;
             nb_pages[index] = new_nbp;
             anne_publication[index] = new_anne_pub;
       }






  };