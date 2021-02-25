#ifndef EXCEPTIONS
#define EXCEPTIONS

struct wrong_access_exception
{
    const char* text = "";
    const char * what () const throw ()
    {
    	return "C++ Exception";
    }
};

#endif /* EXCEPTIONS */