#ifndef GRAPHE_H
#define GRAPHE_H

#include <iostream>
#include <vector>
using namespace std;

class GRAPHE{
public :
    GRAPHE(int length){
        vector<vector<int>> matrix1(length, vector<int>(length));
        matrix = matrix1;
    }
    GRAPHE(){lenght = 0;}

    void ajouterArc(int s1, int s2, int weight){matrix[s1][s2]=weight;}
    int getLenght() const;
    void setLenght(int value);
    void addReloadPoint(int a){reloadPoints.push_back(a);}
    int getWeightAt(int s1, int s2){
        return matrix[s1][s2];
    }

    vector<string> getNamesSommets() const;
    void setNamesSommets(const vector<string> &value);

    void setNameAt(int a, string b);
    string getNameAt(int a);

    vector<vector<int> > getMatrix() const;
    void setMatrix(const vector<vector<int> > &value);

private :
    vector<int> reloadPoints;
    vector<vector<int>> matrix;
    int lenght;
    vector<string> namesSommets;

};

template<typename Out>
void split(const std::string &s, char delim, Out result);
std::vector<std::string> split(const std::string &s, char delim);

void lireGraphe(GRAPHE graphe);
int nbLines(string path);
int nbSommets(string path);
GRAPHE creerGraphe(string path, int index,int max, GRAPHE graphe);
void plusCourtChemin(GRAPHE graphe,int poid, int sommet1, int sommet2);
GRAPHE creerGrapheOriente(string path);

void afficheTousLesFils(int vieux, GRAPHE graphe,int cpt);
void theBestDisplayEver(GRAPHE graphe);
vector<int> giveMeChild(int node, GRAPHE graphe);
void displayListHasse(int node,string a, GRAPHE graphe);
void lireHasse(GRAPHE graphe);
void genererHasse(GRAPHE graphe);


#endif // GRAPHE_H
