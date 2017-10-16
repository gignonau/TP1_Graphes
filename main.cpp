#include <iostream>
#include <limits>
#include "graphe.cpp"


using namespace std;

void displayMenus(){

}
void displayMenuDrones(){
    string input;
    bool out = false;
    GRAPHE graphe;
    while(out!=true){
        do{
            cout<<"(a) Mettre a jour la carte."<<endl;
            cout<<"(b) Determiner le plus court chemin securitaire."<<endl;
            cout<<"(c) Quitter."<<endl;
            cin>>input;
        }while(input != "a" &&input != "b" & input != "c");

        system ("cls");

        if(input=="a"){
            string path;
            cout<<"Donner le nom du fichier a lire :"<<endl;
            cin>>path;
            graphe = creerGraphe(path,0);

            cout<<"Appuyer sur n'importe quelle touche puis entrée pour retourner au menu"<< endl;
            cin>>path;

        }
        if(input=="b"){
            cout<<"Donner le type de colis"<<endl;
            cout<<"(1) Poids Plume"<<endl;
            cout<<"(2) Poid Moyen"<<endl;
            cout<<"(3) Poids Lourds"<<endl<<endl;
            cout<<"VOTRE CHOIX : ";
            int poid,s1,s2;
            do{
                cin>>poid;
                if ( cin.fail() ){
                    cout << "Saisie incorrecte, recommencez : ";
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
            }while(poid != 1 && poid != 2 && poid != 3);

            cout<<"Donner l'indice du sommet1 : ";
            do{
                cin>>s1;
                if ( cin.fail() ){
                    cout << "Saisie incorrecte, recommencez : ";
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
            }while( s1<0 || s1> graphe.getLenght());

            cout<<"Donner l'indice du sommet2 :";
            do{
                cin>>s2;
                if ( cin.fail() ){
                    cout << "Saisie incorrecte, recommencez : ";
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
            }while(s2<0 || s2>graphe.getLenght());

            plusCourtChemin(graphe,poid, s1,s2);
            cout<<"Appuyer sur n'importe quelle touche puis entrée pour retourner au menu"<< endl;
            cin>> input;

        }
        if(input=="c"){
            out = true;
        }
        system ("cls");
    }

}
void displayMenuRecettes(){

}



int main()
{
    cout << "Salut! Que veux-tu faire ? " << endl;
    displayMenuDrones();
    return 0;
}
