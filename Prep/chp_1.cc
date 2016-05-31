#include "util.h"

using namespace std;

bool isUnique(const char* str, int length)
{
    unordered_map<char, bool> charmap;
    unordered_map<char, bool>::iterator it;
    // Could have simply used a bool array
    // or a bit map

    for (int i = 0; i < length; i++) {
        it = charmap.find (str[i]);
        if (it != charmap.end()) {
            return false;
        }
        charmap[str[i]] = true;
    }

    return true;
}

void reverseString(char* str, int length)
{
    char tmp;
    for (int i = 0; i < length/2; i++) {
        //swap i with length - i
        tmp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = tmp;
    }
}

void compressStr(char *str, int length)
{
    int j = 0, i = 0;

    while (j < length) {
        j = i;

        cout << "j is " << j << " i is " << i << endl;
        while (str[j] == str[i]) {
            j++;
        }
        
        // Were there duplicates
        if (j != i) {
            str[i+1] = '0' + (j - i);
            i = i + 2;
        }
    }
}

void imageRotate(int *point[], int length)
{
    //  

}


int main() 
{
    // 1.1 with unordered_map. Build a char hash. If key is set, string
    // does not have unique chars
    const char *str1 = "abcd";
    const char *str2 = "aabc";
    char str3[256] = "abcd";

    bool has_unique_chars = isUnique(str1, 4);

    cout << "Is str 1 unique " << has_unique_chars << endl;
    
    has_unique_chars = isUnique(str2, 4);
    cout << "Is str 2 unique " << has_unique_chars << endl;

    // 1.2 Reverse a null terminated string
    reverseString(str3, strlen(str3));
    cout << "Reversed str 3 is " << str3; 

    // 1.5
    strlcpy(str3, "aabcc", sizeof(str3));
    compressStr(str3, 5);
    cout << "Compressed str3 is " << str3; 

    strlcpy(str3, "abcd", sizeof(str3));
    compressStr(str3, 5);
    cout << "Compressed str3 is " << str3; 
    

}
