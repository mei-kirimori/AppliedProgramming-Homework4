#include <iostream>
using namespace std;
const char* str_match(const char* s1, const char* s2)
{
    int loop = 0;
    int zureloop = 0;
    int zurecount = 0;
    while (s2[loop] != '\0')
    {

        if (s1[zureloop] == '\0')
        {
            return nullptr;
        }


        if (s1[zureloop] == s2[loop])
        {
            ++loop;
            ++zureloop;
        }
        else
        {
            zurecount++;
            loop = 0;
            zureloop = zurecount;
        }
    }
        return &s1[zurecount];
    
   
}



int main()
{
    char s1[] = { "qergsaabcdefghgwrhvd"};
    char s2[] = { "abcdefg" };
    const char* result = str_match(&s1[0], &s2[0]);

    if (result != nullptr)
    {
        cout << s1[result - &s1[0]] << endl;
		cout << result - &s1[0] << "番目" << endl;
    }
    else
    {
        cout << "一致する文字列がありません";
    }
}
