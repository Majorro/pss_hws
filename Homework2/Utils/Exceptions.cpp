#ifndef EXCEPTIONS
#define EXCEPTIONS

struct exception
{
    const char* text = "";
    const char * what () const throw ()
    {
    	return "C++ Exception";
    }
};

#endif /* EXCEPTIONS */