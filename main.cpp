#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;


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


void heapify(int arr[], int place, int size) {
    
    int temp = arr[place-1];
    int a = arr[((place-1)/2)-1]; // parent
    int b = arr[(place/2)-1]; // parent
    if(place > 1 && place <= size) {
        if(place %2 == 0) {
            if(temp > b) {
                arr[place-1] = b;
                arr[(place/2)-1] = temp;
                heapify(arr,place/2, size);
            } else {
                heapify(arr,place+1, size);
            }
            
            
        } else if (place %2 == 1) {
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


void remove(int arr[], int size) {
    int count = 0;
    int sizeCount = size;
    int* sorted = new int[size];
    
    while(count < size) {
        sorted[count] = arr[0];
        for(int i = 1; arr[i] <=sizeCount; i++) {
            arr[i-1] = arr[i];
        }
        heapify(arr,1,sizeCount);
        count ++;
        sizeCount--;
        
    }
    
    for(int i = 0; sorted[i] != 0; i++) {
       
        cout << sorted[i] << " ";
        
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
    
    
    
   
     int count = 0;
    int modif[100];
    char fileName[30];
    
    for (int i = 0; i < 100; i++) {
        modif[i] = 0;
    }
     
    cout << "If you would like to input manually type '1' if you would like to do it from a file type '2':" << endl;
    
    char input[10];
    cin.get(input,10);
    cin.clear();
    cin.ignore(10,'\n');
    if(strcmp(input,"1")== 0) {
        cout << "Enter a set of numbers sperated by spaces:" << endl;
        char in[100000];
        cin.get(in, 100000);
        cin.clear();
        cin.ignore(1000000, '\n');
        parse(in,modif,count);
        int size = sizeof(modif)/sizeof(modif[0]);
        
        heapify(modif,1, size);
        
        visualize(modif,1,0);
        remove(modif, size);
        
    } else if(strcmp(input,"2")== 0) {
        
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
            remove(modif, size);
        }
      
        
    } else {
        cout << "Enter a valid option!" << endl;
    }
   
   

  
    
    


return 0;
}






