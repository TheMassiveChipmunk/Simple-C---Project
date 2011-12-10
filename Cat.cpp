#include "Cat.h"

Cat::Cat (int argc , char* argv [])
{
    int i = 1;
    for (i = 1 ; i < argc ; i++)
    {
	this->Args.push_back (argv [i]);
    }
    this->CurrentLine = "";
}

void Cat::print (ostream* Out)
{
    vector <string>::iterator it = this->Args.begin ();
    for (it = this->Args.begin () ; it < this->Args.end () ; it++)
    {
	*Out << this->getFile (*it) << endl;
    }
    *Out << endl;
}

string Cat::getFile (string File)
{
    string Contents = "";
    string Temp = "";
    ifstream Reader (File.c_str ());
    if (Reader.is_open ())
    {
	while (Reader.good ())
	{
	    getline (Reader , Temp);
	    Contents += Temp;
	    Contents += "\n";
	}
    }
    Reader.close ();
    return Contents;
}
