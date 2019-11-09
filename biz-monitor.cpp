#include <iostream>

using namespace std;

//PROTOTYPE
int getAmount();

int main(){
	//INTAILIZE 
	int amount;
	char category;
	string date_spent;
	char category_e;

	//INPUT
	cout<<"Welcome,Enter your category"<<endl;
	cout<<"I - Income Amount     E - Expenses"<<endl;
	cin>>category;
	if(category == 'I' || category == 'i'){

		amount = getAmount();	
	}else if(category == 'E' || category == 'e'){
	cout<<"Select category of expenses"<<endl;
	cout<<"S - Shopping  E - Enternment N - Snacks  O - Others"<<endl;
	cin>>category_e;
		if(category_e == 'S' || category_e == 's'){
			amount  = getAmount();
		}else if( category_e == 'E' || category_e == 'e'){
			amount = getAmount();
		}else if(category_e == 'N' || category_e == 'n'){
			amount = getAmount();
		}else if(category_e == 'O' || category_e == 'o'){
			amount = getAmount();
		}else{
			
		}
	}
	
	//COMPARE INPUT
	//WRITE ON FILE	
		
      
	return 0;
}

int getAmount(){
	int amount;
	cout<<"Enter Amount(It should be more than 0)"<<endl;
	cin>>amount;
	if(amount >0){
		return amount;		
	}else{
	cout<<"Invalid input,Enter Amount."<<endl;	
	int n;	
	      n=getAmount();
	      return n;

	}	
}
