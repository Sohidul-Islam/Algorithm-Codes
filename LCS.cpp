#include <bits/stdc++.h>
using namespace std;

void LCS(char S1[], char S2[], int m, int n)
{
    int DATA[m + 1][n + 1];


    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0 || j == 0)
                DATA[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
            {

                DATA[i][j] = DATA[i - 1][j - 1] + 1;

            }

            else
            {


                DATA[i][j] = max(DATA[i - 1][j], DATA[i][j - 1]);

            }

        }
    }



    for (int i = 0; i <= m; i++)
    {

        for (int j = 0; j <= n; j++)
        {

            cout<<DATA[i][j]<<" ";
        }
        cout<<endl;
    }

    int index = DATA[m][n];
    cout<<"LCS length: "<<index<<endl;

    char LCS[index];
    LCS[index] = '\0';//01

    int i = m, j = n;

    while(i > 0 && j > 0)
    {
        if( DATA[i][j] == DATA[i-1][j] )
        {
            i--;
        }
        else if( DATA[i][j] == DATA[i][j-1] )
        {
            j--;
        }
        else
        {
            LCS[index - 1] = S1[i - 1];

            i--;
            j--;
            index--;
        }
    }


    // Printing the sub sequences
    cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << LCS << "\n";
}

int main()
{
    char S1[] = "ACADB";
    char S2[] = "CBDA";
//    BACDB
//    BACDB
    int m = strlen(S1);//5
    int n = strlen(S2);//4

    cout<<m<<endl;
    cout<<n<<endl;

    LCS(S1, S2, m, n);
}
