///doesn't support multi-objects allowing for an option. Have to add an 'or' function- perhaps a///list of items.///choices lead on diff places if diff objects- can be done.
///This version allows for objects. I  may add battles, inventory limits etc.
///copy in load from other objects, design better read system in play.
#include<stdio.h>///Currently need to minus 1 from selection choice in object assigning
#include<stdlib.h>
int choicestart[1000];///Gives the array location in 'text' can make dynamic via placing it in main.
int choiceend[1000];///used for calculating end of text in 'play' using this method for now; could also do a play-time method.
int choiceamount[1000];
int choicedestination[1000][3];
char text[10000];
int objects[1000];//use a character search system?//object formatt= /o-choice-type-destinatin-o-choice etc./
obconvert(char*a,int position)
{
    int readtemp,sendto=0;
    while(a[position]!='o'&&a[position]!='O'&&a[position]!='/')///does this work need to add g in, or rather new func
    {
        readtemp=a[position];
        switch (readtemp)
        {
            case '0':
                if (sendto==0)///errorhandleing
                {
                    sendto=0;
                }
                else
                {
                    sendto*=10;
                }
                break;
            case '1':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=1;
                break;
            case '2':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=2;
                break;
            case '3':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=3;
                break;
            case '4':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=4;
                break;
            case '5':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=5;
                break;
            case '6':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=6;
                break;
            case '7':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=7;
                break;
            case '8':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=8;
                break;
            case '9':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=9;
                break;
                default:
                    break;
                    //temp, until work out the backwards one. printf("File not formatted correctly please choose another %c \n",readtemp);
                    //return -1;///add a return minus 1 then return 0;

                }
                position++;
            }
            return sendto;



}
revobconvert(char*a,int position)
{
    int readtemp,sendto=0;
    while (a[position]!='o'&&a[position]!='O')
    {
        position--;
    }
    position++;
    while(a[position]!='l'&&a[position]!='g'&&a[position]!='G'&&a[position]!='/'&&a[position]!='L'&&a[position]!='u'&&a[position]!='U')///does this work need to add g in, or rather new func
    {
        readtemp=a[position];
        switch (readtemp)
        {
            case '0':
                if (sendto==0)///errorhandleing
                {
                    sendto=0;
                }
                else
                {
                    sendto*=10;
                }
                break;
            case '1':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=1;
                break;
            case '2':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=2;
                break;
            case '3':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=3;
                break;
            case '4':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=4;
                break;
            case '5':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=5;
                break;
            case '6':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=6;
                break;
            case '7':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=7;
                break;
            case '8':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=8;
                break;
            case '9':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=9;
                break;
                default:
                    break;
                    //temp, until work out the backwards one. printf("File not formatted correctly please choose another %c \n",readtemp);
                    //return -1;///add a return minus 1 then return 0;

                }
                position++;///compact by an if and passing extra value.
            }
            return sendto;



}
play()
{
    int a;
    for (a=0;a<100;a++)
    {
        objects[a]=0;
    }
    char objectcommand[100];///plenty of space.
    int playing=1,print=0,choiceupto=0,selection,objectcount=0;
    printf("\n");
    while (print<=choiceend[0])///make sure right. also make sure all my greaters etc are right
    {
        if (text [print]=='/')
        {
            if (text [print+1]=='O')
            {
                print+=1;
                while (text[print]!='/')
                {
                    objectcommand[objectcount]=text [print];
                    print++;
                    objectcount++;
                }
                print++;
            }
        }
        printf("%c",text[print]);
        print++;
    }
    scanf("%d",&selection);///make loop, maybe getc? long term word int?
    while (selection>choiceamount[choiceupto])
    {
        printf("Invalid entry. Please choose again\n\n");
        scanf("%d",selection);
    }
    if (objectcount>0)//don't know if really need this, as if 0 the for loop will stop straight away
    {
        ///check that valid choice via u,check, then apply gets and losses ///use format choice, type,object?HERE!
        for (a=0;a<=objectcount;a++)
        {
            if (objectcommand[a]=='u')
            {
                ///here turn it into what the number is, and if not got object and selection matches, invalid choice. and loop
                if (revobconvert(objectcommand,a-1)==selection&&objects[obconvert(objectcommand,a+1)]<1)///the minus one has to be adapted by working backwards!
                {
                    printf("You do not have the needed object! Please choose again\n\n");
                    scanf("%d",&selection);///add a while outside the for, so whole thing checked each selection.
                    a=-1;///could also do =0 and continue


                }
            }
        }
        for (a=0;a<=objectcount;a++)
        {
            if (objectcommand[a]=='l'||objectcommand[a]=='L')
            {
                if(revobconvert(objectcommand,a-1)==selection)
                {
                    if (objects[obconvert(objectcommand,a+1)]>0)
                    {
                        objects[obconvert(objectcommand,a+1)]--;
                    }
                }
            }
        }
        for (a=0;a<=objectcount;a++)
        {
            if (objectcommand[a]=='G'||objectcommand[a]=='g')///and selection!ADD BACKWARDS CAPABILITY!
            {
            revobconvert(objectcommand,a-1);

                    if(revobconvert(objectcommand,a-1)==selection)
                    {
                        objects[obconvert(objectcommand,a+1)]++;
                    }
        }
     }///no support of inventory/ type limiting. can all be added later.
    }
    objectcount=0;
    choiceupto=choicedestination[choiceupto][selection-1];///why. also choice up to starts at 0. maybe shift for ease of composition.
    while(playing==1)
    {
        print=choicestart[choiceupto];///check!
        while (print<=choiceend[choiceupto])//work out why. think it is because of teh choice businesss
        {
            if (text[print]=='/')///does this slow down at all?
            {
                if (text [print+1]=='E')
                {
                    printf("\n\n            ***Thank You for using the TAF***\n\n");
                    return 0;
                }
                if (text [print+1]=='O')
                {
                    print+=1;
                    while (text[print]!='/')
                    {
                        objectcommand[objectcount]=text[print];
                        print++;
                        objectcount++;
                    }
                    objectcommand[objectcount]=text[print];
                    print++;

                }
            }
            printf("%c",text[print]);
            print++;
        }
        scanf("%d",&selection);///make loop, maybe getc? long term word int?
        while (selection>choiceamount[choiceupto])///does this work with the choiceshift?
        {
            printf("Invalid entry. Please choose again\n\n");
            scanf("%d",&selection);
        }
        if (objectcount>0)//don't know if really need this, as if 0 the for loop will stop straight away
        {
        ///check that valid choice via u,check, then apply gets and losses ///use format choice, type,object?HERE!
        for (a=0;a<=objectcount;a++)
        {
            if (objectcommand[a]=='u')
            {
                ///here turn it into what the number is, and if not got object and selection matches, invalid choice. and loop
                if (revobconvert(objectcommand,a-1)==selection&&objects[obconvert(objectcommand,a+1)]<1)///the minus one has to be adapted by working backwards!
                {
                    printf("You don't have the needed object!. Please choose again\n\n");
                    scanf("%d",&selection);///add a while outside the for, so whole thing checked each selection.
                    a=-1;///could also do =0 and continue


                }
            }
        }
        for (a=0;a<=objectcount;a++)
        {
            if (objectcommand[a]=='l'||objectcommand[a]=='L')
            {
                if(revobconvert(objectcommand,a-1)==selection)
                {
                    if (objects[obconvert(objectcommand,a+1)]>0)
                    {
                        objects[revobconvert(objectcommand,a+1)]--;
                    }
                }
            }
        }
        for (a=0;a<=objectcount;a++)
        {
            if (objectcommand[a]=='G'||objectcommand[a]=='g')///and selection!
            {
                    if(revobconvert(objectcommand,a-1)==selection)
                    {
                        objects[obconvert(objectcommand,a+1)]++;
                    }
        }
     }///no support of inventory/ type limiting. can all be added later.
    }
    objectcount=0;
    choiceupto=choicedestination[choiceupto][selection-1];

    }
}
convert(FILE*fp)
{
    char readtemp='e';
    int sendto=0;
    while (readtemp!='/')
    {
        readtemp=getc(fp);
        if (readtemp=='/')///was missing
        {
            break;
        }
        switch (readtemp)
        {
            case '0':
                if (sendto==0)///errorhandleing
                {
                    sendto=0;
                }
                else
                {
                    sendto*=10;
                }
                break;
            case '1':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=1;
                break;
            case '2':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=2;
                break;
            case '3':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=3;
                break;
            case '4':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=4;
                break;
            case '5':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=5;
                break;
            case '6':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=6;
                break;
            case '7':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=7;
                break;
            case '8':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=8;
                break;
            case '9':
                if (sendto>0)
                {
                    sendto*=10;
                }
                sendto+=9;
                break;
                default:
                    printf("File not formatted correctly please choose another\n");
                    return 0;

                }
            }
            return sendto;
}

