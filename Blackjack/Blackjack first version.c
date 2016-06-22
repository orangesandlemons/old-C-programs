#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///BUG CAUSED BY LEFT (I THINK)
int cards[14];///13 types of cards, the values tell how many of that type remain. use values 1-13, as it makes it simpler for maths/print-out
int hands[4]={1,1,1,1};/// this tells how many hands the player has.
int hand [4][4][15];///the actual hands. 13 stores the amount of cards in the hand, 14 stores the bet on the hand. could do with less
int finance[4];///how much money player has
int firstdeal=0,players, var, var2,a,b,pounds=-100,decks;
char i;
void game()
{
    int left=players;///for deciding if the dealer has to hit
    int grandgame=1;
    while (grandgame==1)
    {

    int first=0;
    srand(time(NULL));
    for(var=0;var<players+1;var++)///card amounts
    {
        hands[var]=1;///reset
        for(var2=3;var2>=0;var2--)
        {
            hand[var][var2][13]=0;///fill hand 13's with 0
        }
    }
    for(var=1;var<players+1;var++)
    {
        if (finance[var]==0)
        {
            continue;///can't play
        }
        printf("Player %d, how much would you like to bet?",var);
        printf(" You have %c%d available.\n",pounds,finance[var]);
        scanf("%d",&hand[var][0][14]);
        while (hand[var][0][14]>finance [var])
        {
            printf("You do not have enough money.You have %c%d available. Please choose again\n",pounds,finance[var]);
            scanf("%d",&hand[var][0][14]);
        }
        finance [var]=finance [var]-hand[var][0][14];
    }
    while(first<2)
    {
        for(var=0;var<players+1;var++)
            {
                if (hand[var][0][14]==0&&var>0)
                {
                    continue;
                }

                for (var2=0;var2<hands[var];var2++)
                {

                    a=hand[var][var2][13];

                    b=rand();
                    hand[var][var2][a]=pick(b);///last needs to be the card in hand being dealt
                    hand [var][var2][13]++;///how many cards in hand

                }

            }
            if (firstdeal==0)
                {
                    firstdeal=1;
                    var++;
                }
                first++;
    }
    int play=1;
    while (play==1)
    {
        printf("\t\tDealer Cards:");
        switch(hand[0][0][0])
        {
        case 1:
            printf("A ");
            break;
        case 11:
            printf("J ");
            break;
        case 12:
            printf("Q ");
            break;
        case 13:
            printf("K ");
            break;
        default:
            printf("%d ",hand[0][0][0]);
        }
        printf(" ?\n\n");
        var=0;
        var2=0;
        if(value()==21)
        {
            print();
            printf("Dealer Blackjack!\n");
            for(var=1;var<players+1;var++)
            {

                if (value()==21)
                {
                    printf("Player %d has a Blackjack- Push.",var);
                    finance[var]=finance[var]+hand[var][0][14];
                    hand[var][0][14]=0;
                }
                else
                {
                    printf("Player %d, you lose your bet.\n",var);
                    hand[var][0][14]=0;

                }
                hand[var][0][13]=0;
            }
            break;
        }
        for(var=1;var<players+1;var++)
        {
            printf("Player %d hand:",var);
            print();

        }
        printf("\n\n");
        for (var=1;var<=players;var++)//choice, not made by dealer !!!!do busts first!!!!
        {
            for (var2=0;var2<hands[var];var2++)
            {
                if (hand[var][var2][14]==0&&var>0)//skip empty hands
                {
                    continue;
                }
                if (finance[var]>=hand[var][var2][14])//only can split if have enough money
                {
                    split();
                }
                    if (value()>21)
                    {
                        printf("player %d has 'bust' and lost his bet\n\n Funds remaining= %c%d\n",var,pounds,finance[var]);
                        hand[var][var2][13]=0;///no cards
                        hand[var][var2][14]=0;
                        left--;
                        continue;
                    }
                    if (value()==21&&hand[var][var2][13]==2)
                    {
                        printf("Player %d, you have a blackjack! ",var);
                        if (hands[var]>1)
                        {
                            printf("with hand %d: ",var2);
                        }
                        else
                        {
                            ("with hand:");
                        }
                        print();
                        finance [var]=finance[var]+hand[var][var2][14];//both bet replaced and added (following) could do in one line using precedence.
                        finance [var]=finance[var]+hand[var][var2][14];
                        hand[var][var2][14]=0;
                        left--;
                        printf("Your total money is now %c%d\n\n",pounds,finance[var]);
                        continue;///move on to next hand.
                    }
                    printf("\nPlayer %d, your cards are:   ",var);
                    print();
                    if (finance [var]>=hand[var][var2][14])
                    {
                        printf("Do you want to 1. Hit, 2.Stand, or 3. Double-down");
                    }
                    else
                    {
                        printf("Do you want to 1. Hit, or 2.Stand");
                    }
                    if(var2>1)
                    {
                        printf(" with hand %d",var2+1);
                    }
                    printf("?\n");
                    scanf("%d",&hand[var][var2][12]);
                    //switch to send off to correct function.
                    switch (hand[var][var2][12])
                        {
                            case 1:
                                b=rand();
                                hit(b);
                                print();
                                var2--;//so can keep hitting, i.e. the for loop. could change previous if to while, but leave for now
                                hand[var][var2][12]=0;//allows to do this move and others
                                break;
                            case 2:
                                break;//for loop moves it on.
                            case 3:
                                if (finance [var]>=hand[var][var2][14])//only allows if enough money
                                {
                                    doubledown();
                                    break;
                                }
                            default:
                                printf("Invalid choice.\n");
                                var2--;//to replay that bit
                            }

                }

            }
            var=0;//set to dealer for functions using these variables
            var2=0;
            printf("Dealer Cards");
            print();
            if (left>0)
            {
                while (value()<17)
                {
                    a=hand[0][0][13];
                    b=rand();
                    hand[0][0][a]=pick(b);
                    hand [0][0][13]++;
                }
            }
            printf("Dealer Cards");
            print();
            printf("Dealer hand Value = %d\n",value());
            int dealertotal=value();

            for (var=1;var<=players;var++)//choice, not made by dealer !!!!do busts first!!!!
            {
                for (var2=0;var2<hands[var];var2++)
                {
                    if (hand[var][var2][14]==0)
                    {
                        continue;//to skip out already bust players.
                    }
                    if (dealertotal<22&&dealertotal>value())
                    {
                        hand[var][var2][14]=0;
                        printf("Bad news, player %d, you lost your bet.\n\n Your total money is now %c%d\n\n",var,pounds,finance[var]);
                    }
                    else if(dealertotal<22&&dealertotal==value())
                    {
                        finance [var]=finance[var]+hand[var][var2][14];
                        hand[var][var2][14]=0;
                        printf("Player %d, it's a push.\n\n Your total money is now %c%d\n\n",var,pounds,finance[var]);
                    }
                    else
                    {
                        finance [var]=finance[var]+hand[var][var2][14];
                        finance [var]=finance[var]+hand[var][var2][14];
                        hand[var][var2][14]=0;
                        printf("Well done player %d! You won this hand!\n\n Your total money is now %c%d\n\n",var,pounds,finance[var]);
                    }
                }
            }

            char carryon='r';
            while (carryon!='y'&&carryon!='n')
            {
                printf("Do you want another game, y/n ?\n");
                scanf(" %c",&carryon);
                if (carryon=='y')
                {
                    left=players;//or else dealer will stop hitting!(also could just reposition original...
                    var2=0;
                    if (decks<3)
                    {
                        for (var2=13;var2>0;var2--)//fill the cards
                        {
                            cards [var2]=decks*4;//amount of cards in pack x packs
                        }
                    }
                    else
                    {
                            for (var=1;var<14;var++)//how many cards left
                        {
                            var2=var2+cards[var];
                        }
                        if (var2<decks*17)//aprox a third of 52
                        {
                            for (var2=13;var2>0;var2--)//fill the cards
                            {
                                cards [var2]=decks*4;//amount of cards in pack x packs
                            }
                        }
                    }
                    play=0;
                }
                else if (carryon=='n')
                {
                    exit(0);
                }
            }


        }
    }
}
int split()
{
    if (hand[var][var2][13]>2)
    {
        return 0;
    }
    srand(time(NULL));
    int a, splits=0, temp=var2;//use var, convert back at end of split();
    char dispose='t';
    while (dispose != 'n')
    {
        if (hand [var][temp][1]!=hand[var][temp][0])
        {///switch off if only same face-cards split
            if (hand [var][temp][1]==10||hand [var][temp][1]==11||hand [var][temp][1]==12||hand [var][temp][1]==13)///value based better?
            {

                if(hand [var][temp][0]!=10&&hand [var][temp][0]!=11&&hand [var][temp][0]!=12&&hand [var][temp][0]!=13)
                {

                    break;

                }
            }
            else
            {
                break;
            }
        }
        if (hands[var]>2)//(max 3 splits for four hands, so if three means three splits
        {
            break;
        }
        printf("Player %d, would you like to split your hand of",var);
        print();
        printf( "(y/n)\n");
        scanf(" %c",&dispose);
        if (dispose=='n')
        {
            return 0;
        }
        if (dispose=='y')
        {
            int e= hands[var];//empty; if one hand ,
            a=rand();
            hand [var][e][0]=hand [var][temp][1];
            hands[var]++;
            hand [var][e][12]=0;//choice
            hand [var][temp][1]=pick(a);//pass random
            a=rand();
            hand [var][e][1]=pick(a);
            hand[var][e][13]=2;

            ///bid increase
            hand [var][e][14]=hand [var][temp][14];
            finance[var]-hand [var][e][14];
            splits++;
            printf("Hands for player %d = %d\n",var,hands[var]);
        }


    }
}

