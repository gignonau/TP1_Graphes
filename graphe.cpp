#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include "graphe.h"

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

void lireGraphe(GRAPHE graphe){
    for(int i = 0 ; i<graphe.getLenght();i++){
        cout<< "Noeud numero "<< i+1 << " -> Voisins : [ ";
        for(int j = 0; j<graphe.getLenght();j++){
            if(graphe.getWeightAt(i,j) !=0 )
                cout<<"("<<j+1<<","<<graphe.getWeightAt(i,j)<<")";
        }
        cout<<"]"<<endl;
    }

}

GRAPHE creerGraphe(string path, int n){
    bool clic = false;
    GRAPHE graphe;
    int compteur = 0;
    ifstream fichier("arrondissements.txt", ios::in);  // on ouvre en lecture
    if(fichier){
        string ligne;
        while(getline(fichier, ligne)){
            if(ligne =="") {
                clic = true;
                graphe.setLenght(compteur);
            }
            else{
                compteur++;
                std::vector<std::string> x = split(ligne, ',');
                if(clic == false){
                   if(stoi(x[1]) == 1)
                       graphe.addReloadPoint(stoi(x[0]));
                }
                if(clic == true){
                    graphe.ajouterArc(stoi(x[0])-1,stoi(x[1])-1,stoi(x[2]));
                    graphe.ajouterArc(stoi(x[1])-1,stoi(x[0])-1,stoi(x[2]));
                }
            }
        }
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    lireGraphe(graphe);
    return graphe;
}

int GRAPHE::getLenght() const
{
    return lenght;
}

void GRAPHE::setLenght(int value)
{
    lenght = value;
    vector<vector<int>> matrix1(value, vector<int>(value));
    matrix = matrix1;
    for(int i = 0 ; i<lenght;i++){
        for(int j = 0; j<lenght;j++){
            matrix[i][j]=0;
        }
    }
}

void plusCourtChemin(GRAPHE graphe,int poid, int sommet1, int sommet2){

}
