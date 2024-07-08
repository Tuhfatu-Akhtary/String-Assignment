int getHashValue(string s)   //Function declaration to get the hash value
{
    int h=0,i;           //variable declaration and initializing the value of h,which is the hash value
    int n=s.length();    //Length of string s is assigned to n
    for(i=0;i<n;i++)     //for loop to traverse the string
    {
        h+=s[i]-'A';     //h is assigned with the sum of the value of previous h and the ascii value of i th element of S
    }
    return h;            //Hash value is returned
}

int checkStringEqual(string x,string y)    //Function declaration to check if the strings are equal or not
{
    int len=x.length(),i;  //Length of string x is assigned to len variable
    for(i=0;i<len;i++)     //For loop to traverse String x and y
    {
        if(x[i]!=y[i])     //condition check if i th element of string x is not equal to i th element of string y 0 is returned
        {
            return 0;
        }
    }
    return 1;     //if string x is equal to string y then 1 will be returned

}

int searchOccurrence(string haystack,string needle)   //Function declaration to search first occurrence
{
    int len_haystack=haystack.length();  //length of haystack is assigned to variable len_haystack
    int len_needle=needle.length();    //length of needle is assigned to variable len_needle

    int needleHash=getHashValue(needle);   //hashvalue of needle is assigned to needleHash

    int temp_haystackHash=getHashValue(haystack.substr(0,len_needle));   //hashvalue of haystack from index 0 to ken_needle is assigned to temp_haystackHash

    if(needleHash==temp_haystackHash)   //condition check if hashvalue of needle and haystack from index 0 to needles length is equal
    {
        if(checkStringEqual(needle, haystack.substr(0,len_needle)))   //condition check if the characters of the strings are equal
        {
            return 0;   //if the characters are same then 0 is returned
        }
    }
    for(int i=1;i<len_haystack-len_needle+1;i++)   //for loop from index 1 to less than the subtraction of needles length from haystacks length
    {
        temp_haystackHash= temp_haystackHash-(haystack[i-1]-'A')+(haystack[i+len_needle-1]-'A');  //Rolling hash calculation

        if(temp_haystackHash!=needleHash)   //condition check if haystack hash is not equal to needle hash then the loop will be continued
        {

            continue;
        }

        if(checkStringEqual(needle,haystack.substr(i,len_needle)))    //condition check if the needle and substring of haystack is equal then the index i will be returned
        {
            return i;
        }

    }

    return -1;    //if there is no occurrence of needle then -1 will be returned
}


//Time Complexity : O(n*m)
//Space Complexity: O(1)