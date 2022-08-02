#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define size 100
struct node
{
    int uid;
    int total;
    char name[20];
    char field[20];
   // char status[20];
};
node arr[size];
struct star
{
    int id;
    char name[20];
    star* next;
};
star *newnode,*temp,*head=NULL;
endq()
{
    printf("\n\n\t*****************\t\n\n");

}
void rightch(int a)
{
   // printf("%d",a);
    if(a!=1&&a!=2&&a!=3&&a!=4)
    {
        printf("CHOOSE FROM GIVEN OPTIONS\t");
        scanf("%d",&a);
        rightch(a);
    }
    return;
}
char rightopt(char a)
{
    if(a!='a'&&a!='b'&&a!='c'&&a!='d')
    {
        printf("PLEASE CHOOSE CORRECT OPTION\t");
        scanf("%c",&a);
        a=rightopt(a);
    }
    return a;
}
void qno(int q)
{
    printf("QUESTION NUMBER %d\n",q);
    return;
}
int correctopt(int a)
{
  printf("WELLDONE CORRECT ANSWER\n");
  a++;
  endq();
  return a;
}
void wrongopt()
{
    printf("OOOPS YOU CHOOSE WRONG OPTION\n");
    //endq();      no endq() bcz also have to write correct ans
    return;
}
int parent(int i)
{
    int p=floor((i-1)/2);
    return p;
}
void swap(node *a,node *b)
{
    node t=*a;
    *a=*b;
    *b=t;
}
buildheap(node arr[],int i)    ////again////
{
    int j;
   // int p=parent(i);
    j=i;
    while(j>0)
    {
        if(arr[j].total>arr[parent(j)].total)
        {
            swap(&arr[j],&arr[parent(j)]);
        }
         j=parent(j);

    }


}
int lc(int i,int a)
{
    int l=(2*i)+1;
    if(l>=a)
        return 0;
    return l;
}
int rc(int i,int a)
{
    int r=(2*i)+2;
    if(r>=a)
        return 0;
    return r;
}
int maximum(int l,int r,node arr[])
{
    if(l==0)
        return r;
    if(r==0)
        return l;
    if(arr[l].total>arr[r].total)
        return l;
    else
        return r;
}
void grades(int a)
{
    if(a>8)
        printf("EXCELLENT\n");
    else if(a>5&&a<8)
            printf("GOOD\n");
    else if(a<5)
        printf("WORK HARD\n");
    return;
}
int geta(node arr[])
{
    int a;
    for( a=0;a<size;a++)
    {
        if(arr[a].total==-1)
            break;
    }
    a--;
    return a;
}
heapify(int a,node arr[])
{
    int p,n,m,l,r;
    p=0;
    n=floor(a/2);
    while(p<n)
    {
        l=lc(p,a);
        r=rc(p,a);
        m=maximum(l,r,arr);
        if(arr[p].total<arr[m].total)
        {
            swap(&arr[p],&arr[m]);
            p=m;
        }
        else
            break;;
    }
   // a=(a/2)-1;
   /* while(a>=0)
    {
        m=maximum
        if(arr[a]<arr[m])
            swap(&arr[a],&arr[m]);
    }*/
}