load()
{
 char filename [20];///can do dynamic, just prefer this for ease-of code for now
    char *start;
    char readtemp;
    int loading=1,place=0,choice=0,temp=0,sendto=0,changechoice=0;
    FILE *fp;
    printf("Welcome to the text adventure framework. Please load an adventure or savefile.\n\n");///eventually, add list
    while (temp<19)///why stop at new line?
    {
        filename[temp]=getchar();
        if (filename[temp]=='\n')///does this work>
        {
            filename[temp]='\0';
            break;
        }
        temp++;
    }

    fp=fopen(filename,"r");///alternative using %s? check st.ov. again. Add error check
    if (fp==NULL)
    {
        printf("Disaster! The file doesn't open! Please try again, or choose a different file \n");
        perror("Error: ");
        return 0;
    }
    while (loading==1)///EOF?
    {
        text[place]=getc(fp);
        if (text[place]==EOF)
        {
            fclose(fp);
            return 1;///too short files will 'load'
        }
        if (text[place]=='/')//fits nicely with.
        {
            text[place]=getc(fp);
            if (text[place]!='/')///i.e. no escape from it being a command
            {
                /*text[place]=getc(fp);*///deadly!
                switch(text[place])
                {
                case 'o':
                case 'O':
                    text[place]='/';///so still there for play why doesn't save?
                    place++;
                    text[place]='O';///ditto
                    while (text [place]!='/')///e is used to symbolise the end of an object system
                    {
                        place++;
                        text[place]=getc(fp);///this will get to e, then stop, and then will get place added later as not changed
                        ///changechoice;
                    }
                    place++;
                    text[place]=getc(fp);///does this sort prob?
                    break;
                case 'E':
                case 'e':
                    text[place]='/';
                    place++;
                    text[place]='E';
                    place++;
                    changechoice=1;
                    break;
                case 'c':
                case 'C':
                    changechoice=1;///knows end of chapter (choices always at end)
                    text[place]=getc(fp);
                    switch (text[place])
                    {
                    case 'b':
                    case 'B':
                        choiceamount[choice]=2;
                        for (temp=0;temp<2;temp++)///make sure we keep an eye on temp so don't reuse it!
                        {
                            sendto=convert(fp);///can send to 0! so maybe change! debug
                            if (sendto==0)
                            {
                                printf("Error with file");
                                return 0;
                            }

                            choicedestination[choice][temp]=sendto;///decide whether this is choice or choice+1

                        }

                        break;


                    case 'c':
                    case 'C':
                        choiceamount[choice]=3;
                        for (temp=0;temp<3;temp++)
                        {
                            sendto=convert(fp);
                             if (sendto==0)
                            {
                                return 0;
                            }
                            choicedestination[choice][temp]=sendto;///decide whether this is choice or choice+1

                        }
                        break;

                    default:///debuging here
                        printf("Error in file. Please try a different one\n\n");
                        return 0;
                    }
                }
            if (changechoice==1)
            {
                choiceend[choice]=place-1;///skip out for object. use break.
                choice++;
                choicestart[choice]=place;
                place--;
                changechoice=0;
            }


        }

        else
        {
            place++;
            text[place]='/';///literal for play
        }
    }
    place++;

    }
}
main()
{
    int run=1;
    while (run==1)
    {
        int success=0;
        do
        {
            success=load();
        }
        while (success==0);
        if (play()==0)
        {

            printf("To exit, enter 'e'. continue, press any other letter\n\n");
            int temp=getchar(); //both here
            temp=getchar();
            if (temp=='e'||temp=='E')///has to be here, or else eaten. change on other
            {
                return 0;

            }
            temp=getchar();///three seems to work! use a while next time.


        }

    }
    printf ("Thank you for using the text adventure framework.\n");

}
