#include <iostream>
#include <cstring>

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


void heapify(int arr[], int place) {
    
    int temp = arr[place-1];
    //cout << temp << endl;
    if(temp < arr[2*place] || temp < arr[2*place-1]) {
        cout << arr[2*place] << "\t" << arr[2*place-1] << endl;
        if(arr[2*place] > arr[2*place-1]) {
            int a = arr[2*place];
            int b = arr[2*place-1];
            arr[place-1] = a;
            arr[2*place] = temp;
            heapify(arr,place*2+1);
            
        } else {
            int a = arr[2*place];
            int b = arr[2*place-1];
            arr[place-1] = b;
            arr[2*place-1] = temp;
            heapify(arr,2*place-1);
            
            
        }
        
    } else {
      
        
       
        
        
        
    }
    
    
    
    
    
}


int main() {
    
    
    
    // Parsing method from Stefan Ene https://github.com/Stefanene
     int count = 0;
    int modif[100];
    for (int i = 0; i < 100; i++) {
        modif[i] = 0;
    }
    cout << "Enter numbers separated by space:" << endl;
    char in[100000];
    cin.get(in, 100000);
    cin.clear();
    cin.ignore(1000000, '\n');
    int l = 0;  //keeps track of # of chars before space
    for (int i = 0; i < strlen(in); i++) {
        if (in[i] == ' ') {
            if (l == 1) {
                int temp = 0;
                //cout << in[i-1] -'0';
                temp = in[i-1] - '0';
                modif[count] = temp;
                count++;
                l = 0;
            } else {
                int temp = 0;
                for (int a = 0; a < l; a++) {
                   // cout << in[i-l+a] - '0';
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
                    // cout << in[i+a+1-l] - '0';
                    temp = 10 * temp + (in[i+a+1-l] - '0');
                }
                modif[count] = temp;
                count++;
            }
        }
    }
    
    heapify(modif,1);
    cout << "a" << endl;
    visualize(modif,1,0);
  
    
    


return 0;
}
