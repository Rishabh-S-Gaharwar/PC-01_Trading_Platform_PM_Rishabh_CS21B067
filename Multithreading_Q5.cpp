#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_T 2 //Number of threads
#define NUM_P 2 //Number of times we're supposed to print "Hello World!"

void *Print(void *threadid) {
    for(int i=0; i<NUM_P; i++){
       cout << "Hello World! " << endl;
    }
    cout<<"\n"<<endl;
    pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_T];
   int rc;
   long i;
   
   for( i = 0; i < NUM_T; i++ ) {
      rc = pthread_create(&threads[i], NULL, Print, (void *)i);
      
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}

//Add '-pthread' before '-o' to run the code successfully