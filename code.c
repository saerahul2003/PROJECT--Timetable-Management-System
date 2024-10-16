#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
typedef struct
{   char name[100];
    char coursecode[100];
    char sec[2];
    char coursetype[15];
    char dep[10];
    char facid[5];
    int subid;
}details;
details data[8];
void numtt(int tt[5][7]) //function to print the integer value timetable.
{   for(int i=0;i<5;i++)
    {   for(int j=0;j<7;j++)
        {
            printf("%d\t",tt[i][j]);
        }
        printf("\n");
    }
}
void maintt(int tt[5][7])  //function to print the main timetable.
{   char realtt[5][7];
    int i,j;
    char days[][25]={"MON","TUES","WED","THUR","FRI"};
    char time[][25]={"DAY","8.15-9.15","9.15-10.15","10.30-11.30","11.30-12.30","12.30-1.30","1.30-2.30","2.30-3.30"};
    for(int i=0;i<8;i++)
       printf("%s%s",time[i],i==0?"\t\t":"\t");
    printf("\n");
    for(i=0;i<5;i++)
    {   printf("%s\t\t",days[i]);
        for(j=0;j<7;j++)
        {
            switch(tt[i][j])
            {
                case 1:
                    printf("MAT\t\t");
                    break;
                case 2:
                    printf("EEE\t\t");
                    break;
                case 3:
                    printf("CS\t\t");
                    break;
                case 5:
                    printf("CSL\t\t");
                    break;
                case 4:
                    printf("HSE\t\t");
                    break;
                case 6:
                    printf("EVS\t\t");
                    break;
                case 7:
                    printf("DS\t\t");
                    break;
                case 8:
                    printf("DTL\t\t");
                    break;
                case 9:
                    printf("LUNCH\t\t");
                    break;
                case 10:
                    printf("LIBRARY\t\t");
                    break;
                case 11:
                    printf("MENTOR\t\t");
                    break;
                case 12:
                    printf("SPORTS\t\t");
                    break;
            }

        }
        printf("\n");
    }
    printf("\n");
}
void staff(int subjectno){   //FUNCTION THAT RETRIEVES FACULTY DETAILS FROM THE FILE.
    for(int i=0;i<8;i++){
        if((data[i].subid==subjectno)){
            printf("%s\t\t",data[i].facid);
            break;
        }else{
            continue;
        }
    }
}
void stafftt(int tt[5][7])  //function to print the staff timetable.
{   
    
    int i,j;
    char days[][25]={"MON","TUES","WED","THUR","FRI"};
    char time[][25]={"DAY","8.15-9.15","9.15-10.15","10.30-11.30","11.30-12.30","12.30-1.30","1.30-2.30","2.30-3.30"};
    for(int i=0;i<8;i++)
       printf("%s%s",time[i],i==0?"\t\t":"\t");
    printf("\n");
    for(i=0;i<5;i++)
    {   printf("%s\t\t",days[i]);
        for(j=0;j<7;j++)
        {
            switch(tt[i][j])
            {
                case 1:
                    staff(1);
                    break;
                case 2:
                    staff(2);
                    break;
                case 3:
                    staff(3);
                    break;
                case 4:
                    staff(4);
                    break;
                case 5:
                    staff(5);
                    break;
                case 6:
                    staff(6);
                    break;
                case 7:
                    staff(7);
                    break;
                case 8:
                    staff(8);
                    break;
                case 9:
                    printf("LUNCH\t\t");
                    break;
                case 10:
                    printf("LIBRARY\t\t");
                    break;
                case 11:
                    printf("MENTOR\t\t");
                    break;
                case 12:
                    printf("SPORTS\t\t");
                    break;
            }

        }
        printf("\n");
    }
    printf("\n");
}
void main(){
    char class;
    int i,j,k;    //i-day,j-hour
    int A[5][7];
    FILE *fp;
    printf("Department of computer engineering\n");
    printf("Semester 2\n");
    printf("Enter the Section[A or B]\n");
    scanf("%c",&class);
    if(toupper(class)=='A'){
        fp=fopen("inputa.txt","r");
    }else{
        fp=fopen("inputb.txt","r");
    }
   for(i=0;i<8;i++){       //8 denotes the number of faculty
        fscanf(fp,"%s %s %s %s %s %d %s",&data[i].name,&data[i].coursecode,&data[i].sec,&data[i].coursetype,&data[i].dep,&data[i].subid,&data[i].facid);
        //printf("%s:%s\n",data[i].name,data[i].facid);
    }
    fclose(fp);  
    
    int nullallot(int tt[5][7])  //functio to allot 0's to all the values in the tt matrix
    {   for(i=0;i<5;i++)
        {   for(int j=0;j<7;j++)
            {   
                tt[i][j]=0;
            }
        }
    }
    int lunchallot(int tt[5][7])  //funtion to assign lunch to the 4th hour everyday
    {   for(i=0;i<5;i++)
        {
            tt[i][3]=9;
        }
    }
    nullallot(A);
    lunchallot(A);   
    for(j=0;j<3;j++)
    {                           //j denotes the hour and monday morning three hours is assigned to be c lab manually
        A[0][j]=5;
    }
    for(j=4;j<7;j++)
    {                           //j denotes the hour and wed aftnoon three hours is assigned to be eee lab manually.
        A[2][j]=8;
    }
    int rn;        //randomnumber
    srand(time(NULL));
    char diffstaff_subarrayy[4][15]={"UMA2276","UCS2201","UHS2242","UCS2202"};
    int diffstaff_subid[6]={1,3,4,7};
    int diffstaff_maxhr[6]={5,3,3,3};
    char samestaff_subarray[2][10]={"UEE2276","ACY2276"};
    int samestaff_subid[2]={2,6};
    int samestaff_maxhr[2]={3,3};
    char addcls_subarray[3][10]={"library","mentor","sports"};
    int addcls_subid[3]={10,11,12};
    int addcls_maxhr[3]={2,1,1};
    int tid;
    int tmhr;
    
     
    for(k=0;k<2;k++)    //loop for allocating subjects with same staff
    {                            //subid-k which denotes the subject 
     
        tid=samestaff_subid[k];
        tmhr=samestaff_maxhr[k];
        
        int hr=0;
        for(i=0;i<5;i++){   //i denotes the day
            while(hr!=tmhr){
                rn = rand() % 7;
               // printf("%d\n", randomnumber);
                if(A[i][rn]==0){
                    A[i][rn]=tid;
                    //printf("tta[%d][%d]=%d\n",i,randomnumber,tempsubid);
                    hr++;
                    //printf("Yes\n");
                    break;
                }
                else{
                    //printf("No\n");
                    continue;
                }
            }
            
        }
    }
    
    int diffac(int tt[5][7])    //function for allocating subjects with different staff
    {
        for(k=0;k<4;k++){       //subid-k which denotes the subject 
           
            tid=diffstaff_subid[k];
            tmhr=diffstaff_maxhr[k];
            
            int hr=0;
            for(i=0;i<5;i++){   
                while(hr!=tmhr){
                    int flag = 0;
                    for(int nor=0;nor<25;nor++)  //nor-number of random numbers generated
                    {
                        rn = rand() % 7;
                        //printf("%d\n", randomnumber);
                        if(tt[i][rn]==0){
                            tt[i][rn]=tid;
                            //printf("tta[%d][%d]=%d\n",i,randomnumber,tempsubid);
                            flag = 1 ;
                            //printf("Yes\n");
                            break;
                        }
                        else{
                            //printf("No\n");
                            continue;
                        }
                    }
                    if(flag == 1)
                    {
                        hr++;
                        break;
                    }
                    else
                    {
                        break;
                    }

                }
            }
        }
    }
    diffac(A);
    
    int addsub(int tt[5][7]) //function for allocating additional classes
    {
        for(int k=0;k<3;k++){       //subid-k which denotes the subject 
            
            tid=addcls_subid[k];
            tmhr=addcls_maxhr[k];
            
            int hr=0;
            for(int i=0;i<5;i++){   //i denotes the day
                while(hr!=tmhr){
                    int flag = 0;
                    for(int nor=0;nor<50;nor++)
                    {
                        rn = rand() % 7;
                        //printf("%d\n", randomnumber);
                        if(tt[i][rn]==0){
                            tt[i][rn]=tid;
                            //printf("tta[%d][%d]=%d\n",i,randomnumber,tempsubid);
                            flag = 1 ;
                            
                            //printf("Yes\n");
                            break;
                        }
                        else{
                            //printf("No\n");
                            continue;
                        }
                    }
                    if(flag == 1)
                    {
                        hr++;
                        break;
                    }
                    else
                    {
                        break;
                    }

                }
            }
        }
    }
    addsub(A);
    //////////////////cseb/////////////////
    int B[5][7];
    char lab[2][10]={"CSL","DTL"};
    int labid[2]={5,8};
    int labmaxhr[2]={3,3};
    nullallot(B);
    lunchallot(B);
    
    int s=0;
    for(k=0;k<2;k++)    //allotment of lab classes by comparision with A section
    {
        tid=labid[k];
        tmhr=labmaxhr[k];
        int hr=0;
        int flag=0;
        for(i=s;i<5;i++){
            while(hr!=tmhr){
                if((A[i][0]!=tid)&&(A[i][1]!=tid)&&(A[i][2]!=tid)){
                    B[i][0]=tid;
                    B[i][1]=tid;
                    B[i][2]=tid;
                    flag=1;
                    hr=3;
                    
                    break;
                }
                else if((A[i][4]!=tid)&&(A[i][5]!=tid)&&(A[i][6]!=tid)){
                    B[i][4]=tid;
                    B[i][5]=tid;
                    B[i][6]=tid;
                    flag=1; 
                    hr=3;

                    break;
                }
                else{
                    break;
                }
            }
            if(flag==1){
                s++;
                break;
            }
            else{
                continue;
            }
        }
    }
    diffac(B);  //function for allocating subjects with different staff
    
    for(k=0;k<2;k++)    //loop for allocating subjects with same staff
    {       
        tid=samestaff_subid[k];
        tmhr=samestaff_maxhr[k];
        int hr=0;
        for(i=0;i<5;i++){   //i denotes the day
            while(hr!=tmhr){
                int flag = 0;
                for(int nor=0;nor<50;nor++)
                {
                    rn = rand() % 7;
                    //printf("%d\n", randomnumber);
                    if((B[i][rn]==0)&&(A[i][rn]!=tid)){
                        B[i][rn]=tid;
                        //printf("ttb[%d][%d]=%d\n",i,randomnumber,tempsubid);
                        flag = 1 ;
                        //printf("Yes\n");
                        break;
                    }
                    else{
                        //printf("No\n");
                        continue;
                    }
                }
                if(flag == 1)
                {
                    hr++;
                    break;
                }
                else
                {
                    break;
                }

            }
        }
    }
    addsub(B);
    
    if(toupper(class)=='A')
    {
        printf("---------------------TIMETABLE OF CSE A---------------------\n");
        numtt(A);
        printf("\n");
        maintt(A);
        printf("\n");
        stafftt(A);
    }
     else if(toupper(class)=='B')
    {   
        printf("---------------------TIMETABLE OF CSE B---------------------\n");
        numtt(B);
        printf("\n");
        maintt(B);
        printf("\n");
        stafftt(B);
    }
    
}