#include <iostream>
#ifdef WINDOWS
#include <windows.h>
#endif
#include <cmath>
#include <climits>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

std::vector<std::string> split_2( const std::string& original, char separator )
{
    std::vector<std::string> results;
    std::string::const_iterator start = original.begin();
    std::string::const_iterator end = original.end();
    std::string::const_iterator next = std::find( start, end, separator );
    while ( next != end ) {
        results.push_back( std::string( start, next ) );
        start = next + 1;
        next = std::find( start, end, separator );
    }
    results.push_back( std::string( start, next ) );
    return results;
}


void T_Split(string *Tableau, string Texte, unsigned long N, const char &Separateur)
{
    string *j = Tableau;
    string *M = Tableau + N-1;
    char A;

    for(unsigned long i = 0 ; i < Texte.length() ; i++)
    {
        A = Texte[i];

        if(A == Separateur)
        {
            j++;

            if(j > M) exit(1);
        }
        else
        {
            *j += A;
        }
    }
}

long Nombre_De_Colonnes(char *Nom_De_Fichier, const char &Separateur)
{
    ifstream Fichier(Nom_De_Fichier);
    string Ligne;
    long Nombre = 0;

    std::getline(Fichier, Ligne);

    for(unsigned long i = 0 ; i < Ligne.length() ; i++)
    {
        if(Ligne[i] == Separateur)
        {
            Nombre++;
        }
    }

    Fichier.close();

    return (Nombre + 1);
}

int main(int argc, char** argv)
{
  char *Nom_De_Fichier = NULL;
  if (1 < argc) {
    Nom_De_Fichier = argv[1];
  } else {
    Nom_De_Fichier = "C:/Tanguy/BDD/4 - Données fusionnées/Séries fusionnées triées.csv";
  }
  
  ifstream Fichier(Nom_De_Fichier);
  
  std::string Ligne;
  int i = 0;
  int N = Nombre_De_Colonnes(Nom_De_Fichier, ';');
  string Temporaire[N];
  while (std::getline(Fichier, Ligne)) {
      //std::vector<std::string> x = split(Ligne, ';');
      //cout << x.size() << endl;
      
    // string Temporaire[N];
      T_Split(Temporaire, Ligne, N, ';');
      
      //std::vector<std::string> x = split_2(Ligne, ';');
      
      /*if(i < 10)
        {
        for(int j = 0 ; j < N ; j++)
        {
        cout << Temporaire[j] << ' ';
        }
        
        cout << endl;
        }*/
      
      i++;
      if (Fichier.eof() || i > 100000) break;
    }

    cout << i << endl;

    return 0;
}

