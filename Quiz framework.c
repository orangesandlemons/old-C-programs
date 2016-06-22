///first question sorting. automatic a b and c additions.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char text[10000];//For a more flexible approach I could make these arrays dynamically at load-time
int answers[300];
int ansamount[300];
int startpoint[300];
int end;
int convert(char a)
{
    switch (a)
    {
    case 'a':
    case 'A':
        return 1;
    case'b':
    case 'B':
        return 2;
    case 'c':
    case 'C':
        return 3;
    case 'd':
    case 'D':
        return 4;
    case 'e':
    case 'E':
        return 5;//up to five choices. This is easy to expand.
    default:
        return 100;//invalid choice,as number will be too high
    }
}
int quiz()//this is the presentation to the end user. the file has already been parsed by load()
{
    int print=0,run=1,asked=1,wrong=0;
    char choice='e';
    while (run==1)
    {
        while (print<startpoint[asked+1])//+1 as using new questions start point as old questions endpoint
        {
            printf("%c",text[print]);
            print++;
        }
        choice=getchar();
        while (convert(choice)>ansamount[asked])
        {
            printf("Invalid choice. Please choose again\n\n");//if multiple chars are fed in, will get multiple prints
            choice=getchar();//gets rid of endline
            while (choice!='\n')// prevents multi-character invalid choices
            {
                choice=getchar();
            }
            choice=getchar();
        }
        if (convert(choice)!=answers[asked])//this means invalid choices also count as wrong.
        {
            printf("You got the answer wrong!\n");
            wrong++;
        }
        choice=getchar();//remove the end-line.
        printf("You have got %d out of %d questions right.\n\n",asked-wrong,asked);
        asked++;
        if (asked==end)
        {
            return 0;//all questions have now been asked
        }
    }

}
int load()
{
    char filename [25];//can do dynamic, just prefer this for ease-of code for now
    int temp=0,position=0,run=1,question=1, answer=1;//starting from question 1, as that's how I feel like doing it.
    FILE *fp;
    printf("Welcome to Console . Please choose the quiz you wish to take.\n\n");
    while (temp<19)
    {
        filename[temp]=getchar();
        if (filename[temp]=='\n')
        {
            filename[temp]='.';//all quizzes have to be saved as .txt
            filename[temp+1]='t';
            filename[temp+2]='x';
            filename[temp+3]='t';
            filename[temp+4]='\0';
            break;
        }
        temp++;
    }

    fp=fopen(filename,"r");
    if (fp==NULL)
    {
        printf("Disaster! The file doesn't open! Please try again, or choose a different file \n");
        return 0;//instead of stderr.
    }
    while (run==1)
    {
        text[position]=getc(fp);
        if (text[position]==EOF)//loading finished
        {
            ansamount[question-1]=answer;//for last question
            text[position]='\n';//to make sure at least one new line for input, regardless of what quiz-writer did.
            end=question;//so that quiz()knows which question is last.
            startpoint[question]=position;//print till beginning of next question in quiz() , then carry on from there
            return 1;//successful load, breaks do-while loop;
        }
        if (text[position]=='\n')
        {
            while (text[position]=='\n')//removes multiple spaces between question/answers, so a bit more user-friendly .
            {
                position++;
                text[position]=getc(fp);
                {
                    if (text[position]=='Q'||text[position]=='q')//could also have chosen a switch
                    {
                        startpoint[question]=position;//as start from after the 'q'
                        ansamount[question-1]=answer;//-1 as answer is currently the total answers to the last question
                        question++;
                        answer=1;//resets for next question
                    }
                    else if (text[position]=='a'||text[position]=='A')
                    {
                        answer++;//so that we know what number the correct answer is
                    }
                    else if (text[position]=='r'||text[position]=='R')
                    {
                        answers [question-1]=answer;//correct answer is saved for question before, as there was++ at Q
                    }

                }

            }
        }
        else
        {
            position++;//if A, Q, or R, it is overwritten by loop, so doesn't appear in the text .
        }
    }
}
int main()
{
    int run=1;
    while (run==1)
    {
        int success=0;
        do
        {
            success=load();
        }
        while (success==0);//do while to keep on re-running load until successful
        if (quiz()==0)
        {
            printf("To exit, enter 'e'. To take another quiz, choose any other letter\n\n");///switch around?
            int temp=getchar();
            while (temp=='\n')
            {
                temp=getchar();
            }
            if (temp=='e'||temp=='E')
            {
                return 0;

            }
            temp=getchar(); //newline clearup for new quiz


        }

    }

}

