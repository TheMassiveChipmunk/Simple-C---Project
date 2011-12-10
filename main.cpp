#include <iostream>
#include <string>

#include "Cat.h"

const int ARGS = 1;
string Arguments = "--";

void printUsage (ostream* , char*);
int isArg (int , char**);
string getFile (char*);

int main(int argc , char* argv[])
{
    if (argc == 1)
    {
	printUsage (&cout , argv [0]);
	return 0;
    }
    Cat MyCat (argc , argv);
    
    int nPos = isArg (argc , argv);
    ostream* Out = NULL;
    ofstream OutFile;

    if (nPos != -1)
    {
      	string Path = getFile (argv [nPos]);
      	OutFile.open (Path.c_str () , ios::app);
      	Out = &OutFile;
    }
    else
    {
	Out = &cout;
    }
    MyCat.print (Out);
    if (nPos != -1)
    {
	OutFile.close ();
    }
    return 0;
}

int isArg (int argc , char** argv)
{
    string Temp = "";
    int i = 0;
    int j = 0;
    int nPos = 0;
    for (i = 0 ; i < argc ; i++)
    {
	Temp = argv [i];
	for (j = 0 ; j < ARGS ; j++)
	{
	    nPos = Temp.find (Arguments [j]);
	    if (nPos != string::npos)
	    {
		return i;
	    }
	}
    }
    return -1;
}

string getFile (char* szFile)
{
    string Temp = szFile;
    Temp.replace (Temp.find (Arguments) , Arguments.length () , "");
    return Temp;
}

void printUsage (ostream* Out , char* argv)
{
    *Out << "Usage : %" << argv << "% FILES" << endl;
    *Out << "--YourFile to print to another file." << endl;
}
