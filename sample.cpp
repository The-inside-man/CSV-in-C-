//////////////////////////////////////////////////////////////////
//	Name	:	Jacob Brown				//			
//	Title	:	Example CSV Code c++			//
//////////////////////////////////////////////////////////////////

#include "sample.h"

/* 	You will need to edit these numbers to match 
	the number of questions you have in your csv
	file */

#define TOTAL_NUMBER_OF_QUESTIONS 10

using namespace std;

/*	This function will display a random question
	and return an integer to the correct answer
	for that question starting from 1 - 4 */

int get_random_question(){
	/* 	Here we will declare some variables that will be used in
		this program. */
	
	//int used_indexes[TOTAL_NUMBER_OF_QUESTIONS];	// Array to store indexes to questions already used
	
	srand(time(NULL));								// Random number generater is initialized
	
	int random_index = rand() % TOTAL_NUMBER_OF_QUESTIONS + 1;	// we obtain a random index 
	
	int this_index = 0; 							// Index of question in the csv file
	
	int index_of_answer = 0;						// we will assign the index to the answer here
	
	/*	First thing you will need to do is open the file
		I have included an example of what the file should
		look like so that everything gets read in properly. */	
	ifstream input_file("questions.csv");
		
	/*	We have now opened a file called questions.csv and 
		it will eb referred to in this program by the variable
		name input_file. */
	
	/*	Next we must go through the file separating the data
		by the commas and making it useable to us to show the 
		user. */
	
	/* 	This is the variable used that will store the data
		between each comma in the csv file. */
	string data;
	
	/* 	We also need to keep track of which position we are at
		in the csv file in order to know if we are looking at a 
		question or an answer. For this reason we will use an 
		integer as a counter to keep track.	*/
	int ctr = 0;	
	
	/* 	Here we need to adjust the index of the random_index so it
		points to the correct index of each question in the file.
		Since the beginning of each question in the file is at each
		multiple of 6 we need to multiply our random number by 6 to
		point at the appropriate spot. */
	random_index = random_index * 6;
	
	/* 	This first line goes through the file until it reaches 
		the end of the file which the file will then be considered
		no longer "good". */
	while(input_file.good()){
		/* 	This next line is where we get each line of the csv
			file up to each comma. We will have to store each
			piece of data in a variable and store the parts
			we plan to use. For this example it will be the 
			question and the 4 possible answers */
		getline(input_file, data, ',');
		
		/*	We dont want to actually analyze any of the file 
			unless we are at the index for the question we 
			are randomly selecting. When this_index is equal
			to the random_index that we chose previously we 
			then look at the question and its answers and 
			display them to the user while returning the 
			index to the correct answer once complete.*/
		if(this_index == random_index){
		
			if(ctr == 0){
				/* 	If the counter is at 0 we know we are looking at a 
					question */
				cout << "Question : " << data << endl;
				cout << "_______________________________________________________________________" << endl;
				this_index--;
			}else if(ctr == 1){
			/* 	Here we are looking at the first possible answer */
				cout << "1) " << data << endl;
				this_index--;
			}else if(ctr == 2){
			/* 	Here we are looking at the second possible answer */
				cout << "2) " << data << endl;
				this_index--;
			}else if(ctr == 3){
			/* 	Here we are looking at the third possible answer */
				cout << "3) " << data << endl;
				this_index--;
			}else if(ctr == 4){
			/* 	Here we are looking at the fourth possible answer */
				cout << "4) " << data << endl;
				this_index--;
			}else if(ctr == 5){
			/* 	Here we are looking at the index to the correct 
				answer */
				index_of_answer = atoi(data.c_str());
				this_index--;
			}else{
			/* 	Here we must now re-initialize the counter to 0 
				since we will be at the position of the next question */
				ctr = 0;
				
			}
			ctr++;
			
		}
		
		this_index ++;
		
	}
	
	/* 	Here we close the file after we are done using it */
	input_file.close();	
	
	/*	 Now we return the index of the answer so we know what the answer is */
	return index_of_answer;
}
int main(){
	/* 	This is the main program so you can see the function working.
		What we would typically do here is ask for the user to input 
		their answer in the form of an int or whatever and compare 
		that to the answer index returned form the function. If they
		match then the user got the question right. Otherwise they
		got it wrong. */
	while(true){
		int answer = get_random_question();
	
		string in = "";
	
		int val = 0;
	
		cout << "What is your guess?" << endl;
		while(true){
			getline(cin, in);
		
			stringstream input(in);
			if(input >> val){
				break;
			}
			cout << "Please enter a value from 1 to 4" << endl;
			cin.clear();
		}
	
		if(val == answer){
			cout << "CORRECT! You guess right!" << endl;
		}else {
			cout << "WRONG! That was no where near the right answer..." << endl;
		}
	
		cout << "Play again? (y,n)" << endl;
		while(true){
			getline(cin, in);
		
			if(in == "y" || in == "Y"){
				break;
			}else{
				cout << "Thanks for playing!" << endl;
				return 1;
			}
		}
	}
}
