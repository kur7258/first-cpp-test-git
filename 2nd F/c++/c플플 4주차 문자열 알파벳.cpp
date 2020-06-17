#include <iostream> 
#include <string> 
using namespace std;

char mors_to_alpha(string mors)
{
    static string morsL[26] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--.."
    };

    for (int i = 0; i < 26; i++)
    {
        if (mors == morsL[i]) return 'A' + i;
    }

       
}

void print_mors(string mors)
{
    int begin = 0;    

    while (true)
    {
        int end = mors.find('|', begin);//0 - |
        if (end == string::npos) break;
        cout << mors_to_alpha(mors.substr(begin, end - begin));
        begin = end + 1;
    }

    cout << mors_to_alpha(mors.substr(begin, mors.length() - begin)) << endl;
}

int main()
{    
    string mors;
    
    cout << "모스부호 입력 : ";
    getline(cin,mors);

    print_mors(mors);

    return 0;
}