string shuffledString(string S,int A[]){  //Function Declaration
    string C;      //A new string declaration
    int i,n;     //Variable declaration
    n=S.length();   //Assigning the length of string S to n variable
    for(i=0;i<n;i++)  //loop to traverse the array and the string
    {
        C[A[i]]=S[i];    //the value of i th index of string S is assigened to the A[i] th index of string S;
    }
    for(i=0;i<n;i++)   //loop to print the string C;
    {
        cout<<C[i];
    }
}



//Time complexity : O(n)
//Space complexity : O(1)