void heapsort(node arr[])
{
    int a;
    a=geta(arr);
    while(a>0)
    {
        swap(&arr[0],&arr[a]);    //descending order
        heapify(a,arr);
        a--;
    }

}
void printheap(node arr[])
{
    heapsort(arr);
    int i=0;
    i=geta(arr);


    /*for(i=0;i<size;i++)
    {
        if(arr[i].total==-1)
        {
            break;
        }
    }
    i--;*/
    printf("UID\tTOTAL\tNAME\tFIELD\n");
    while(i>=0)
    {
        printf("%d\t%d\t%s\t%s\n",arr[i].uid,arr[i].total,arr[i].name,arr[i].field);
        i--;
    }




    return;
}
void maxheap(node arr[])
{
    int a,i,m;
    a=geta(arr);
    m=floor(a/2);   //midpoint
    i=0;
    while(i<=m)
    {
        swap(&arr[i],&arr[a]);
        i++;
        a--;
    }
    // for printing

    /*a=geta(arr);
    for(i=0;i<=a;i++)
    {
        printf("\n%d\t%d\t%s\t%s\n",arr[i].uid,arr[i].total,arr[i].name,arr[i].field);
    }*/
    return;

}
int obtained(char array[])
{
    int o=0,s;
  for(int a=0;a<size;a++)
  {
      if(arr[a].total==-1)
        break;
      else
      {
          s=strcmp(arr[a].field,array);   //string compare function for true its value will be 0
          if(s==0&&arr[a].total==10)
            o++;


      }
  }
  return o;
}
/*node star[4];
void starplayer(int id)
{
    int i=0;
    for(int a=0;a<size;a++)
    {
        if(arr[a].uid==id)
        {
            star[i]=arr[a];
            i++;
            if(i==4)
            {
                break;
            }
        }
    }
    i=0;
        if(star[i].total==10&&star[i+1].total==10&&star[i+2].total==10&&star[i+3].total)
        {
            printf("\n'''STAR PLAYERS'''GOT FULL MARKS IN ALL FOUR QUIZZES\n%d\t%s\n",arr[i].uid,arr[i].name);
        }
    return;

}*/
void statistics(int t,char arr[])
{
    int o;
    float s;
    if(t==0)
    {
        printf("\nNO ONE PLAYED %s QUIZ\n",arr);
        return;
    }
    else
    {
        o=obtained(arr);
        s=(float)o/t*100;  //problem.........1/3
        printf("TOTAL %d USERS PLAYED %s QUIZ AND %f USERS GOT FULL MARKS\n\n ",t,arr,s);


    }
    return;

}