int doubledown()
{
    finance [var]=finance [var]-hand[var][var2][14];
    hand [var][var2][14]=hand [var][var2][14]*2;//add a pick
    srand(time(NULL));//could pass, cant be bothered
    int a=rand();
    int b=hand[var][var2][13];//if 2 card,loc 2
    hand[var][var2][b]=pick(a);
    hand[var][var2][13]++;
    print();

}
int hit(int b)
{
    int a;
    a= hand [var][var2][13];
    hand[var][var2][a]=pick(b);
    hand [var][var2][13]++;
    ///redoes
    hand[var][var2][12]=0;
}

int value()
{
    int valueworkout, totalhandvalue=0,acecount=0,newno;
    for (valueworkout=hand[var][var2][13];valueworkout>0;valueworkout--)//work out which values to pass
    {
        switch(hand[var][var2][valueworkout-1])
        {
            case 1:
                totalhandvalue=totalhandvalue+11;
                acecount++;
                break;
            case 11:
            case 12:
            case 13:
                totalhandvalue=totalhandvalue+10;
                break;
            default:
                newno=hand[var][var2][valueworkout-1];
                totalhandvalue=totalhandvalue+newno;

        }

    }
    while (acecount>0)
    {
        if (totalhandvalue>21)
        {
            totalhandvalue=totalhandvalue-10;
            acecount--;
        }
        else
        {
                return totalhandvalue;

        }
    }
    return totalhandvalue;


}
int print()
{
    int cardstoprint=0;
    char cardoutput;
    for (cardstoprint;cardstoprint<hand[var][var2][13];cardstoprint++)
    {
        switch (hand [var][var2][cardstoprint])//before and after spaces print
        {
            case 1:
                cardoutput= 'A';
                printf("%c ",cardoutput);
                break;
            case 11:
                cardoutput= 'J';
                printf("%c ",cardoutput);
                break;
            case 12:
                cardoutput= 'Q';
                printf("%c ",cardoutput);
                break;
            case 13:
                cardoutput= 'K';
                printf("%c ",cardoutput);
                break;
            default:
                printf("%d ",hand [var][var2][cardstoprint]);
            }

    }
     printf("\n");
}
int pick(a)
{
    int seed=0,randomnumber=0;
    srand(a);
    while(randomnumber==0||cards[randomnumber]==0)
    {
        printf("Picking card...\n");
        randomnumber=rand()%14;
    }
    cards [randomnumber]=cards [randomnumber]-1;
    return randomnumber;


}
int main()
{
    srand(time(NULL));
    printf("Welcome to Blackjack. Please choose the amount of players. (1-3)\n");
    scanf("%d",&players);
    while (players>3)
    {
        printf("Please enter between 1-3.\n");
        scanf("%d",&players);
    }
    printf("Please choose the number of decks you wish to use (1-8)\n");
    scanf("%d",&decks);
    while (decks>8||decks<1)
    {
        printf("Choose between 1-8");
        scanf("%d",&decks);
    }
    for (var2=13;var2>0;var2--)//fill the cards
    {
        cards [var2]=decks*4;//amount of cards in pack x packs
    }
    printf("Please choose your staring budget (1000-10000)\n");
    scanf ("%d",&finance [1]);
    while (finance [1]>10000||finance [1]<1000)
    {
        printf("Number needs to be between 1000 and 10000\n");
        scanf ("%d",&finance [1]);
    }
    for (var=2;var<=players;var++)
    {
        finance[var]=finance[1];
    }
    game();
}
