#include <iostream>
#include <fstream>

#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"



using namespace std;
DNA::DNA()
{
   this->type = tail ;
}
DNA ::DNA( DNA& other)  {
    this->len = other.len ;
    seq = new char [len];

    for (int i = 0 ; i < other.len ; i++) {
        seq[i] = other.seq[i] ;
    }
    this->type = other.type ;
}

DNA::~DNA()
{
    //ctor
}
string DNA::convertToProtein () {

    string x = seq ;
    for (unsigned int i = 0 ; i < x.size() ; i++)    if (x[i] == 'T') x[i] = 'U' ;
    string y = "" ;
    int copyoflen =  x.size()  ;
    string rna = "";
    for (unsigned int i=0 ; i < x.size() ; i+=3 , copyoflen-- )
    {
            for ( unsigned int j=i; j<i+3 ; j++ )
            {
                rna += x[j];
            }

            for (int j=0 ; j < 64 ; j++ )
            {
                if (rna == codons[j].value)
                {
                    y += codons[j].AminoAcid ;
                    break ;
                }
            }

            rna ="";
    }


    return y ;
}

DNA::DNA(char * seq, int len,  DNA_Type atype)
{
    for (int i = 0 ; i < len ; i++)
        if (seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i] != 'T' )  throw wrongSequence() ;
    this->len = len ;
    this->seq = seq ;
    this->type = atype ;
}
RNA DNA::ConvertToRNA()
{
    RNA r ;
    r.seq = new char [len];;
    r.seq = seq ;
    for (int i = 0  ; i < len ; i++)
    {
        if (r.seq[i] == 'T')
            r.seq[i] = 'U' ;
    }
    return r ;
}
void DNA::Print()
{
    string t ;
    if (type == 1)
        t = "promoter" ;
    if (type == 2)
        t = "motif" ;
    if (type == 3)
        t = "tail" ;
    if (type == 4)
        t = "noncoding" ;


    cout << "The sequence is  : " << seq << " - of type : " << t <<  endl;

}
void DNA :: BuildComplementaryStrand()
{
    (complementary_strand->seq) = seq ;
    for (int i = 0 ; i < len ; i++)
    {
        if((complementary_strand->seq[i] )== 'A')
            (complementary_strand->seq[i] ) = 'T';
        else if((complementary_strand->seq[i] ) == 'C')
            (complementary_strand->seq[i] ) = 'G';
        else if('G' == (complementary_strand->seq[i] ))
            (complementary_strand->seq[i] )  ='C';
        else if((complementary_strand->seq[i] ) == 'T')
            (complementary_strand->seq[i] ) == 'A';
    }

}
bool DNA::operator== (const DNA& other) const
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
bool DNA:: operator!= (const DNA& other) const
{
    return !(other == *this) ;
}
DNA DNA:: operator+ (const DNA& other) const
{
    DNA r ;
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
void DNA:: set_type (int i)
{
    type = static_cast<DNA_Type>(i);

}
string DNA::LoadSequenceFromFile(string filename )
{
    string loaded_data;
    ifstream input;

    filename +=".txt";
    input.open(filename.c_str());

    input >>  loaded_data ;
    input.close();

    return loaded_data;

}
void DNA::SaveSequenceToFile(char* data,string filename)
{
    filename += ".txt";
    ofstream outfile;
    outfile.open(filename.c_str());

    outfile << data;

    outfile.close();


}
