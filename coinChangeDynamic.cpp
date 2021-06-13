#include<iostream>
#include<algorithm>

using namespace std;


int ChangingingFunction(int coinArray[], int size, int sum)
{


    int DynaProg[size+1][sum+1];

    for(int j=0; j<=sum; j++)
    {
        DynaProg[0][j]=INT_MAX;
    }

    for(int i=1; i<=size; i++)
    {
        DynaProg[i][0]=0;
    }

    int temp1,temp2;
    for(int i=1; i<=size; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j>=coinArray[i-1])
            {
                temp1=DynaProg[i-1][j];
                temp2=1+DynaProg[i][j-coinArray[i-1]];
                DynaProg[i][j]=min(temp1,temp2);
            }

            else
            {
                DynaProg[i][j]=DynaProg[i-1][j];
            }
        }
    }

    return DynaProg[size][sum];
}

int main()
{

    int size,sum;

    cout<<"Enter the size : "<<endl;
    cin>>size;

    int coinArray[size];

    cout<<"Enter the coin value : "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>coinArray[i];
    }

    cout<<"Enter the final coin : "<<endl;
    cin>>sum;

    cout<<"this coin are uses>>>>: "<<endl;

    cout<<ChangingingFunction(coinArray,size,sum)<<endl;

    return 0;
}
