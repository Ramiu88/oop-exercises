#include<iostream>
#include<string>
#include<vector>

     using namespace std;

class vehicule
{
  private:

  string name;
  string carburant;
  float vitesse_maximale;
  int nb_roue;
  int kilometrage;

  public:

  void vidange()
  {
     if(kilometrage > 15000)
     {
       cout<< "effectuer vidange!"<<endl;
     }
  }

  void set_kilometrage(int kilo)
    {
       if(kilo > 0)
       {
          kilometrage = kilo;
       }
    }

};


class voiture : public vehicule

{
    private:

    int nb_porte;
    string type;
    
    public:

    void usage()

    {
        if(type == "Berline")
        {
           cout << "location";
        }

        else

        {

            cout << "a vendre"<<endl;
        }
    }

    void effectuer_visite(){}

    void set_type(string type)
    {
       
         this->type = type;
       

    }


};