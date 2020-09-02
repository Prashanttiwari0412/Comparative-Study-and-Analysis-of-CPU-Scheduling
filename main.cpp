
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 40
void sort(int m, int x[ ]);
int Shopping();


 main()
{   int x,i,j,n,pos,total,con;
    char ch;
    int temp[max],pr[max],p[max],bust[max],wait[max],turnt[max],arrt[max];
    float awt=0,atat=0;
    int value=1;
 	char str[100];
 	value= Shopping();
	printf("\n\n\n\n");
	
    printf("Enter the number of process");
    scanf("%d",&n);
    
    printf("Enter the burst time:");
    for(i=0;i<n;i++)
    {

        scanf("%d",&bust[i]);
    }
    
    
    printf("Enter the arrival time:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arrt[i]);
    }
    
    do{
    printf("1.FCFS\n");
    printf("2.priority\n");
    printf("3.SJF\n");
    printf("enter the choices");
    scanf("%d",&x);
    switch (x) 
   { 
       case 1: printf("FCFS\n"); 

  
  
    temp[0]=0;
    printf("process\t burst time\t arrival time\t waiting time\t turn around time\n");
    for(i=0;i<n;i++)
    {


        wait[i]=0;
        turnt[i]=0;
        temp[i+1]=temp[i]+bust[i];
        wait[i]=temp[i]-arrt[i];
        turnt[i]=wait[i]+bust[i];
        awt=awt+wait[i];
        atat=atat+turnt[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bust[i],arrt[i],wait[i],turnt[i]);
    }

    awt=awt/n;
    atat=atat/n;
    printf("average waiting time=%f\n",awt);
    printf("average turn around time=%f",atat);

               break; 





       case 2: printf("priority\n"); 
        printf("Enter the Priority for each process:");
        for(i=0;i<n;i++) 
       { scanf("%d",&pr[i]);}
        p[i]=i+1;           
       
    
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp[i]=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp[i];
 
        temp[i]=bust[i];
        bust[i]=bust[pos];
        bust[pos]=temp[i];
 
        temp[i]=p[i];
        p[i]=p[pos];
        p[pos]=temp[i];
    }
 
    wait[0]=0;
 
    
    for(i=1;i<n;i++)
    {
        wait[i]=0;
        for(j=0;j<i;j++)
            wait[i]+=bust[j];
 
        total+=wait[i];
    }
 
    awt=total/n;     
    total=0;
 
    printf("\nProcess\t\t    Burst Time   \t \tWaiting Time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turnt[i]=bust[i]+wait[i];     
        total+=turnt[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t%d",p[i],bust[i],wait[i],turnt[i]);
    }
 
    atat=total/n;     
    printf("\n\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f\n",atat);
         break;
 

      case 3:
      printf("SJf\n");
      printf("enter position\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        p[i]=i+1;         
    }
      for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bust[j]<bust[pos])
                pos=j;
        }
  
        temp[i]=bust[i];
        bust[i]=bust[pos];
        bust[pos]=temp[i];
  
        temp[i]=p[i];
        p[i]=p[pos];
        p[pos]=temp[i];
    }
   
    wait[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        wait[i]=0;
        for(j=0;j<i;j++)
            wait[i]+=bust[j];
  
        total+=wait[i];
    }
  
    awt=(float)total/n;      
    total=0;
  
    printf("\nProcess\t\t    Burst Time   \t \tWaiting Time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turnt[i]=bust[i]+wait[i];   
        total+=turnt[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t%d",p[i],bust[i],wait[i],turnt[i]);
    }
  
    atat=(float)total/n;    
    printf("\n\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f\n",atat);
     break;
     

       default: printf("Choice other than 1 or 2 is invalid\n"); 
                break;   
   } 
   printf ("Do you want to continue: y/n\n");
    scanf (" %c", &ch);
    }while(ch == 'y');
    }
    
   int Shopping()
   {char str[100];
   int con;
 printf("Please Enter Your Name\n");
 scanf("%s",str);
  int totalCost=0;
 int i,j,choice,c=1,a[9],cost[9];
 int priority[9];
 int distance[9]={5,8,2,3,7,9,1,4,6};
 for(i=0;i<9;i++)
 a[i]=0;
 
 char items[9][100]={
 "Milk Bottle",
 "Butter\t",
 "Cheese\t",
 "Apple\t",
 "Banana\t",
 "Mango\t",//change
 "Mango Fruity",
 "Beer\t",
 "Cold Drink"  
 };
 
 printf("Hello %s, Welcome to our Online Shopping.\n",str);
 do{
  //C is 1 by default
  if(c==1){
  printf("Enter\n1 - Dairy Products\n2 - Fruits\n3 - Soft Drinks\n4 - Final Bill\nAny other number to exit\n"); //start asking
  scanf("%d",&choice);
  switch(choice)
  {
  	
  	case 4:
   {
   	 printf("%s's cart\n",str);
			  printf("\tId\tItems\t\tQuantity\t\t\tCost\t\t\tpriority\tDistance\n");
			  for(i=0;i<9;i++)
			  {
			   if(a[i]!=0)
			   {
			    printf("|\t%d\t%s\t\t\t%d\t\t\t%d\t\t\t%d\t%d|\n",i,items[i],a[i],(cost[i]*a[i]),priority[i],distance[i]);
			    
			   }
			  }
			  break;
   }

   case 1:
   {
    int accessoriesChoice;
    printf("Enter\n1 - Milk Bottle - Rs.100\n2 - Butter- Rs.50\n3 - Cheese - Rs.75\nAny other number to exit\n");//change
    scanf("%d",&accessoriesChoice);
    cost[0]=100;//change
    priority[0]=1;
    cost[1]=50;//change
    priority[1]=1;
    cost[2]=75;//change
    priority[2]=1;
    switch(accessoriesChoice)
    {
     case 1:
     {
      int num;
      printf("You choose Milk Bottle with Rs.100.Are you sure to buy.If 'Yes' Enter 1 else any number\n"); //change
      scanf("%d",&num);
      if(num==1)
      {
       a[0]++;
       totalCost+=100;
      }
      
      break;
     }
     case 2:
     {
      int num;
      printf("You choose Butter with Rs.50.Are you sure to buy.If 'Yes' Enter 1 else any number\n");//change
      scanf("%d",&num);
      if(num==1)
      {
       a[1]++;
       totalCost+=50;
      }
     
      break;
     }
     case 3:
     {
      int num;
      printf("You choose Cheese with Rs.75.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
       a[2]++;
       totalCost+=75;
      }
      
      break;
     }
     default:{
      printf("Exit from Dairy Products\n");
      break;
     }
    }
    break;
    }
   /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
   case 2:
   {
    int shoesChoice;
    printf("Enter\n1 - Apple - Rs.250\n2 - Banana - Rs.80\n3 - Mango - Rs.120\nAny other number to exit\n"); //change
    scanf("%d",&shoesChoice);
    cost[3]=250; //change
    priority[3]=2;
    cost[4]=80; //change
    priority[4]=2;
    cost[5]=120; //change
    priority[5]=2;
    switch(shoesChoice)
    {
     case 1:
     {
      int num;
      printf("You choose Apple for Rs.250.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
       a[3]++;
       totalCost+=250;
      }
      
      break;
     }
     case 2:
     {
      int num;
      printf("You chose Banana for Rs.80.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
       a[4]++;
       totalCost+=80;
      }
      
      break;
     }
     case 3:
     {
      int num;
      printf("You chose Mango for Rs.120.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
       a[5]++;
       totalCost+=120;
      }
      
      break;
     }
     default:{
      printf("Exit from Fruits Category\n");
      break;
     }
    }
    break;
   }
   /* //////////////////////////////////////////////////////////////////////// */
   case 3:
   {
    int mobileChoice;
    printf("Enter\n1 - Mango Fruity - Rs.60\n2 - Beer - Rs.250\n3 - Cold Drink - Rs.80\nAny other number to exit\n");
    scanf("%d",&mobileChoice);
    cost[6]=60;
    priority[6]=3;
    cost[7]=250;
    priority[7]=3;
    cost[8]=80;
    priority[8]=3;
    if(mobileChoice==0){
    	break;
	}
    switch(mobileChoice)
    {
     case 1:
     {
      int num;
      printf("You choose to buy Mango Fruity for Rs.60.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
       a[6]++;
       totalCost+=60;
      }
      
      break;
     }
     case 2:
     {
      int num;
      printf("You choose to buy Beer for Rs.250.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
       a[7]++;
       totalCost+=250;
      }
     
      break;
     }
     case 3:
     {
      int num;
      printf("You choose to buy Cold Drink for Rs.80.Are you sure to buy.If 'Yes' Enter 1 else any number\n");
      scanf("%d",&num);
      if(num==1)
      {
       a[8]++;
       totalCost+=80;
      }
      
      break;
     }
     default:{
      printf("Exit from Soft Drinks Category\n");
      break;
     }
    }
    break;
   }
   	
   default:
   {
    printf("Enter Valid Categories Choice\n");
    break;
   }
  }
  
  printf("\nSome More Options Enter\n1 to Add Item\n2 to Delete Items\n3 to Change Quantity\n4 to final Bill \nAny other number to EXIT\n0 to exit\n");
  scanf("%d",&c);
 }
  if(c==2)
  {
   int id;
   printf("Enter id to delete item\n");
   scanf("%d",&id);
   if(id<9&&id>0){
   totalCost=totalCost-(cost[id]*a[id]);
   a[id]=0;
   }
   else{
    printf("Enter Valid id\n");
   }
       printf("Revised Items \n");
       printf("Id\t\tItems\t\tQuantity\t\tCost\n");
            for(i=0;i<9;i++)
      {
     if(a[i]!=0)
      {
    printf("!\t%d\t%s\t\t\t%d\t\t\t%d\t\t\t\t%d!\n",i,items[i],a[i],(cost[i]*a[i]),priority[i]);
      }
     }
        printf("Total Cost\t\t\t\t\t\t\t%d\n",totalCost);
        printf("Some More Options Enter\n1 to Add Item\n2 to Delete Items\n3 to Change Quantity\n4 to final Bill \nAny other number to EXIT\n0 to exit\n");
     scanf("%d",&c);
  }
  if(c==3)
  {
   int id,quantity;
   printf("Enter id to Change quantity of an item\n");
   scanf("%d",&id);
   printf("Enter quantity to be changed of an item\n");
   scanf("%d",&quantity);
   if(id<9&&id>=0){
    if(quantity>0 && a[id]>0){  
        if(quantity<a[id]) 
     {
      int dec=a[id]-quantity;
      a[id]=quantity;
       totalCost=totalCost-(cost[id]*dec); 
     }
     if(quantity>a[id]) 
     {
      int inc=quantity-a[id];
      a[id]=quantity;
       totalCost=totalCost+(cost[id]*inc); 
     }
     if(quantity==a[id]) 
     {
      a[id]=quantity;
       totalCost=totalCost+0; 
     }   
           
    }
    else{
       printf("Item has no Quantity.Please Try again\n");
    }
     }
     else{
    printf("Enter Valid id\n");
   }
       printf("Revised Items \n");
       printf("Id\tItems\t\tQuantity\tCost\n");
            for(i=0;i<9;i++)
      {
     if(a[i]!=0)
      {
    printf("\t%d\t%s\t\t\t%d\t\t\t%d\t\t\t\t%d\n",i,items[i],a[i],(cost[i]*a[i]),priority[i]);
      }
     }
       
        printf("Some More Options Enter\n1 to Add Item\n2 to Delete Items\n3 to Change Quantity\n4 to final Bill \nAny other number to EXIT\n0 to exit\n");
     scanf("%d",&c);
  }
  
  
  if(c==4){
  printf("%s's cart\n",str);
  printf("\tId\tItems\t\tQuantity\t\t\tCost\t\t\tpriority\tDistance\n");
  for(i=0;i<9;i++)
  {
   if(a[i]!=0)
   {
    printf("|\t%d\t%s\t\t\t%d\t\t\t%d\t\t\t%d\t%d|\n",i,items[i],a[i],(cost[i]*a[i]),priority[i],distance[i]);
   }
  }
  break;
}
  
 }while(c==1 || c==2 ||c==3 ||c==4);
 printf("Your Final Cost is %d\n",totalCost);
 printf("Thanks %s for Choosing Us and Visit us again.\n",str);
   
 	printf ("Do you want to add another costumer: 1\n");
    scanf (" %d",&con);
    if(con == 1)
   {    
       Shopping();
       printf("\n\n\n");
       return c;
   }
  else
  {
       return c; 
  } 
       
   } 
     void sort(int m, int x[ ])
   {                                                           
       int i, j, t;                                            
                                                               
       for(i = 1; i <= m-1; i++)                               
          for(j = 1; j <= m-i; j++)                             
             if(x[j-1] >= x[j])                                
             {
                t = x[j-1];                                    
                x[j-1] = x[j];                                 
                x[j] = t;                                      
             }  
             
}
