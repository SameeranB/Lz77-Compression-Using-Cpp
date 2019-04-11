
#include<string.h>
#include <iostream>

using namespace std;
int main()
{
    char str[13]="abracadabra";
    char sb[10]={'\0'},lb[10]={'\0'};
    int i,j,c=0,k=0,m,l,len,flag;

    strcpy(str,"abracadabra");
    cout<<"Given string is: "<<str;
    for(i=0;i<5;i++)
    {
        lb[i]=str[i]; // store first 5 characters in look ahead buffer
    }
    for(i=0;i<11;i++)
    {
        str[i]=str[i+5]; // move remaining characters to the front of the string
    }

    for(m=0;m<6;m++)
    {
        i=0;
        j=0;
        flag=0;
        len=strlen(sb);
        cout<<"\nlength of sb : "<<len;
        while(flag==0 && i<len)
        {
            if(sb[i]==lb[0])  // checking for matching characters
            {
                flag=1;
                for(l=0;l<len;l++)
                {
                    if(sb[l]==lb[0]) // checking for matching characters - finding first character
                    {
                        if(sb[l+1]!=lb[1] && sb[i+1]==lb[1])
                        {
                            c=i;
                        }
                        else
                        {
                            c=l;
                        }
                    }
                }

                if(c>0)
                {
                    for(l=c;l<len;l++) // checking for matching characters - checking how many of them are repeated
                    {
                        if(sb[l]==lb[j])
                            j++;
                    }
                }
                else
                {
                    for(l=0;l<strlen(lb);l++)
                    {
                        if(sb[l]==lb[j])
                            j++;
                    }
                }
            }
            else
            {
                i++;
            }
        }
        cout<<"\n<"<<c<<","<<j<<","<<lb[j]<<">"; // printing resultant compression
        if(k==7) // transferring to search buffer - max size is 7 (k = currently filled)
        {
            for(i=0;i<7;i++)
            {
                if(strlen(lb)>j)
                {
                    sb[i]=sb[j+i+1]; // delete the oldest few characters from the search buffer
                }
                else
                    sb[i]=sb[j+i];

            }
            if(strlen(lb)>j)
            {
                for(i=0;i<j+1;i++)
                {
                    sb[k-j-1]=lb[i]; // clear out last j spaces to put in j more from look ahead buffer
                    k++;
                }
            }
            else
            {
                for(i=0;i<j+1;i++)
                {
                    sb[k-j]=lb[i];
                    k++;
                }
            }
        }
        else
        {
            for(i=0;i<j+1;i++)
            {
                sb[k]=lb[i]; // adding to search buffer
                k++;
            }
        }
        for(i=0;i<(4-j);i++)
        {
            lb[i]=lb[i+1+j]; // j is the position of last matched character - removing that many elements from look ahead buffer
        }
        for(l=0;l<j+1;l++)
        {
            lb[i]=str[l]; // adding more elements from the string to look ahead buffer
            i++;
        }
        if(str!="\0") // when string has not become empty - bring remaining characters to the front
        {
            for(l=0;l<13;l++)
            {
                str[l]=str[l+1+j];
            }
            for(l=13;l>(13-j);l--)
            {
                str[i]='\0';
            }

        }
        cout<<"\n In sb: "<<sb;
        cout<<"\t\t In lb: "<<lb;
        cout<<"\t\t In str: "<<str;

    }

    return 0;
}