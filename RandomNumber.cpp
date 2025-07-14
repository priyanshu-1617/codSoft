#include <iostream>
#include <random>

using namespace std;

int main(){
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> distr(1,100);// the range is 1 - 100

  int random_number = distr(gen);
 // cout<<random_number;
  

  bool isWon = false;
  while(!isWon){
    int n;
    cout<<"Guess the number(1-100) : ";
    cin>>n;
    
    if(n > random_number){
      cout<<"The number you guessed is greater than target\n";
    }
    else if(n < random_number){
      cout<<"The number you guessed is less than target\n";
    }
    else{
      cout<<"You won!!! the number is "<<random_number<<endl;
      isWon = true;
    }
  }
}
