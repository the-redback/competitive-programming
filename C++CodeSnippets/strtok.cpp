#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "cuet, cse- society. Hahaha";
    char* pch;
    char a[100][100];
    int i = 0;
    pch = strtok(str, " ,.-");
    while (pch != NULL) {
        strcpy(a[i], pch);
        printf("%s\n", a[i++]);
        pch = strtok(NULL, " ,.-");
    }
    return 0;
}

// ================================[ MORE ]========================================
// while (pch != NULL)                   or, while (pch != 0)
//     {
//         string s;
//         s=pch;
//         printf ("%s\n",s.c_str());    or, printf ("%s\n",pch);
//         pch = strtok (NULL, " ,.-");  or, pch = strtok (0, " ,.-");
//     }
// ================================[ OUTPUT ]=======================================
// output:
// cuet
// cse
// society
// Hahaha