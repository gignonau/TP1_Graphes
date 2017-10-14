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
    void ajouterArc();
private :
    vector<int> reloadPoints;
    vector<vector<int>> matrix;

};

/*
class Sommet{
public :
    Sommet(int i, string n, bool r):id(i),name(n),reload(r){}

    int getId() const{return id;}
    void setId(int value){id = value;}

    string getName() const{return name;}
    void setName(const string &value){name = value;}

    bool getReload() const{return reload;}
    void setReload(bool value){reload = value;}

private :
    int id;
    string name;
    bool reload;

};

class Arc{
public :
    Arc(int d, int s1, int s2):distance(d),sommet1(s1),sommet2(s2){}
    int getDistance() const{return distance;}
    void setDistance(int value){distance = value;}

    int getSommet1() const{return sommet1;}
    void setSommet1(const int &value){}

    int getSommet2() const{return sommet2;}
    void setSommet2(const int &value);

private :
    int distance;
    int sommet1;
    int sommet2;

};*/
#endif // GRAPHE_H
