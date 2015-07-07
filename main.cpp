/* 
 * File:   main.cpp
 * Author: danny
 *
 * Created on March 9, 2015, 2:47 PM
 */


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <sys/types.h>
#include <unistd.h>
#include <boost/shared_ptr.hpp>
#include <pthread.h>
using namespace std;
using namespace boost;

void* thread( void *ptr )
{
    int i;
    for(i=0;i<3;i++)
        cout<<"This is a pthread.\n";
}
int main()
{
    pthread_t id;
    int i,ret;
    ret=pthread_create(&id,NULL,thread, NULL);
    if(ret!=0)
    {
        cout<<"Create Pthread Error!\n";
        exit(1);
    }
    
    for(i=0;i<3;i++)
    {
        cout<<"This is the main process.\n";
    }
   pthread_join(id,NULL);
   
    return 0;
    
}
