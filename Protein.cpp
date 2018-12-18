#include "Protein.h"
#include <iostream>
#include <fstream>
#include "Sequence.h"
#include "RNA.h"

using namespace std;


Protein::Protein()
{
    type = Cellular_Function ;
}

Protein ::Protein(const Protein& other )
{
    this->len = other.len ;
    seq = new char [len];
    for (int i = 0 ; i < len ; i++)
    {
        seq[i] = other.seq[i] ;
    }
    this->type = other.type ;
}


Protein::Protein( char* seq, int len, Protein_Type type)
{
    for (int i = 0 ; i < len ; i++)
    {
        if (( seq[i] != 'N' && seq[i] != 'K' &&seq[i] != 'T' &&seq[i] != 'R' &&seq[i] != 'S'

                &&seq[i] != 'I' &&seq[i] != 'M' &&seq[i] != 'Q' &&seq[i] != 'H' &&seq[i] != 'P'

                &&seq[i] != 'L' &&seq[i] != 'E' &&seq[i] != 'D' &&seq[i] != 'A' &&seq[i] != 'G'

                &&seq[i] != 'Y' &&seq[i] != '.' &&seq[i] != 'C' &&seq[i] != 'W' &&seq[i] != 'F'

                &&seq[i] != 'V' && seq[i] != 'R') )
            throw wrongSequence() ;
    }
    this->len = len ;
    this->seq = seq ;
    this->type = type ;
}

RNA Protein:: convertProteintoRNA()
{
    RNA r;
    r.len = 3*(this->len) ;
    r.seq = new char [r.len];
    int copyOflen = r.len ;
    for(int i=0 ; i < r.len ; i++, copyOflen -= 3)
    {
        for (int j=0; j<64; j++)
        {
            if(this->seq[i] == this->codons[j].AminoAcid)
            {
                r.seq[r.len - copyOflen] = this->codons[j].value[0];
                r.seq[r.len - copyOflen +1] = this->codons[j].value[1];
                r.seq[r.len - copyOflen +2] = this->codons[j].value[2];
                break;
            }
        }
    }
    return r ;

}

void Protein::Print()
{
    string t ;
    if (type == 1)
        t = "Hormon" ;
    else if (type == 2)
        t = "Enzyme" ;
    else if (type == 3)
        t = "TF" ;
    else if (type == 4)
        t = "Cellular_Function" ;
    cout << seq << " - of type ( " << t << " )\n" ;
}
bool Protein:: operator== (const Protein& other) const
{
    bool s = 1  ;
    if (this->len != other.len)
        return 0 ;
    else
    {

        for (int i = 0 ; i < len ; i++ )
        {
            if (seq[i] != other.seq[i])
            {
                s = 0 ;
                break;
            }

        }
    }
    return ( s && this->type == other.type) ;
}
bool Protein:: operator!= (const Protein& other) const
{
    return !(other == *this) ;
}
Protein Protein:: operator+ (const Protein& other) const
{
    Protein r ;
    r.type = this->type ;
    r.len = this-> len + other.len ;
    r.seq = new char [r.len];
    for (int i = 0 ; i < r.len ; i++)
    {
        if (i < len)
        {
            r.seq[i] = this->seq[i] ;
        }
        else
            r.seq[i] = other.seq[i-len] ;

    }
    return r ;
}
void Protein:: set_type (int i)
{
    type = static_cast<Protein_Type>(i);

}
string Protein::LoadSequenceFromFile(string filename )
{
    string loaded_data;
    ifstream infile;

    filename +=".txt";
    infile.open(filename.c_str());

    infile >>  loaded_data ;
    infile.close();

    return loaded_data;

}
void Protein::SaveSequenceToFile(char* data,string filename)
{
    filename += ".txt";
    ofstream file;
    file.open(filename.c_str());

    file << data;

    file.close();

}
string* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
{
    if (bigDNA.len < (3 * len))
        throw wrongSequence() ;
    else
    {
        string include = "", compareme, *possibleSeq;
        int first = 0, last = -1 + 3 * len ;  // first is concerned with the start of the part . for example : from 0 : 8 or 1 : 9
        for (int a = 0 ; a < bigDNA.len ; a++)
        {
            if (bigDNA.seq[a] == 'T')
                bigDNA.seq[a] = 'U' ;  // this loop makes sure that the given sequence is now RNA
        }

        for (int i = 0 ; i < ( bigDNA.len - (3 * len - 1)) ; i++, first++, last++)     // loop to cut the bigDna sequence into pieces
        {

            string rna, dna;
            for (int a = i ; a < i+8 ; a++)
            {
                dna += bigDNA.seq[a] ;       // take for example : 9 chars to convert to 3 proteins
            }
            int copyoflen = len  ;
            for (int k =0 ; k  < (3 * len ) ; k +=3, copyoflen-- )     // each cycle here is to look for a protein pattern a
            {
                for ( int a = k ; a < k +3 ; a++ )
                {
                    rna += dna[a];       // take just 3 chars to  convert to protein
                }

                for (int a = 0 ; a  < 64 ; a ++ )
                {
                    if (rna == codons[a].value)
                    {
                        compareme += codons[a].AminoAcid ;
                        break ;
                    }
                }
                rna ="";
                dna = "" ;
            }
            bool isProtein = 1 ;
            for (int b = 0 ; b < len ; b++)
            {
                if (compareme[b] != seq[b])
                {
                    isProtein = 0 ;
                    break ;
                }
            }
            if (isProtein)  include += compareme ;
            compareme = "" ;
        }
        cout << "the include is " << include << endl;
        possibleSeq = new string[include.size() / ( 3*len )] ;
        for (int i = 0 ; i < (include.size() / ( 3*len )) ; i++ )
        {
            possibleSeq[i] = include.substr(i,i+8) ;
        }
        for (int i = 0 ; i < (include.size() / ( 3*len )) ; i++ )
        {
            cout << possibleSeq[i] << " "  ;
        }
        return possibleSeq ;
    }
}
