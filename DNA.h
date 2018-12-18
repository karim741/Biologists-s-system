#ifndef DNA_H
#define DNA_H
#include <iostream>
#include <fstream>
#include "Protein.h"

using namespace std;

enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
    private:

        DNA_Type type;
        DNA * complementary_strand;
    public:
 	 	// constructors and destructor
        DNA();
        DNA (DNA& other) ;
        DNA(char * seq, int endIndex ,DNA_Type atype);
        ~DNA();
        string convertToProtein () ;

        bool operator== (const DNA& other) const ;
        bool operator!= (const DNA& other) const ;
        DNA operator+ (const DNA& other) const ;
        friend istream& operator>> (istream& in , DNA& d) ;
        friend ostream& operator<< (ostream& out  , DNA& d) ;

        void set_type (int i) ;
 	 	// function printing DNA sequence information to user
        void Print();
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();

 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.

         string LoadSequenceFromFile(string filename );
         void SaveSequenceToFile(char* data,string filename);

        void BuildComplementaryStrand();
  };

#endif // DNA_H
