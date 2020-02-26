#include <iostream>

int main() {
    
    
    
    // Parsing method from Stefan Ene https://github.com/Stefanene
    char** modif = new char*[100];  //clear char* array
   
    //begin input splitting:
    //break input by spaces
    int l = 0;  //keeps track of # of chars before space
    int count = 0; //number of chars
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            if (l == 1) {
                char *temp = new char[10];
                for (int z = 0; z < sizeof(temp); z++) {  //clear temp memory
                    temp[z] = 0;
                }
                temp[0] = input[i-1];
                modif[count] = temp;
                count++;
                l = 0;
            } else {
                char *temp = new char[10];
                for (int z = 0; z < sizeof(temp); z++) {  //clear temp memory
                    temp[z] = 0;
                }
                for (int a = 0; a < l; a++) {
                    temp[a] = input[i-l+a];
                }
                modif[count] = temp;
                count++;
                l = 0;
            }
        } else {
            char *temp = new char[10];
            for (int z = 0; z < sizeof(temp); z++) {  //clear temp memory
                temp[z] = 0;
            }
            l++;
            if (i == strlen(input) - 1) {  //last possible pair of chars
                for (int a = 0; a < l; a++) {
                    temp[a] = input[i+a+1-l];
                }
                modif[count] = temp;
                count++;
            }
        }
    }


return 0;
}
