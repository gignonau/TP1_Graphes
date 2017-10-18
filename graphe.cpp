#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include "graphe.h"

/*********  FUNCTIONS FROM GRAPHE **********/
vector<string> GRAPHE::getNamesSommets() const
{
    return namesSommets;
}

void GRAPHE::setNamesSommets(const vector<string> &value)
{
    namesSommets = value;
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
            matrix[i][j]=INT_MAX;
        }
    }
    vector<string> random(value);
    namesSommets = random;
    for(int j = 0; j<lenght;j++){
        namesSommets[j] = "";
    }

}
void GRAPHE::setNameAt(int a, string b){
    namesSommets[a]=b;

}
string GRAPHE::getNameAt(int a){
    return namesSommets[a];

}

vector<vector<int> > GRAPHE::getMatrix() const
{
    return matrix;
}

void GRAPHE::setMatrix(const vector<vector<int> > &value)
{
    matrix = value;
}
/**************** FUNCTIONS  to split string around a delimiter
                  found on https://stackoverflow.com/questions/236129/the-most-elegant-way-to-iterate-the-words-of-a-string
***********/
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
/********** FUNCTION C2 **************/
void lireGraphe(GRAPHE graphe){
    for(int i = 0 ; i<graphe.getLenght();i++){
        cout<< "Noeud "<< i+1;
        string name = graphe.getNameAt(i);
        if(name != ""){
            cout<<" "<<name;
        }
        cout<<" -> Voisins : [ ";
        for(int j = 0; j<graphe.getLenght();j++){
            if(graphe.getWeightAt(i,j) !=INT_MAX ){
                cout<<"("<<j+1<<","<<graphe.getWeightAt(i,j)<<")";
                if(j!=0 || j!=graphe.getLenght())
                    cout<<",";
            }
        }
        cout<<"]"<<endl;
    }

}

int nbLines(string path){
    ifstream fichier(path, ios::in);  // on ouvre en lecture
    int compteurLigne = 0;
    if(fichier){
        string ligne;
        while(getline(fichier, ligne)){

            compteurLigne++;
        }
    }
    return compteurLigne ;
}

int nbSommets(string path){
    ifstream fichier(path, ios::in);  // on ouvre en lecture
    int compteurLigne = 0;
    if(fichier){
        string ligne;
        while(getline(fichier, ligne)){
            if(ligne == "") break;
            compteurLigne++;
        }
    }
    return compteurLigne ;
}

/********** FUNCTION C1 **************/
GRAPHE creerGraphe(string path, int index,int max, GRAPHE graphe){

    ifstream fichier("arrondissements.txt", ios::in);  // on ouvre en lecture

    if(fichier){
        string ligne;
        for(int i = 0; i<=index;i++)
            getline(fichier, ligne);

        std::vector<std::string> x = split(ligne, ',');
        if(index<18){
            if(stoi(x[1]) == 1)
                graphe.addReloadPoint(stoi(x[0]));
        }else{
            if(index>19){
                graphe.ajouterArc(stoi(x[0])-1,stoi(x[1])-1,stoi(x[2]));
                graphe.ajouterArc(stoi(x[1])-1,stoi(x[0])-1,stoi(x[2]));
            }
        }
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    if(index != max){
        graphe = creerGraphe(path,index+1,max,graphe);
    }
    return graphe;
}
/*********** FUNCTION C3 *********/
void plusCourtChemin(GRAPHE graphe,int poid, int sommet1, int sommet2){

}

/*********** FUNCTION D1 *********/
GRAPHE creerGrapheOriente(string path){
    bool clic = false;
    GRAPHE graphe;
    int infos = nbSommets(path);
    graphe.setLenght(infos);
    ifstream fichier("manger.txt", ios::in);  // on ouvre en lecture
    if(fichier){
        string ligne;
        while(getline(fichier, ligne)){
            if(ligne =="") {
                clic = true;
            }
            else{
                std::vector<std::string> x = split(ligne, ',');
                if(clic == false){
                   graphe.setNameAt(stoi(x[0])-1,x[1]);
                }
                if(clic == true){
                    graphe.ajouterArc(stoi(x[0])-1,stoi(x[1])-1,1);
                }
            }
        }
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    lireGraphe(graphe);
    return graphe;
}

void genererHasse(GRAPHE graphe){

}


