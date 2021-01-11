#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100000000

using namespace std;

enum Make{
   GLASS, STONE
};
struct Marble
{

   Make make;
};

class BagOfMarble
{
   private:
       // create a root node for the marbles linked list
       Marble * marbleArray;
       // variable to store number of marbles in the bag
       long long marbleCount;
       // array capacity
       long long arrayCapacity;
   public:
       // declaring the functions. all wioll be defined outside class.
       BagOfMarble();
       void add(Marble marble);
       Marble remove();

};

BagOfMarble::BagOfMarble()
{
   // change this to increase the size of array .
   // 3 is just to demo how the size increase works
   arrayCapacity = 3;
   // allocate storage for 1000 marbles
   marbleArray = new Marble[arrayCapacity];
   // marble count set to 0
   marbleCount = 0;

}
void BagOfMarble::add(Marble marble)
{
   // check if whether array need to be resized
   if(marbleCount>= arrayCapacity)
   {
       cout<<"Bag is full, increasing size of bag."<<endl;
       // double the array size variable
       arrayCapacity += arrayCapacity;
       // check if arraycpaicty is over max size
       if(arrayCapacity > MAX_SIZE)
       {
           // set array cpacity as max size
           arrayCapacity = MAX_SIZE;
       }
       // create a temporay array and copy marbles in to it
       Marble * tempArray = new Marble[arrayCapacity];
       for(int i = 0; i < marbleCount; i++)
       {
           tempArray[i] = marbleArray[i];
       }
       // cleanup original
       delete [] marbleArray;
       // point the original to new array
       marbleArray = tempArray;
   }
   cout<<"Adding marble to bag."<<endl;
   // add the marble to array
   marbleArray[marbleCount] = marble;
   // increment marble counter
   marbleCount++;
}
Marble BagOfMarble::remove()
{
   //generate a random number between 0 and marbleCount
   long long idx = rand() % (marbleCount + 1);
   // return marble at index idx
   return marbleArray[idx];
}

int main()
{
   // seed for the random number generator
   // only once
   srand(time(NULL));
   // create marble bag instance
   BagOfMarble bag;
   // create 3 marbles
   Marble m1,m2,m3;
   m1.make = GLASS;
   m2.make = STONE;
   m3.make = STONE;



   //add marbles to bag
   bag.add(m1);
   bag.add(m2);
   bag.add(m3);

   // remove random one from bag
   Marble m = bag.remove();
   cout<<"Make : ";
   if(m.make == GLASS)
       cout<<"GLASS";
   else
       cout<<"STONE";

    system ("pause");
}