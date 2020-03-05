/*
 Following function utilizes the heap sort in order to sort a group of numbers either inputted manually or from a file.
 By:Deyvik Bhan
 Date: 2/26/20
 Thank you to Omar, Stefan and Wikipedia
 
 
 */


#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

// Following function is used to visualize the heap
void visualize(int arr[], int n, int levels) {
    for(int i = 0; i < levels; i++) {
        cout << " ";
    }
    cout << arr[n-1] << endl;
    int b = n*2;
    if(arr[b] != 0) {
        visualize(arr, b+1, levels +1);
        
    }
    if(arr[b-1] !=0) {
        visualize(arr,b,levels+1);
    }

    
}

// Following function creates the max heap
void heapify(int arr[], int place, int size) {
    
    int temp = arr[place-1];
    // Root
    int a = arr[((place-1)/2)-1]; // parent
    int b = arr[(place/2)-1]; // parent
    if(place > 1 && place <= size) {
        // If is past first index
        if(place %2 == 0) {
            // If place is left child
            if(temp > b) {
                arr[place-1] = b;
                arr[(place/2)-1] = temp;
                heapify(arr,place/2, size);
            } else {
                heapify(arr,place+1, size);
            }
            
            
        } else if (place %2 == 1) {
            // If place is right child
            if(temp > a) {
                arr[place-1] = a;
                arr[((place-1)/2)-1] = temp;
                heapify(arr,((place-1)/2),size);
            } else {
                heapify(arr,place+1,size);
            }
            
        }
        
        
    } else {
        
        if(place <= size) {
        heapify(arr,place+1,size);
        }
    }
    
    
    
}

// Function used to fix the heap once the swap of the first and last thing in array occurs
void siftDown(int arr[], int start, int end) {
    int root = start;
    while((root*2) <= end) {
        // While there is a left node
        
        if((root*2)+1 <= end) {
            // If there is a right node
          //  cout << root << " " << (root*2)+1 <<endl;
            
            if(arr[root-1] < arr[(root*2)-1] || arr[root-1] < arr[(root*2)] ) {
                // If root is less then left or right node
            if(arr[(root*2)-1] < arr[(root*2)]) {
                // Whichever child is greater switch it with root
                int a = arr[(root*2)];
                int b = arr[root-1];
                arr[root-1] = a;
                arr[(root*2)] = b;
                siftDown(arr,(root*2)+1,end);
                // Call sift on the switched child
                
            } else {
                // Whicever child is greater switch it with root
                int a = arr[(root*2)-1];
                int b = arr[root-1];
                arr[root-1] = a;
                arr[(root*2)-1] = b;
                siftDown(arr,root*2,end);
                // Call sift on switched child
                
            }
            } else {
                
                break;
            }
        
        } else {
            // If there is only a left child
            if(arr[root-1] < arr[(root*2)-1]) {
                int a = arr[root-1];
                int b = arr[(root*2)-1];
                arr[root-1] = b;
                arr[(root*2)-1] = a;
                siftDown(arr,root*2,end);
                // Switch the child and root and call sift on new child
                
                
            } else {
                break;
            }
            
            
        }
        
    
    }
 
    
 
}

// Following function is used to sort the heap
void remove(int arr[], int size, int place) {
    int count = 0;
    int* final = new int[100];
    // New array
     size = 0;
    int i = 0;
    while(arr[i] != 0) {
         size++;
        i++;
        
    }
    // Gets size of array
    //int final = size;
    int end = size;
 
    // Psuedo code gotten from wikipeida
    while(end-1 > 0) {
        // While the array still has size
        int a = arr[end-1];
        int b = arr[0];
        arr[0] = a;
        final[count] = b;
        count ++;
        // Switches first and last and puts top of heap in new array
        
        end = end-1;
        // Reduces the size of teh array
        siftDown(arr,1,end);
        // Calls sift on new array
        
        
    }
    final[count] = arr[0];
    // Puts last element in the original array into the final array
    
    
    // Prints out sorted numbers
    for(int i = 0; final[i] != '\0'; i++) {
    
        cout << final[i] << " " ;
    }
  
    cout << endl;
 
    
    
}



// Following parse function from Stefan Ene https://github.com/Stefanene/Heap/blob/master/main.cpp
void parse(char* in, int* modif, int &count) {
    int l = 0;  //keeps track of # of chars before space
    for (int i = 0; i < strlen(in); i++) {
        if (in[i] == ' ') {
            if (l == 1) {
                int temp = 0;
                temp = in[i-1] - '0';
                modif[count] = temp;
                count++;
                l = 0;
            } else {
                int temp = 0;
                for (int a = 0; a < l; a++) {
                    temp = 10 * temp + (in[i-l+a] - '0');
                }
                modif[count] = temp;
                count++;
                l = 0;
            }
        } else {
            int temp = 0;
            l++;
            if (i == strlen(in) - 1) {  //last possible pair of chars
                for (int a = 0; a < l; a++) {
                    temp = 10 * temp + (in[i+a+1-l] - '0');
                }
                modif[count] = temp;
                count++;
            }
        }
    }
}


int main() {
    
    
    // Just the input stuff
   
     int count = 0;
    int modif[100];
    char fileName[30];
    
    for (int i = 0; i < 100; i++) {
        modif[i] = 0;
    }
     
    cout << "If you would like to input manually type '1' if you would like to do it from a file type '2':" << endl;
    char inp[10];
    char input[100000];
    cin.get(inp,10);
    cin.clear();
    cin.ignore(1000000,'\n');
    if(strcmp(inp,"1")== 0) {
        cout << "Enter a set of numbers sperated by spaces:" << endl;
        char in[100000];
        cin.get(in, 100000);
        cin.clear();
        cin.ignore(1000000, '\n');
        parse(in,modif,count);
        int size = sizeof(modif)/sizeof(modif[0]);
        
        heapify(modif,1, size);
        
        visualize(modif,1,0);
        remove(modif, size,0);
        
    } else if(strcmp(inp,"2")== 0) {
        
        // Following chunk from Omar Nassar
        cout << endl << "What is the name of the file?" << endl << ">> ";
        cin.get(fileName, 30);
        cin.clear();
        cin.ignore(100000, '\n');
        streampos size;
        ifstream file(fileName, ios::in | ios::binary | ios::ate);
        if (file.is_open()) {
            size = file.tellg();
            file.seekg(0, ios::beg);
            file.read(input, size);
            file.close();
            parse(input,modif,count);
            
           
            int size = sizeof(modif)/sizeof(modif[0]);
            
            heapify(modif,1, size);
            
           visualize(modif,1,0);
            remove(modif, size,0);
        }
      
        
    } else {
        cout << "Enter a valid option!" << endl;
    }
   
   

  
    
    


return 0;
}






