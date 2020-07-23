// variadic.c by Bill Weinman <http://bw.org/>
// updated for C++EssT 2014-10-24
#include <cstdio>
#include <cstdarg>

// c++ allows for variable size argument list, as in c???

// first argument is int count of remaining args
// ... remaining args are doubles for average
double average(const int count, ...)
{
  va_list ap; // va_list is a macro, ap is aguments after count
  int i;
  double total = 0.0;
    
  va_start(ap, count); // count is the last variable expicitly declared
  for(i = 0; i < count; ++i) {
    // grabs the next variable from the list and next arguent declares its type
    total += va_arg(ap, double);
  }
  va_end(ap); // must be called when your done.
  return total / count;
}

// works like printf, format plus args
int message(const char * fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int rc = vfprintf(stdout, fmt, ap);
  puts("");
  va_end(ap);
  return rc;
}

int main( int argc, char ** argv ) {
  message("This is a message");
  message("Average: %lf", average(5, 25.0, 35.7, 50.1, 127.6, 75.0));
  return 0;
}