main()
{
    printf("\n\nQUIZ\tGAME\n\n\nIF YOU PLAY ALL FOUR QUIZZES CORRECTLY YOU WILL ECOME STAR PLAYER.........\n\n");
    printf("\n\nINSTRUCTIONS\n1-YOU JUST HAVE TO WRITE THE CORRECT OPTION EITHER a,b,c or d NOT A,B,C,OR D\n\n\n");
    char n[20],opt,gk[18]="general knowledge",isl[9]="islamiat",pak[17]="pakistan studies",eng[8]="English";
    int cont=1,game=1;
    int c,ch,tot,q,id=0;
    int gt=0,it=0,pt=0,et=0;   //totals
    int i=0,starplay=0;
    int g=0,is=0,p=0,e=0;
    for(int a=0;a<size;a++)
    {
        arr[a].total=-1;
    }
 while(game==1)
 {

     printf("1-NEW USER\t2-DASHBOARD\t3-STATISTICS\t4-EXIT\n");
     scanf(" %d",&c);
     switch(c)
     {
     case 1:
     {
                    printf("ENTER NAME:\t");
                    scanf(" %s",&n);               //??????//
                    //gets(n);

                   id++;
                   cont=1;
                   while(cont==1)
                   {

                       printf("CHOOSE YOUR FIELD OF INTEREST\n1-GENERAL KNOWLEDGE\t2-ISLAMIAT\t3-PAKISTAN STUDIES\t4-ENGLISH\n");
                       scanf("%d",&ch);

                      // printf("\n'''WITHOUT KNOWLEDGE ACTION IS USELESS AND KNOWLEDGE  WITHOUT ACTION IS FUTILE'''\n\n ");
                       rightch(ch);
                       switch(ch)
                       {
                       case 1:
                        {
                            if(g==1)
                            {
                                printf("CAN\'T CHOOSE IT AGAIN SORRY..\n");
                                break;
                            }
                            printf("\n'''WITHOUT KNOWLEDGE ACTION IS USELESS AND KNOWLEDGE  WITHOUT ACTION IS FUTILE'''\n\n ");
                            statistics(gt,gk);
                            gt++;
                            tot=0;q=1;
                            qno(q);
                            //printf("QUESTION NUMBER:\t%d",q);
                            printf("Which planet in our solar system is known as the Red Planet?\na-MARS\tb-JUPITER\tc-URANUS\td-EARTH\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='a')
                            {
                                //printf("WELLDONE CORRECT ANSWER\n");
                                //tot++;
                                tot=correctopt(tot);

                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS a-MARS\n");
                                endq();
                              // printf("OOOPS YOU CHOOSE WRONG OPTION\n");
                            }
                            //endq();
                            //printf("\n\n\t*****************\t\n\n");
                            q++;
                            qno(q);
                            printf("WHICH CITY IS FAMOUS FOR TELEPHONE INDUSTRY IN PAKISTAN\na-KARACHI\tb-ISLAMABAD\tc-HARIPUR\td-GUJRAT\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                            {
                               //printf("WELLDONE CORRECT ANSWER\n");
                                //tot++;
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS c-HARIPUR\n");
                                endq();
                                //printf("OOOPS YOU CHOOSE WRONG OPTION\n");
                            }
                            q++;
                            qno(q);
                            printf("How many wings does a mosquito have\na-2\tb-4\tc-6\td-8\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='a')
                            {
                                tot=correctopt(tot);

                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS a-2\n");
                                endq();
                                //printf("OOOPS YOU CHOOSE WRONG OPTION\n");
                            }
                            q++;
                            qno(q);
                            printf("What is the collective name for a group of crows?\na-RAFT\tb-MURDER\tc-WAKE\td-BATTERY\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='b')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS b-MURDER\n");
                                endq();
                            }
                            q++;
                            qno(q);
                            printf("What is the biggest planet in our solar system?\na-EARTH\tb-SATURN\tc-JUPITER\td-MERCURY\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS c-JUPITER\n");
                                endq();
                            }
                            q++; //6
                            qno(q);
                            printf("Which animal is known as the 'Ship of the Desert?\na-CAMEL\tb-COW\tc-ELEPHANT\td-GOAT\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='a')
                            {
                                tot=correctopt(tot);

                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS a-CAMEL\n");
                                endq();
                            }
                            q++;  //7
                            qno(q);
                            printf("How many consonants are there in the English alphabet?\na-4\tb-14\tc-24\td-34\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS c-24\n");
                                endq();
                            }
                            q++;  //8
                            qno(q);
                            printf("What is a baby frog called?\na-CALF\tb-TADPOLE\tc-KID\td-FROG\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='b')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS b-TADPOLE\n");
                                endq();
                            }
                            q++; //9
                            qno(q);
                            printf(" How many ribs do you have?\na-a-4\tb-14\tc-24\td-34\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS c-24\n");
                                endq();
                            }
                            q++;  //10
                            qno(q);
                            printf("who is the president of pakistan?\na-IMRAN KHAN\tb-SAEED GHANI\tc-MAMNOON HUSSAIN\td-ARIF ALVI\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='d')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS d-ARIF ALVI\n");
                                endq();

                            }
                            if(tot==10)
                            {
                                starplay++;
                            }
                            g++;




                            //printf("%d",tot);
                            ////last question//
                            arr[i].total=tot;
                            arr[i].uid=id;
                            strcpy(arr[i].name,n);
                            strcpy(arr[i].field,gk);
                            printf("you got %d out of 10\n",tot);
                            grades(tot);
                            //printf("%d\t%d\t%s\t%s",arr[i].uid,arr[i].total,arr[i].name,arr[i].field);
                            buildheap(arr,i);

                            i++;
                            break;



                        }
                       case 2:
                        {
                            if(is==1)
                            {
                                printf("CAN\'T CHOOSE IT AGAIN SORRY..\n");
                                break;
                            }
                            printf("\n'''THERE IS NO GOD BUT ALLAH AND MUHAMMAD IS THE MASSENGER OF ALLAH'''\n\n");
                            statistics(it,isl);
                            it++;
                            tot=0;q=1;
                            qno(q);
                            printf("Prophet Muhammad (PBUH) belonged to which family?\na-QURAISHI\tb-HASHMI\tc-MAKKI\td-MADNI\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='b')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS b-HASHMI\n");
                                endq();
                            }
                            q++;  //2
                            qno(q);
                            printf("Prophet Muhammad (PBUH) had sons\na-1\tb-2\tc-3\td-4\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS c-3\n");
                                endq();
                            }
                            q++;   //3
                            qno(q);
                            printf("Prophet Muhammad (PBUH) had daughters\na-1\tb-2\tc-3\td-4\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='d')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS d-4\n");
                                endq();
                            }
                            q++; //4
                            qno(q);
                            printf("What companion of Prophet (PBUH) was awarded with the title of 'The lion of Allah'?\na-HAZRAT ABU BAKAR\tb-HAZRAT UMER\tc-HAZRAT USMAN\td-HAZRAT ALI\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='d')
                            {
                                tot=correctopt(tot);

                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS d-HAZRAT ALI\n");
                                endq();

                            }


                            q++; //5
                            qno(q);
                            printf("who added 2nd Azan for friday prayers ?\na-HAZRAT ABU BAKAR\tb-HAZRAT UMER\tc-HAZRAT USMAN\td-HAZRAT ALI\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                            {
                                tot=correctopt(tot);
                            }
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS c-HAZRAT USMAN\n");
                                endq();
                            }

                            q++;  //6
                            qno(q);
                            printf("Nation of hood destroyed by \na-THROUGH FLOOD\tb-AZAAB OF MOSQUITOES\tc-A DREADFUL EARTHQUAKE\td-CONTINUOUS RAIN AND STORM\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='d')
                                tot=correctopt(tot);
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS d-CONTINUOUS RAIN AND STORM\n");
                                endq();
                            }

                            q++;  //7
                            qno(q);
                            printf("What is the literal meaning of islam is \na-TO OBEY\tb-TO BOW DOWN THE NECK\tc-TO HAVE SAFTY\td-ALL OF THESE\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='d')
                                tot=correctopt(tot);
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS d-ALL OF THESE\n");
                                endq();
                            }

                            q++;  //8
                            qno(q);
                            printf("which Prophet died while standing with the support of a stick?\na-HAZRAT MUSA A.S\tb-HAZRAT ESSA A.A\tc-HAZRAT SULEMAN A.S\td-HAZRAT HAROON A.S\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                                tot=correctopt(tot);
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS c-HAZRAT SULEMAN A.S\n");
                                endq();
                            }

                            q++; //9
                            qno(q);
                            printf("How many surah start with name of Prophets?\na-3\tb-6\tc-9\td-12\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='b')
                                tot=correctopt(tot);
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS b-6\n");
                                endq();
                            }

                            q++;  //10
                            qno(q);
                            printf("Which of the following was the Teacher of Hazrat Musa (AS) ?\na-HAZRAT IBRAHIM A.S\tb-HAZRAT ISHAQ A.S\tc-HAZRAT KHIZAR A.S\td-HAZRAT YUSAF A.S\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                                tot=correctopt(tot);
                            else
                            {
                                wrongopt();
                                printf("CORRECT ANSWER IS c-HAZRAT KHIZAR A.S\n");
                                endq();
                            }
                            if(tot==10)
                            {
                                starplay++;
                            }
                            is++;






                            arr[i].total=tot;
                            arr[i].uid=id;
                            strcpy(arr[i].name,n);
                            strcpy(arr[i].field,isl);
                            printf("you got %d out of 10\n",tot);
                            grades(tot);
                            //printf("%d\t%d\t%s\t%s",arr[i].uid,arr[i].total,arr[i].name,arr[i].field);
                            buildheap(arr,i);

                            i++;
                            break;

                        }
                       case 3:
                        {
                            if(p==1)
                            {
                                printf("CAN\'T CHOOOSE IT AGAIN SORRY..\n");
                                break;
                            }
                            printf("\n'''THERE IS NO POWER ON EARTH THAT CAN UNDO PAKISTAN'''\t'QUAID-E-AZAM'\n\n");
                            statistics(pt,pak);
                            pt++;
                          tot=0;q=1;
                          qno(q);
                          printf("After how many years did Pakistan got its first constitution?\na-5\tb-7\tc-9\td-11\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='c')
                                tot=correctopt(tot);
                          else
                          {
                              wrongopt();
                              printf("CORRECT ANSWER IS c-9\n");
                              endq();
                          }

                          q++; //2
                          qno(q);
                          printf("Who was Mohammad Ali Bogra?\na-FOREIGN MINISTER\tb-PRIME MINISTER\tc-LAW MINISTER\td-PARLIAMENT MINISTER\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='b')
                            tot=correctopt(tot);
                          else

                            {
                              wrongopt();
                              printf("CORRECT ANSWER IS b-PRIME MINISTER\n");
                              endq();
                          }
                          q++;  //3
                          qno(q);
                          printf("What age was prescribed for President in 1956 constitution?\na-40\tb-50\tc-60\td-30\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);

                          if(opt=='a')
                            tot=correctopt(tot);
                          else
                         {
                              wrongopt();
                              printf("CORRECT ANSWER IS a-40\n");
                              endq();
                          }


                          q++; //4
                          qno(q);
                          printf("Who abrogated 1956 constitution?\na-YAHYA KHAN\tb-AYUB KHAN\tc-ISKANDAR MIRZA\td-ZIA UL HAQQ\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='c')
                            tot=correctopt(tot);
                          else
                        {
                              wrongopt();
                              printf("CORRECT ANSWER IS c-ISKANDAR MIRZA\n");
                              endq();
                          }
                          q++;  //5
                          qno(q);
                          printf("Pakistan\'s National Flag was prepared by?\na-ABDUR REHMAN CHUGTAI\tb-LIAQUAT ALI KHAN\tc-CHAUDHARY REHMAT ALI\td-AMEER-UD-DIN QADWAI\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='d')
                            tot=correctopt(tot);
                          else
                            {
                              wrongopt();
                              printf("CORRECT ANSWER IS d-AMEER-UD-DIN QUDWAI\n");
                              endq();
                          }
                          q++; //6
                          qno(q);
                          printf("Which is the national flower of Pakistan ?\na-LILLY\tb-ROSE\tc-JASMINE\td-TULIP\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='c')
                            tot=correctopt(tot);
                          else
                            {
                              wrongopt();
                              printf("CORRECT ANSWER IS c-JASMINE\n");
                              endq();
                          }
                          q++;  //7
                          qno(q);
                          printf("Which is the national bird of Pakistan ?\na-PARROT\tb-MARKHOR\tc-CHAKOR\td-PIGEON\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='c')
                            tot=correctopt(tot);
                          else
                            {
                              wrongopt();
                              printf("CORRECT ANSWER IS c-CHAKOR\n");
                              endq();
                          }
                          q++;  //8
                          qno(q);
                          printf("Pakistan\’s standard time was suggested by\na-LIAQUAT ALI\tb-CHAUDHARY REHMAT ALI\tc-MAULANA MAZHAR UD DIN\td-PROFESSOR MUHAMMAD ANWAR\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='d')
                            tot=correctopt(tot);
                          else
                            {
                              wrongopt();
                              printf("CORRECT ANSWER IS d-PROFESSOR MUHAMMAD ANWAR\n");
                              endq();
                          }
                          q++; //9
                          qno(q);
                          printf("Where the biggest Salt Mine located in Pakistan ?\na-JEHLUM\tb-SAWAT\tc-MANGORA\td-NONE OF THESE\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='a')
                            tot=correctopt(tot);
                          else
                            {
                              wrongopt();
                              printf("CORRECT ANSWER IS a-JEHLUM\n");
                              endq();
                          }
                          q++;  //10
                          qno(q);
                          printf("Pakistan Steel Mills is located in?\na-KARACHI\tb-GAWADAR\tc-LAHORE\td-NONE OF THEM\n");
                          scanf(" %c",&opt);
                          opt=rightopt(opt);
                          if(opt=='a')
                            tot=correctopt(tot);
                          else
                            {
                              wrongopt();
                              printf("CORRECT ANSWER IS a-KARACHI\n");
                              endq();
                          }
                          if(tot==10)
                          {
                              starplay++;
                          }
                          p++;


                            arr[i].total=tot;
                            arr[i].uid=id;
                            strcpy(arr[i].name,n);
                            strcpy(arr[i].field,pak);
                            printf("you got %d out of 10\n",tot);
                            grades(tot);
                           // printf("%d\t%d\t%s\t%s",arr[i].uid,arr[i].total,arr[i].name,arr[i].field);
                            buildheap(arr,i);

                            i++;
                            break;



                        }
                       case 4:
                        {
                            if(e==1)
                            {
                              printf("CAN\'T CHOOSE IT AGAIN SORRY..\n");
                                break;
                            }
                            printf("\n'''THE ENGLISH LANGUAGE IS A WORK IN PROGRESS.HAVE FUN WITH IT'''\n\n");
                            statistics(et,eng);
                            et++;
                            tot=0;q=1;
                            qno(q);
                            printf("How heavy is a liter of water?\na-It's one kilogram heavy\tb-Is it one kilogram.\tc-It weighs one kilogram\td-Is about a kilogram\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                            {
                                tot=correctopt(tot);

                            }
                            else

                               {
                              wrongopt();
                              printf("CORRECT ANSWER IS c-It weighs one kilogram\n");
                              endq();
                          }
                            q++; //2
                            qno(q);
                            printf("When you are parted from your partner, you _____ to appreciate each other more.\na-FIND\tb-MAY\tc-BECOME\td-GROW\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='d')
                                tot=correctopt(tot);
                            else
                                {
                              wrongopt();
                              printf("CORRECT ANSWER IS d-GROW\n");
                              endq();
                          }
                            q++;  //3
                            qno(q);
                            printf("What is the meaning of 'hit the nail on the head'?\na-MEMORIZE IT\tb-ACCEPT THE CONSEQUENCES\tc-EXPERIENCE\td-ABSOLUTELY RIGHT\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='d')
                                tot=correctopt(tot);
                            else
                               {
                              wrongopt();
                              printf("CORRECT ANSWER IS d-ABSOLUTELY RIGHT\n");
                              endq();
                          }

                            q++;  //4
                            qno(q);
                            printf("antonyom of 'UNDERHEAD'\na-HIDDEN\tb-EXPOSED\tc-OBSCURE\td-SURREPTITIOUS\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='b')
                                tot=correctopt(tot);
                            else
                                {
                              wrongopt();
                              printf("CORRECT ANSWER IS b-EXPOSED\n");
                              endq();
                          }

                            q++; //5
                            qno(q);
                            printf("Synonym of 'MASSIVE'\na-HUGE\tb-LITTLE\tc-LUMP SUM\td-STRONG\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='a')
                                tot=correctopt(tot);
                            else
                                {
                              wrongopt();
                              printf("CORRECT ANSWER IS a-HUGE\n");
                              endq();
                          }
                            q++;  //6
                            //printf("%d\n",tot);
                            qno(q);
                            printf("a hater of knowledge and learning is\na-BIBLIOPHILE\tb-PHILOLOGIST\tc-MISOLOGIST\td-MISOGYNIST\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                                tot=correctopt(tot);
                            else
                                {
                              wrongopt();
                              printf("CORRECT ANSWER IS c-MISOLOGIST\n");
                              endq();
                          }
                            q++;  //7
                            qno(q);
                            printf("person who does not believe in existence of GOD\na-THEIST\tb-HERETIC\tc-ATHEIST\td-FANATIC\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='c')
                                tot=correctopt(tot);
                            else
                                {
                              wrongopt();
                              printf("CORRECT ANSWER IS c-ATHEIST\n");
                              endq();
                          }
                            q++;  //8
                            qno(q);
                            printf("CORRECT THE SENTENCE\nthe small child does whatever his father 'WAS DONE'\na-DOES\tb-DID\tc-HAS DONE\td-HAD DONE\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='a')
                                tot=correctopt(tot);
                            else
                                {
                              wrongopt();
                              printf("CORRECT ANSWER IS a-DOES\n");
                              endq();
                          }
                            //printf("%d\n",tot);
                            q++;  //9
                            qno(q);
                            printf("to keep one's temper means\na-TO BECOME HUNGRY\tb-TO BE IN GOOD MOOD\tc-TO BE ALOOF FROM\td-NONE OF THESE\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='b')
                                tot=correctopt(tot);
                            else
                                {
                              wrongopt();
                              printf("CORRECT ANSWER IS b-TO BE IN GOOD MOOD\n");
                              endq();
                          }
                            q++; //10
                            qno(q);
                            printf("fill in the given blank\nif _______ I would not lose temper\na-I WAS YOU\tb-I AM NOT YOU\tc-I AM YOU\td-I WERE YOU\n");
                            scanf(" %c",&opt);
                            opt=rightopt(opt);
                            if(opt=='d')
                                tot=correctopt(tot);
                            else
                                {
                              wrongopt();
                              printf("CORRECT ANSWER IS d-I WERE YOU\n");
                              endq();
                          }
                          if(tot==10)
                          {
                              starplay++;
                          }
                          e++;
                               //check it???10/9

                            arr[i].total=tot;
                            arr[i].uid=id;
                            strcpy(arr[i].name,n);
                            strcpy(arr[i].field,eng);
                            printf("you got %d out of 10\n",tot);
                            grades(tot);

                           // printf("%d\t%d\t%s\t%s",arr[i].uid,arr[i].total,arr[i].name,arr[i].field);
                            buildheap(arr,i);

                            i++;
                            break;
                        }
                        break;
                       }
                       if(starplay==4)    //check it .......<..
                       {

                           newnode=(star*)malloc(sizeof(star));
                           newnode->id=id;
                           strcpy(newnode->name,n);
                           newnode->next=NULL;
                           if(head==NULL)
                           {
                               head=newnode;
                               temp=head;
                           }
                           else
                           {
                              temp->next=newnode;
                              temp=newnode;
                           }


                            break;
                       }

                       printf("DO YOU WANT TO CONTINUE THIS GAME\t");
                       scanf("%d",&cont);

                   }
                   g=e=is=p=starplay=0;    //now new player will play

       break;
     }
    case 2:
     {
         temp=head;
         if(temp==NULL)
         {
             printf("NO STAR PLAYER.........\n\n");

         }
         else
         {
             printf("STAR PLAYERS\n ");   //for star players
             while(temp!=NULL)
            {
             printf("%d\t%s\n",temp->id,temp->name);
             if(temp->next==NULL)
                break;
             temp=temp->next;
            }

         }


     /* for(int a=1;a<=id;a++)
      {
          starplayer(a);

     }*/
     printheap(arr);
    // printf("fine");

      maxheap(arr);
      break;
     }

    case 4:
     {
        game=0;
        break;
     }
    case 3:
        {

            statistics(gt,gk);
            statistics(it,isl);
            statistics(pt,pak);
            statistics(et,eng);
            break;
        }
     break;
     }



}

}

